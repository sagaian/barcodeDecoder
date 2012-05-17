#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include "greedyAlgorithm.h"

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

    void on_scrollArea_destroyed(QObject *arg1);

    void convertInput(GreedyAlgorithm* g);

    void generateBinary(GreedyAlgorithm* g);

    void generateBarcode();

private:
    QVBoxLayout* layout;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
