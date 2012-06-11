#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include <vector>
#include <numberSystem.h>
#include <string>
using namespace std;

#define FUSION_FILE "encoded.gif"
#define CODE39_FILE_ANALYTICS "code39.gif"
#define FUSION_FILE_ANALYTICS "fusion.gif"
#define BROWSE_FOLDER "/home/jose/Desktop/Final Barcode cs194/barcodeDecoder2/"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_decodeButton_released();
    void on_browseButton_released();
    void on_saveBrowseButton_released();
    void on_encodeButton_released();
    void on_addSysButton_released();
    void on_enhanceButton_released();
    void on_decodeEnhancedButton_released();
    void on_Analytics_2_currentChanged(int index);
    void on_Analytics_EncodeButton_released();

private:
    QVBoxLayout* layout;
    Ui::MainWindow *ui;
    void getDefaultSystem(NumberSystem *sys, int upperLimit);
    void getNumberSystem(NumberSystem *sys, int upperLimit, bool isEncoder);
    // void convertInput(GreedyAlgorithm* g);
    void generateBarcode(vector<int> *binary, string filename);
    bool isValidPin(string pin);
    string decode(string path);
    bool enhance(string path);
    string Decode2();
    void resetEncoderSettings();

    void generateCode39Barcode(vector<int> *binary, string filename);
};

#endif // MAINWINDOW_H
