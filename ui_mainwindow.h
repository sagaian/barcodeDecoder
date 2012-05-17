/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu May 17 03:47:42 2012
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
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *Encoder;
    QLabel *encodedBinaryLabel;
    QLabel *encodedBarcode;
    QLabel *encodedBarcodeLabel;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *saveFileLabel;
    QLineEdit *saveLocationBox;
    QPushButton *saveBrowseButton;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *inputTextBox;
    QPushButton *encodeButton;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QComboBox *modeSelection;
    QComboBox *operatorSelection;
    QComboBox *chunkSelection;
    QPushButton *addSysButton;
    QTextEdit *encodedBinaryBox;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *outputLayout;
    QTextEdit *encodedOutputBox;
    QWidget *Decoder;
    QLabel *picLabel;
    QPushButton *decodeButton;
    QLabel *resultLabel;
    QPushButton *enhanceButton;
    QLabel *label_2;
    QComboBox *systemBox;
    QPushButton *browseButton;
    QLabel *label;
    QLineEdit *lineEdit;
    QMenuBar *menuBar;
    QMenu *menuFusion_Codes;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(653, 681);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 661, 621));
        Encoder = new QWidget();
        Encoder->setObjectName(QString::fromUtf8("Encoder"));
        encodedBinaryLabel = new QLabel(Encoder);
        encodedBinaryLabel->setObjectName(QString::fromUtf8("encodedBinaryLabel"));
        encodedBinaryLabel->setGeometry(QRect(470, 350, 51, 21));
        QFont font;
        font.setPointSize(11);
        encodedBinaryLabel->setFont(font);
        encodedBarcode = new QLabel(Encoder);
        encodedBarcode->setObjectName(QString::fromUtf8("encodedBarcode"));
        encodedBarcode->setGeometry(QRect(40, 370, 231, 211));
        encodedBarcodeLabel = new QLabel(Encoder);
        encodedBarcodeLabel->setObjectName(QString::fromUtf8("encodedBarcodeLabel"));
        encodedBarcodeLabel->setGeometry(QRect(130, 350, 67, 21));
        scrollArea = new QScrollArea(Encoder);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(30, 131, 591, 111));
        scrollArea->setFrameShape(QFrame::Panel);
        scrollArea->setFrameShadow(QFrame::Sunken);
        scrollArea->setLineWidth(1);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 576, 109));
        scrollArea->setWidget(scrollAreaWidgetContents);
        layoutWidget = new QWidget(Encoder);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 15, 591, 66));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        saveFileLabel = new QLabel(layoutWidget);
        saveFileLabel->setObjectName(QString::fromUtf8("saveFileLabel"));

        horizontalLayout_2->addWidget(saveFileLabel);

        saveLocationBox = new QLineEdit(layoutWidget);
        saveLocationBox->setObjectName(QString::fromUtf8("saveLocationBox"));

        horizontalLayout_2->addWidget(saveLocationBox);

        saveBrowseButton = new QPushButton(layoutWidget);
        saveBrowseButton->setObjectName(QString::fromUtf8("saveBrowseButton"));

        horizontalLayout_2->addWidget(saveBrowseButton);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        inputTextBox = new QLineEdit(layoutWidget);
        inputTextBox->setObjectName(QString::fromUtf8("inputTextBox"));

        horizontalLayout_3->addWidget(inputTextBox);

        encodeButton = new QPushButton(layoutWidget);
        encodeButton->setObjectName(QString::fromUtf8("encodeButton"));

        horizontalLayout_3->addWidget(encodeButton);


        verticalLayout->addLayout(horizontalLayout_3);

        layoutWidget1 = new QWidget(Encoder);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(30, 90, 479, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        modeSelection = new QComboBox(layoutWidget1);
        modeSelection->setObjectName(QString::fromUtf8("modeSelection"));

        horizontalLayout->addWidget(modeSelection);

        operatorSelection = new QComboBox(layoutWidget1);
        operatorSelection->setObjectName(QString::fromUtf8("operatorSelection"));

        horizontalLayout->addWidget(operatorSelection);

        chunkSelection = new QComboBox(layoutWidget1);
        chunkSelection->setObjectName(QString::fromUtf8("chunkSelection"));

        horizontalLayout->addWidget(chunkSelection);

        addSysButton = new QPushButton(layoutWidget1);
        addSysButton->setObjectName(QString::fromUtf8("addSysButton"));

        horizontalLayout->addWidget(addSysButton);

        encodedBinaryBox = new QTextEdit(Encoder);
        encodedBinaryBox->setObjectName(QString::fromUtf8("encodedBinaryBox"));
        encodedBinaryBox->setGeometry(QRect(380, 370, 231, 211));
        layoutWidget2 = new QWidget(Encoder);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(30, 260, 591, 80));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        outputLayout = new QLabel(layoutWidget2);
        outputLayout->setObjectName(QString::fromUtf8("outputLayout"));

        horizontalLayout_4->addWidget(outputLayout);

        encodedOutputBox = new QTextEdit(layoutWidget2);
        encodedOutputBox->setObjectName(QString::fromUtf8("encodedOutputBox"));

        horizontalLayout_4->addWidget(encodedOutputBox);

        tabWidget->addTab(Encoder, QString());
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        encodedBinaryLabel->raise();
        encodedBarcode->raise();
        encodedBarcodeLabel->raise();
        encodedBinaryBox->raise();
        scrollArea->raise();
        Decoder = new QWidget();
        Decoder->setObjectName(QString::fromUtf8("Decoder"));
        picLabel = new QLabel(Decoder);
        picLabel->setObjectName(QString::fromUtf8("picLabel"));
        picLabel->setGeometry(QRect(40, 190, 261, 221));
        decodeButton = new QPushButton(Decoder);
        decodeButton->setObjectName(QString::fromUtf8("decodeButton"));
        decodeButton->setGeometry(QRect(190, 470, 97, 27));
        resultLabel = new QLabel(Decoder);
        resultLabel->setObjectName(QString::fromUtf8("resultLabel"));
        resultLabel->setGeometry(QRect(320, 190, 281, 221));
        resultLabel->setWordWrap(true);
        enhanceButton = new QPushButton(Decoder);
        enhanceButton->setObjectName(QString::fromUtf8("enhanceButton"));
        enhanceButton->setGeometry(QRect(350, 470, 97, 27));
        enhanceButton->setCheckable(false);
        enhanceButton->setAutoDefault(false);
        enhanceButton->setFlat(false);
        label_2 = new QLabel(Decoder);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 80, 111, 21));
        systemBox = new QComboBox(Decoder);
        systemBox->setObjectName(QString::fromUtf8("systemBox"));
        systemBox->setGeometry(QRect(200, 70, 361, 31));
        browseButton = new QPushButton(Decoder);
        browseButton->setObjectName(QString::fromUtf8("browseButton"));
        browseButton->setGeometry(QRect(460, 20, 97, 27));
        label = new QLabel(Decoder);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 25, 31, 17));
        lineEdit = new QLineEdit(Decoder);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(124, 20, 331, 27));
        tabWidget->addTab(Decoder, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 653, 25));
        menuFusion_Codes = new QMenu(menuBar);
        menuFusion_Codes->setObjectName(QString::fromUtf8("menuFusion_Codes"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFusion_Codes->menuAction());

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        encodedBinaryLabel->setText(QApplication::translate("MainWindow", "Binary", 0, QApplication::UnicodeUTF8));
        encodedBarcode->setText(QString());
        encodedBarcodeLabel->setText(QApplication::translate("MainWindow", "Barcode", 0, QApplication::UnicodeUTF8));
        saveFileLabel->setText(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        saveBrowseButton->setText(QApplication::translate("MainWindow", "Browse", 0, QApplication::UnicodeUTF8));
        encodeButton->setText(QApplication::translate("MainWindow", "Encode", 0, QApplication::UnicodeUTF8));
        modeSelection->clear();
        modeSelection->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Numeric", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Alpha", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "AlphaNumeric", 0, QApplication::UnicodeUTF8)
        );
        operatorSelection->clear();
        operatorSelection->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "*", 0, QApplication::UnicodeUTF8)
        );
        chunkSelection->clear();
        chunkSelection->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "chunk", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8)
        );
        addSysButton->setText(QApplication::translate("MainWindow", "Add Number System", 0, QApplication::UnicodeUTF8));
        outputLayout->setText(QApplication::translate("MainWindow", "Output", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(Encoder), QApplication::translate("MainWindow", "Encoder", 0, QApplication::UnicodeUTF8));
        picLabel->setText(QString());
        decodeButton->setText(QApplication::translate("MainWindow", "Decode", 0, QApplication::UnicodeUTF8));
        resultLabel->setText(QString());
        enhanceButton->setText(QApplication::translate("MainWindow", "Enhance", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Number System", 0, QApplication::UnicodeUTF8));
        systemBox->clear();
        systemBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Code 39", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Fibonacci", 0, QApplication::UnicodeUTF8)
        );
        browseButton->setText(QApplication::translate("MainWindow", "Browse", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(Decoder), QApplication::translate("MainWindow", "Decoder", 0, QApplication::UnicodeUTF8));
        menuFusion_Codes->setTitle(QApplication::translate("MainWindow", "Fusion Codes", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
