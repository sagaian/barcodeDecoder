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
#include "securer.h"
#include <assert.h>
#include "chunker.h"
#include "compressor.h"
#include "alphaConverter.h"
#include "analyzer.h"
#include "pqFibonacciSystem.h"
#include "lucasSystem.h"
#include "powerSystem.h"
#include "code39.h"

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
    ui->encodeErrorLabel->hide();
    ui->Analytics_encodeErrorLabel->hide();
    ui->systemErrorLabel->hide();
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
    pqFibonacci f(1,0, upperLimit, 0);
    f.sanitizeSequence();
    *sys = f;
}

//pin must be multiple of PIN_CHUNK and made up of integer values
bool MainWindow::isValidPin(string pin){
    size_t pinLen = pin.size();
    if(pinLen % PIN_CHUNK != 0 || pinLen > (MAX_SYSTEMS_SECURE*PIN_CHUNK)) return false;
    for(size_t i = 0; i < pinLen; i++){
        if(!isdigit(pin.at(i))) return false;
        if(i % PIN_CHUNK == 0 && (pin.at(i)-'0') >= NUM_SYSTEMS) return false;
    }
    return true;
}

void MainWindow::getNumberSystem(NumberSystem *sys, int upperLimit, bool isEncoder){
    if(layout->count() == 0 || !ui->useAdvancedBox->isChecked()){
        //If default or no systems provided, use classical fibonacci
        //getDefaultSystem(sys, upperLimit);
        Securer s;
        if(isEncoder){
            if(ui->securityValue->value() == 0){
                s.generateUnsecuredSystem(sys);
            } else if(ui->securityValue->value() <75){
                s.generateLowSecuritySystem(sys);
            } else {
                s.generateHighSecuritySystem(sys);
            }
            ui->encoderPin->setText(QString::fromStdString(s.getPin()));
            ui->decoderPin->setText(QString::fromStdString(s.getPin()));
        } else {
            string pin = ui->decoderPin->text().toStdString();   
            if(!(isValidPin(pin))) {
                ui->resultLabel->setText(QString::fromStdString(ERROR_STRING2));
            } else {
                s.decodePin(pin, sys);

            }
        }
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
}

void MainWindow::generateBarcode(vector<int> *binary, string filename){
    Encoder e;
    //e.EncodeBinary(binary, ui->saveLocationBox->text().toStdString(),e.OneDimensional);
    if(ui->typeSelection->currentIndex() == 0){
        e.EncodeBinary(binary, filename ,e.OneDimensional, true);
    } else {
        e.EncodeBinary(binary, filename ,e.TwoDimensional, true);
    }
    QPixmap encodedImage(QString::fromStdString(filename));
    ui->encodedBarcode->setPixmap(encodedImage);
    ui->encodedBinaryBox->setText(QString::fromStdString(e.VectorToString(binary)));
}

void MainWindow::on_addSysButton_released()
{
    if(layout->count() < MAX_SYSTEMS){
        numberSystemWidget* newSys = new numberSystemWidget();
        layout->addWidget(newSys);
    }
}


// =================== Decoder Main and UI ============================
string MainWindow::decode(string path){
    ui->resultLabel->clear();
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
        return ERROR_STRING2;
    }

    // determine type of barcode to decode and get number system if needed
    int index = ui->systemBox->currentIndex();
    int max = pow(10, CHUNK_SIZE) - 1;
    NumberSystem sys;
    if(index !=  2) getNumberSystem(&sys, max, false);
    if(!ui->resultLabel->text().toStdString().compare((ERROR_STRING2))) return ERROR_STRING2;
    // decode output string
    Decoder gui = Decoder();
    string output = "";
    if(index == 0){
        output = gui.ReadFusion(&image, &sys, gui.OneDimensional);
    } else if (index == 1){
        output = gui.ReadFusion(&image, &sys, gui.TwoDimensional);
    } else {
        output = gui.ReadCode39(&image);
    }
    return output;
}

// for debugging
string MainWindow::Decode2(){
    Image image;
    try {
        // Read a file into image object
        image.read("encoded.gif");
    }
    catch( Exception &error_ )
    {
        cout << "Caught exception: " << error_.what() << endl;
        return "";
    }
    // determine type of barcode to decode and get number system if needed
    int index = ui->systemBox->currentIndex();
    NumberSystem sys;
    if(index == 0) getNumberSystem(&sys, Chunker::maxSeqValue, false); //change later to chunk size

    // decode output string
    Decoder gui;
    string result = gui.ReadFusion(&image, &sys, gui.OneDimensional);
    ui->resultLabel->setText( QString::fromStdString(result));
    return result;
}


void MainWindow::on_decodeButton_released()
{
    int mode = ui->modeSelection_Decoder->currentIndex();
    if(ui->lineEdit->text().isEmpty()){
        ui->resultLabel->setText(QString::fromStdString(ERROR_STRING2));
        return;
    }
    string output = decode(ui->lineEdit->text().toStdString());
    ui->resultLabel->setText(QString::fromStdString(AlphaConverter::decodeAlpha(output,mode)));

}

// refresh decoded image when decode tab is selected
void MainWindow::on_Analytics_2_currentChanged(int index)
{
    if(index == 1){
        QPixmap image(ui->lineEdit->text());
        ui->picLabel->setPixmap(image);
        ui->enhanceLabel->clear();
        ui->systemBox->setCurrentIndex(ui->typeSelection->currentIndex());
        ui->modeSelection_Decoder->setCurrentIndex(ui->modeSelection->currentIndex());
    }
    if(ui->useAdvancedBox->isChecked()){
        //make sure number systems are valid
        ui->systemErrorLabel->hide();
        numberSystemWidget* w;
        for(int i = 0; i < layout->count(); i++){
            w = dynamic_cast<numberSystemWidget*>(layout->itemAt(i)->widget());
            if(!w->isValidSystem()){
                ui->systemErrorLabel->show();
                ui->useAdvancedBox->setChecked(false);
                ui->Analytics_2->setCurrentIndex(2);
            }
        }

    }
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
        ui->resultLabel->setText(QString::fromStdString(ERROR_STRING3));
        return false;
    }
    float ratio = (float) (1+sqrt(5))/2;
    GoldenRatio f(256, ratio);
    f.sanitizeSequence();
    Enhancer e;
    e.EnhanceImage(image, &f);
    return true;
}

void MainWindow::on_enhanceButton_released()
{
    ui->resultLabel->clear();
    ui->enhanceLabel->clear();
    if(ui->lineEdit->text().isEmpty()){
        if(ui->lineEdit->text().isEmpty()){
            ui->resultLabel->setText(QString::fromStdString(ERROR_STRING3));
            return;
        }
    }
    string path = ui->lineEdit->text().toStdString();
    bool enhanced = enhance(path);
    if(enhanced){
        QPixmap enhancedImage("enhanced.gif");
        ui->enhanceLabel->setPixmap(enhancedImage);
        //ui->enhanceLabel->setScaledContents(true);
    } else {
        ui->resultLabel->setText(QString::fromStdString(ERROR_STRING3));
    }

}

void MainWindow::on_decodeEnhancedButton_released()
{
    int mode = ui->modeSelection_Decoder->currentIndex();
    string output = decode("enhanced.gif");
    ui->resultLabel->setText(QString::fromStdString(AlphaConverter::decodeAlpha(output,mode)));
}

void MainWindow::resetEncoderSettings(){
    ui->encodeErrorLabel->hide();
    ui->encoderPin->clear();
    ui->encodedBinaryBox->clear();
    ui->encodedBarcode->clear();
}

void MainWindow::on_encodeButton_released()
{
    resetEncoderSettings();
    if(ui->inputTextBox->text().isEmpty()) {
        ui->encodeErrorLabel->show();
        return;
    }

    int mode = ui->modeSelection->currentIndex();
    string input = ui->inputTextBox->text().toStdString();
    input = AlphaConverter::encodeAlpha(input,mode);
    if(input == ERROR_STRING1){
        //we have an error.
        ui->encodeErrorLabel->show();
    } else {
        NumberSystem sys;
        Chunker c;
        getNumberSystem(&sys, c.maxSeqValue, true);
        vector<int> binary = c.GetBitRepresentation(input, &sys);
        vector<int> compressedBinary = Compressor::CompressBitSequence(&binary, &sys);
        generateBarcode(&compressedBinary, FUSION_FILE);
    }

     /*Number systems checking
    NumberSystem sys;
        getNumberSystem(&sys, 1000, true);
        vector<float>* seq = sys.getSequence();
        string printOut = sys.getDescription();
        printOut += " ";
        printOut.append(AlphaConverter::sequenceToString(seq));
        ui->encodedBinaryBox->setText(QString::fromStdString(printOut));

*/

    //    ui->encodedBinaryBox->setText(QString::fromStdString(sys.getGreedyAsSum(&binary)));
    //ui->encodedBinaryBox->setText(QString::fromStdString(Analyzer::getTestResuls()));



    /* for debugging
    for(int i = 1000000000; i < 2000000000; i+=12345678){
   //     for(int i = 1; i < 100; i++){
        cout << i << "\n";
        getNumberSystem(&sys, MAX_CHUNK, true);
        Chunker c;
        stringstream istring;
        istring << i;
        vector<int> binary = c.GetBitRepresentation(istring.str(), &sys);
        Compressor comp;
        vector<int> compressedBinary = comp.CompressBitSequence(binary, &sys);
        //generateBinary(i,&sys, &binary);
        generateBarcode(&compressedBinary);
        string result = Decode2();
        ui->resultLabel->setText( QString::fromStdString(result));
        //assert(round(atof(result.c_str())) == i);
    }*/
}

void MainWindow::generateCode39Barcode(vector<int> *binary, string filename){
    Encoder e;
    e.EncodeBinary(binary, filename ,e.OneDimensional, false);
    QPixmap encodedImage(QString::fromStdString(filename));
    ui->encodedBarcode->setPixmap(encodedImage);
    ui->encodedBinaryBox->setText(QString::fromStdString(e.VectorToString(binary)));
}

void MainWindow::on_Analytics_EncodeButton_released(){
    //ensure that error message is hidden.
    ui->Analytics_encodeErrorLabel->hide();

    //use input to generate code39 bit sequence
    string input = ui->Analytics_Input->text().toStdString();
    vector<int> code39bits = Code39::encodeBarcode(input);

    //convert input for Fusion encoding
    int mode = ui->Analytics_modeSelection->currentIndex();
    input = AlphaConverter::encodeAlpha(input,mode);

    //generate fusion bit sequence
    NumberSystem sys;
    Chunker c;
    getNumberSystem(&sys, c.maxSeqValue, true);
    vector<int> binary = c.GetBitRepresentation(input, &sys);
    vector<int> compressedBinary = Compressor::CompressBitSequence(&binary, &sys);

    //if bit sequences are empty show an error.
    /* TODO:
     * For proper error handling, we would want the encoding process to tell us there is an error
     * with the fusion encoding by returning an empty bit sequence. This tells us something bad happened.
     * Then there would be no need to check for the error string here. Instead we would check at the time
     * of the encoding and ERROR_STRING1 = binary.empty() = compressedBinary.empty().
     */
    if(input == ERROR_STRING1 || code39bits.empty() || compressedBinary.empty()){
        //we have an error.
        ui->Analytics_encodeErrorLabel->show();
        return;
    }

    //generate both the code39 and fusion barcodes.
    generateBarcode(&compressedBinary, FUSION_FILE_ANALYTICS);
    generateCode39Barcode(&code39bits, CODE39_FILE_ANALYTICS);

    //tack together the paths where the images are
    string path_code39 = BROWSE_FOLDER;
    string path_fusion = BROWSE_FOLDER;
    path_code39.append(CODE39_FILE_ANALYTICS);
    path_fusion.append(FUSION_FILE_ANALYTICS);

    //Display both barcodes
    QPixmap image_code39(QString::fromStdString(path_code39));
    ui->barcode_code39->setPixmap(image_code39);
    QPixmap image_fusion(QString::fromStdString(path_fusion));
    ui->barcode_fusion->setPixmap(image_fusion);

    //state the lengths in bits of each barcode.
    string length_code39 = "Length: ";
    string length_fusion = "Length: ";
    length_code39.append(AlphaConverter::integerToString(code39bits.size()));
    length_fusion.append(AlphaConverter::integerToString(compressedBinary.size()));
    ui->label_code39_length->setText(QString::fromStdString(length_code39));
    ui->label_fusion_length->setText(QString::fromStdString(length_fusion));

}
