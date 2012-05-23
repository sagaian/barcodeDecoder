#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <Magick++.h>
#include <iostream>
#include <string>
#include <QtGui>
#include "decoder.h"
#include "histogramResult.h"
#include "numbersystemwidget.h"
#include "multiBase.h"
#include "enhancer.h"
#include "encoder.h"
#include "goldenRatioSystem.h"
#include "fibonacciSystem.h"
#include <assert.h>

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
}

/*void MainWindow::convertInput(GreedyAlgorithm* g){
    string input, converted, output;
    int mode = ui->modeSelection->currentIndex();
    input = ui->inputTextBox->text().toStdString();
    converted = g->convertInput(input, mode);
    ui->encodedOutputBox->setText(QString::fromStdString(converted));

    if(converted == g->errorString){
        output = converted;
    }
}*/

// default system is classical fibonacci
void MainWindow::getDefaultSystem(NumberSystem *sys, int upperLimit){
    Fibonacci f(1, upperLimit, 0);
    f.sanitizeSequence();
    *sys = f;
    //delete f.getSequence();
}

void MainWindow::getNumberSystem(NumberSystem *sys, int upperLimit){
    if(layout->count() == 0 || !ui->useAdvancedBox->isChecked()){
        //If default or no systems provided, use classical fibonacci
        getDefaultSystem(sys, upperLimit);
        return;
    }
    //Collect all number Systems and add to systems
    // string input = ui->encodedOutputBox->toPlainText().toStdString();
    vector<NumberSystem> systems;
    numberSystemWidget* w;
    for(int i = 0; i < layout->count(); i++){
        w = dynamic_cast<numberSystemWidget*>(layout->itemAt(i)->widget());
        NumberSystem newSystem = w->getNumberSystem(upperLimit);
        systems.push_back(newSystem);
    }
    //Combine number systems and generate binary
    *sys = MultiBase(ui->operatorSelection->currentIndex(), &systems);
    sys->sanitizeSequence();

    // delete unnecessary system values
    for(size_t i = 0; i < systems.size(); i++){
        NumberSystem s = systems.at(i);
        delete s.getSequence();
    }
}

void MainWindow::generateBinary(float value, NumberSystem *sys, vector<int>*binary){
    sys->getGreedyRepresentation(value, binary);
    ui->encodedOutputBox->setText(QString::fromStdString(sys->getGreedyAsSum(binary)));
}

void MainWindow::generateBarcode(vector<int> *binary){
    Encoder e;
    e.EncodeBinary(binary, ui->saveLocationBox->text().toStdString());
    QPixmap encodedImage("encoded.gif");
    ui->encodedBarcode->setPixmap(encodedImage);
    ui->encodedBinaryBox->setText(QString::fromStdString(e.VectorToString(binary)));
}

void MainWindow::on_addSysButton_released()
{
    numberSystemWidget* newSys = new numberSystemWidget();
    layout->addWidget(newSys);
}

void MainWindow::on_encodeButton_released()
{
    if(ui->inputTextBox->text().isEmpty()) return;
    NumberSystem sys;
    delete sys.getSequence();
    float num = ::atof(ui->inputTextBox->text().toStdString().c_str());
    getNumberSystem(&sys, 1000);
    vector<int> binary;
    generateBinary(num, &sys, &binary);
    delete sys.getSequence();
    generateBarcode(&binary);

}


// =================== Decoder Main and UI ============================
string MainWindow::decode(string path){
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
        return "";
    }

    // determine type of barcode to decode and get number system if needed
    int index = ui->systemBox->currentIndex();
    NumberSystem sys;
    delete sys.getSequence();
    if(index == 0) getNumberSystem(&sys, 1000); //change later to chunk size

    // decode output string
    Decoder gui = Decoder();
    if(index == 1){
        return gui.ReadCode39(&image);
    }
    return gui.ReadFusion(&image, &sys);
}

void MainWindow::on_decodeButton_released()
{
    if(ui->lineEdit->text().isEmpty()) return;
    string output = decode(ui->lineEdit->text().toStdString());
    ui->resultLabel->setText(QString::fromStdString(output));
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
}

// =================== Enhancer Main and UI ============================

bool MainWindow::enhance(string path){
    // Construct the image object. Seperating image construction from the
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
        return false;
    }
    float ratio = (float) (1+sqrt(5))/2;
    GoldenRatio f(256, ratio);
    f.sanitizeSequence();
    Enhancer e;
    e.EnhanceImage(image, &f);
    delete f.getSequence();
    return true;
}

void MainWindow::on_enhanceButton_released()
{
    if(ui->lineEdit->text().isEmpty()) return;
    string path = ui->lineEdit->text().toStdString();
    if(path != ""){
        bool enhanced = enhance(path);
        if(enhanced){
            QPixmap enhancedImage("enhanced.gif");
            ui->enhanceLabel->setPixmap(enhancedImage);
            //ui->enhanceLabel->setScaledContents(true);
        }
    }
}

void MainWindow::on_decodeEnhancedButton_released()
{
    string output = decode("enhanced.gif");
    ui->resultLabel->setText(QString::fromStdString(output));
}
