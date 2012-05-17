#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <Magick++.h>
#include <iostream>
#include <string>
#include <QtGui>
#include "decoder.h"
#include "greedyAlgorithm.h"
#include "histogramResult.h"
#include "numbersystemwidget.h"
#include "multiBase.h"

using namespace std;
using namespace Magick;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    layout = new QVBoxLayout;
    layout->setSpacing(0);
    QWidget* viewport = new QWidget;
    viewport->setLayout(layout);
    ui->scrollArea->setWidget(viewport);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// =================== Decoder Main and UI ============================
static string Decode(string path, int index){
    // Construct the image object. Separating image construction from the
    // the read operation ensures that a failure to read the image file
    // doesn't render the image object useless.
    Image image;
    try {
        // Read a file into image object
        image.read(path);
    }
    catch( Exception &error_ )
    {
        cout << "Caught exception: " << error_.what() << endl;
        return NULL;
    }
    Decoder gui = Decoder();
    if(index == 0){
        return gui.ReadCode39(&image);
    }
    return gui.ReadFibonacci(&image);
}

void MainWindow::on_decodeButton_released()
{
    string path = ui->lineEdit->text().toStdString();
    string result = Decode(path, ui->systemBox->currentIndex());
    ui->resultLabel->setText( QString::fromStdString(result));
}

void MainWindow::on_browseButton_released()
{
    QString path;

    path = QFileDialog::getOpenFileName(
                this,
                "Choose a file to open",
                QString::null,
                QString::null);

    ui->lineEdit->setText( path );

    QPixmap image(path);
    ui->picLabel->setPixmap(image);
    ui->picLabel->setScaledContents(true);
}

// =================== Encoder Main and UI ============================

void MainWindow::on_saveBrowseButton_released()
{
    QString path;

    path = QFileDialog::getOpenFileName(
                this,
                "Choose a file to open",
                QString::null,
                QString::null);

    ui->saveLocationBox->setText( path );

    //  QPixmap image(path);
    //ui->picLabel->setPixmap(image);
    //ui->picLabel->setScaledContents(true);s
}

void MainWindow::convertInput(GreedyAlgorithm* g){
    string input, converted, output;
    int mode = ui->modeSelection->currentIndex();
    input = ui->inputTextBox->text().toStdString();
    converted = g->convertInput(input, mode);
    ui->encodedOutputBox->setText(QString::fromStdString(converted));

    if(converted == g->errorString){
        output = converted;
    }
}

void MainWindow::generateBinary(GreedyAlgorithm* g){
    //Collect all number Systems and add to systems
    string input = ui->encodedOutputBox->toPlainText().toStdString();
    vector<NumberSystem> systems;
    numberSystemWidget* w;
    for(int i = 0; i < layout->count(); i++){
        w = dynamic_cast<numberSystemWidget*>(layout->itemAt(i)->widget());
        NumberSystem newSystem = w->getNumberSystem();
        if(w->isGood()){
            systems.push_back(newSystem);
        }else{
            ui->encodedBinaryBox->setText("Invalid Number System");
            return;
        }
    }

    //Combine number systems and generate binary
    NumberSystem finalSystem = MultiBase(ui->operatorSelection->currentIndex(), &systems);
    g->setNumberSystem(&finalSystem);
    string binary = g->runGreedy(ui->encodedOutputBox->toPlainText().toStdString(), 3);
    ui->encodedBinaryBox->setText(QString::fromStdString(binary));
}

void MainWindow::generateBarcode(){
    string binary = ui->encodedBinaryBox->toPlainText().toStdString();

}

void MainWindow::on_encodeButton_released()
{
    GreedyAlgorithm g;
    convertInput(&g);
    generateBinary(&g);
    generateBarcode();
}


void MainWindow::on_addSysButton_released()
{
    numberSystemWidget* newSys = new numberSystemWidget();
    layout->addWidget(newSys);

}

