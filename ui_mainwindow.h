/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu May 10 01:34:18 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *decodeButton;
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *browseButton;
    QPushButton *enhanceButton;
    QLabel *picLabel;
    QComboBox *systemBox;
    QLabel *label_2;
    QLabel *resultLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(502, 404);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        decodeButton = new QPushButton(centralWidget);
        decodeButton->setObjectName(QString::fromUtf8("decodeButton"));
        decodeButton->setGeometry(QRect(80, 310, 97, 27));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(54, 5, 331, 27));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 31, 17));
        browseButton = new QPushButton(centralWidget);
        browseButton->setObjectName(QString::fromUtf8("browseButton"));
        browseButton->setGeometry(QRect(390, 5, 97, 27));
        enhanceButton = new QPushButton(centralWidget);
        enhanceButton->setObjectName(QString::fromUtf8("enhanceButton"));
        enhanceButton->setGeometry(QRect(270, 310, 97, 27));
        enhanceButton->setCheckable(false);
        enhanceButton->setAutoDefault(false);
        enhanceButton->setFlat(false);
        picLabel = new QLabel(centralWidget);
        picLabel->setObjectName(QString::fromUtf8("picLabel"));
        picLabel->setGeometry(QRect(40, 110, 161, 151));
        systemBox = new QComboBox(centralWidget);
        systemBox->setObjectName(QString::fromUtf8("systemBox"));
        systemBox->setGeometry(QRect(130, 45, 361, 31));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 50, 111, 21));
        resultLabel = new QLabel(centralWidget);
        resultLabel->setObjectName(QString::fromUtf8("resultLabel"));
        resultLabel->setGeometry(QRect(310, 110, 161, 151));
        resultLabel->setWordWrap(true);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 502, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        decodeButton->setText(QApplication::translate("MainWindow", "Decode", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        browseButton->setText(QApplication::translate("MainWindow", "Browse", 0, QApplication::UnicodeUTF8));
        enhanceButton->setText(QApplication::translate("MainWindow", "Enhance", 0, QApplication::UnicodeUTF8));
        picLabel->setText(QString());
        systemBox->clear();
        systemBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Code 39", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Fibonacci", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("MainWindow", "Number System", 0, QApplication::UnicodeUTF8));
        resultLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
