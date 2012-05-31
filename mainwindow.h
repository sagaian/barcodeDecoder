#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include <vector>
#include <numberSystem.h>
#include <string>
using namespace std;

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

private:
    QVBoxLayout* layout;
    Ui::MainWindow *ui;
    void getDefaultSystem(NumberSystem *sys, int upperLimit);
    void getNumberSystem(NumberSystem *sys, int upperLimit, bool isEncoder);
    // void convertInput(GreedyAlgorithm* g);
    void generateBinary(float value, NumberSystem *sys, vector<int>*binary);
    void generateBarcode(vector<int> *binary);
    string decode(string path);
    bool enhance(string path);
    string Decode2();
};

#endif // MAINWINDOW_H
