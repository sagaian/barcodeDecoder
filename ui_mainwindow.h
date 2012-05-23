/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue May 22 02:44:21 2012
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
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *Encoder;
    QLabel *encodedBarcode;
    QLabel *encodedBarcodeLabel;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QLabel *outputLayout;
    QTextEdit *encodedOutputBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_6;
    QLabel *encodedBinaryLabel;
    QTextEdit *encodedBinaryBox;
    QLineEdit *inputTextBox;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *modeSelection;
    QLabel *label_4;
    QSlider *horizontalSlider;
    QPushButton *encodeButton;
    QFrame *line;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QLineEdit *lineEdit_2;
    QFrame *line_2;
    QLabel *label_6;
    QWidget *Decoder;
    QLabel *picLabel;
    QPushButton *decodeButton;
    QLabel *resultLabel;
    QPushButton *enhanceButton;
    QLabel *enhanceLabel;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *browseButton;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_2;
    QComboBox *systemBox;
    QLabel *label_7;
    QComboBox *modeSelection_Decoder;
    QLabel *label_8;
    QLineEdit *lineEdit_3;
    QLabel *label_9;
    QPushButton *decodeEnhancedButton;
    QWidget *tab;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_12;
    QComboBox *operatorSelection;
    QPushButton *addSysButton;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *saveFileLabel;
    QLineEdit *saveLocationBox;
    QPushButton *saveBrowseButton;
    QCheckBox *useAdvancedBox;
    QLabel *label_10;
    QLabel *label_11;
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
        encodedBarcode = new QLabel(Encoder);
        encodedBarcode->setObjectName(QString::fromUtf8("encodedBarcode"));
        encodedBarcode->setGeometry(QRect(20, 270, 611, 90));
        encodedBarcode->setMaximumSize(QSize(16777215, 90));
        encodedBarcode->setFrameShape(QFrame::StyledPanel);
        encodedBarcodeLabel = new QLabel(Encoder);
        encodedBarcodeLabel->setObjectName(QString::fromUtf8("encodedBarcodeLabel"));
        encodedBarcodeLabel->setGeometry(QRect(20, 240, 67, 21));
        layoutWidget = new QWidget(Encoder);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 520, 611, 31));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        outputLayout = new QLabel(layoutWidget);
        outputLayout->setObjectName(QString::fromUtf8("outputLayout"));

        horizontalLayout_4->addWidget(outputLayout);

        encodedOutputBox = new QTextEdit(layoutWidget);
        encodedOutputBox->setObjectName(QString::fromUtf8("encodedOutputBox"));

        horizontalLayout_4->addWidget(encodedOutputBox);

        horizontalLayoutWidget = new QWidget(Encoder);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 470, 611, 31));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        encodedBinaryLabel = new QLabel(horizontalLayoutWidget);
        encodedBinaryLabel->setObjectName(QString::fromUtf8("encodedBinaryLabel"));
        QFont font;
        font.setPointSize(11);
        encodedBinaryLabel->setFont(font);

        horizontalLayout_6->addWidget(encodedBinaryLabel);

        encodedBinaryBox = new QTextEdit(horizontalLayoutWidget);
        encodedBinaryBox->setObjectName(QString::fromUtf8("encodedBinaryBox"));

        horizontalLayout_6->addWidget(encodedBinaryBox);

        inputTextBox = new QLineEdit(Encoder);
        inputTextBox->setObjectName(QString::fromUtf8("inputTextBox"));
        inputTextBox->setGeometry(QRect(20, 100, 611, 111));
        horizontalLayoutWidget_2 = new QWidget(Encoder);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(20, 10, 611, 80));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        modeSelection = new QComboBox(horizontalLayoutWidget_2);
        modeSelection->setObjectName(QString::fromUtf8("modeSelection"));

        horizontalLayout_3->addWidget(modeSelection);

        label_4 = new QLabel(horizontalLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        horizontalSlider = new QSlider(horizontalLayoutWidget_2);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(horizontalSlider);

        encodeButton = new QPushButton(horizontalLayoutWidget_2);
        encodeButton->setObjectName(QString::fromUtf8("encodeButton"));

        horizontalLayout_3->addWidget(encodeButton);

        line = new QFrame(Encoder);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(20, 220, 611, 16));
        line->setLineWidth(2);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        horizontalLayoutWidget_3 = new QWidget(Encoder);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(20, 380, 611, 29));
        horizontalLayout_7 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(horizontalLayoutWidget_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_7->addWidget(label_5);

        lineEdit_2 = new QLineEdit(horizontalLayoutWidget_3);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_7->addWidget(lineEdit_2);

        line_2 = new QFrame(Encoder);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(20, 420, 611, 16));
        line_2->setFrameShadow(QFrame::Sunken);
        line_2->setLineWidth(2);
        line_2->setFrameShape(QFrame::HLine);
        label_6 = new QLabel(Encoder);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 440, 161, 17));
        tabWidget->addTab(Encoder, QString());
        layoutWidget->raise();
        encodedBarcode->raise();
        encodedBarcodeLabel->raise();
        horizontalLayoutWidget->raise();
        inputTextBox->raise();
        horizontalLayoutWidget_2->raise();
        line->raise();
        horizontalLayoutWidget_3->raise();
        line_2->raise();
        label_6->raise();
        Decoder = new QWidget();
        Decoder->setObjectName(QString::fromUtf8("Decoder"));
        picLabel = new QLabel(Decoder);
        picLabel->setObjectName(QString::fromUtf8("picLabel"));
        picLabel->setGeometry(QRect(20, 130, 261, 221));
        decodeButton = new QPushButton(Decoder);
        decodeButton->setObjectName(QString::fromUtf8("decodeButton"));
        decodeButton->setGeometry(QRect(60, 510, 131, 27));
        resultLabel = new QLabel(Decoder);
        resultLabel->setObjectName(QString::fromUtf8("resultLabel"));
        resultLabel->setGeometry(QRect(20, 410, 601, 51));
        resultLabel->setWordWrap(true);
        enhanceButton = new QPushButton(Decoder);
        enhanceButton->setObjectName(QString::fromUtf8("enhanceButton"));
        enhanceButton->setGeometry(QRect(260, 510, 131, 27));
        enhanceButton->setCheckable(false);
        enhanceButton->setAutoDefault(false);
        enhanceButton->setFlat(false);
        enhanceLabel = new QLabel(Decoder);
        enhanceLabel->setObjectName(QString::fromUtf8("enhanceLabel"));
        enhanceLabel->setGeometry(QRect(340, 130, 261, 221));
        horizontalLayoutWidget_4 = new QWidget(Decoder);
        horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(10, 20, 631, 31));
        horizontalLayout_8 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget_4);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_8->addWidget(label);

        lineEdit = new QLineEdit(horizontalLayoutWidget_4);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_8->addWidget(lineEdit);

        browseButton = new QPushButton(horizontalLayoutWidget_4);
        browseButton->setObjectName(QString::fromUtf8("browseButton"));

        horizontalLayout_8->addWidget(browseButton);

        horizontalLayoutWidget_5 = new QWidget(Decoder);
        horizontalLayoutWidget_5->setObjectName(QString::fromUtf8("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(10, 60, 631, 41));
        horizontalLayout_9 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget_5);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_9->addWidget(label_2);

        systemBox = new QComboBox(horizontalLayoutWidget_5);
        systemBox->setObjectName(QString::fromUtf8("systemBox"));

        horizontalLayout_9->addWidget(systemBox);

        label_7 = new QLabel(horizontalLayoutWidget_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_9->addWidget(label_7);

        modeSelection_Decoder = new QComboBox(horizontalLayoutWidget_5);
        modeSelection_Decoder->setObjectName(QString::fromUtf8("modeSelection_Decoder"));

        horizontalLayout_9->addWidget(modeSelection_Decoder);

        label_8 = new QLabel(horizontalLayoutWidget_5);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_9->addWidget(label_8);

        lineEdit_3 = new QLineEdit(horizontalLayoutWidget_5);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        horizontalLayout_9->addWidget(lineEdit_3);

        label_9 = new QLabel(Decoder);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(20, 380, 101, 17));
        decodeEnhancedButton = new QPushButton(Decoder);
        decodeEnhancedButton->setObjectName(QString::fromUtf8("decodeEnhancedButton"));
        decodeEnhancedButton->setGeometry(QRect(460, 510, 131, 27));
        tabWidget->addTab(Decoder, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        layoutWidget_2 = new QWidget(tab);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 50, 320, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(layoutWidget_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout->addWidget(label_12);

        operatorSelection = new QComboBox(layoutWidget_2);
        operatorSelection->setObjectName(QString::fromUtf8("operatorSelection"));

        horizontalLayout->addWidget(operatorSelection);

        addSysButton = new QPushButton(layoutWidget_2);
        addSysButton->setObjectName(QString::fromUtf8("addSysButton"));

        horizontalLayout->addWidget(addSysButton);

        scrollArea = new QScrollArea(tab);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(10, 90, 591, 141));
        scrollArea->setFrameShape(QFrame::Panel);
        scrollArea->setFrameShadow(QFrame::Sunken);
        scrollArea->setLineWidth(1);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 576, 139));
        scrollArea->setWidget(scrollAreaWidgetContents);
        layoutWidget_3 = new QWidget(tab);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(19, 290, 591, 29));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        saveFileLabel = new QLabel(layoutWidget_3);
        saveFileLabel->setObjectName(QString::fromUtf8("saveFileLabel"));

        horizontalLayout_2->addWidget(saveFileLabel);

        saveLocationBox = new QLineEdit(layoutWidget_3);
        saveLocationBox->setObjectName(QString::fromUtf8("saveLocationBox"));

        horizontalLayout_2->addWidget(saveLocationBox);

        saveBrowseButton = new QPushButton(layoutWidget_3);
        saveBrowseButton->setObjectName(QString::fromUtf8("saveBrowseButton"));

        horizontalLayout_2->addWidget(saveBrowseButton);

        useAdvancedBox = new QCheckBox(tab);
        useAdvancedBox->setObjectName(QString::fromUtf8("useAdvancedBox"));
        useAdvancedBox->setGeometry(QRect(200, 380, 191, 22));
        useAdvancedBox->setCheckable(true);
        useAdvancedBox->setChecked(false);
        label_10 = new QLabel(tab);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 20, 131, 17));
        label_11 = new QLabel(tab);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(20, 260, 171, 17));
        tabWidget->addTab(tab, QString());
        layoutWidget_2->raise();
        scrollArea->raise();
        layoutWidget_3->raise();
        useAdvancedBox->raise();
        label_10->raise();
        label_11->raise();
        saveLocationBox->raise();
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

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        encodedBarcode->setText(QString());
        encodedBarcodeLabel->setText(QApplication::translate("MainWindow", "Barcode", 0, QApplication::UnicodeUTF8));
        outputLayout->setText(QApplication::translate("MainWindow", "Terms", 0, QApplication::UnicodeUTF8));
        encodedBinaryLabel->setText(QApplication::translate("MainWindow", "Binary", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Input Data", 0, QApplication::UnicodeUTF8));
        modeSelection->clear();
        modeSelection->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Numeric", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Alpha", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "AlphaNumeric", 0, QApplication::UnicodeUTF8)
        );
        label_4->setText(QApplication::translate("MainWindow", "Security", 0, QApplication::UnicodeUTF8));
        encodeButton->setText(QApplication::translate("MainWindow", "Encode", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Security Pin", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Advanced Output Data", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(Encoder), QApplication::translate("MainWindow", "Encoder", 0, QApplication::UnicodeUTF8));
        picLabel->setText(QString());
        decodeButton->setText(QApplication::translate("MainWindow", "Decode Original", 0, QApplication::UnicodeUTF8));
        resultLabel->setText(QString());
        enhanceButton->setText(QApplication::translate("MainWindow", "Enhance", 0, QApplication::UnicodeUTF8));
        enhanceLabel->setText(QString());
        label->setText(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        browseButton->setText(QApplication::translate("MainWindow", "Browse", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", " Type", 0, QApplication::UnicodeUTF8));
        systemBox->clear();
        systemBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Fusion", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Code 39", 0, QApplication::UnicodeUTF8)
        );
        label_7->setText(QApplication::translate("MainWindow", "Input Data", 0, QApplication::UnicodeUTF8));
        modeSelection_Decoder->clear();
        modeSelection_Decoder->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Numeric", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Alpha", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "AlphaNumeric", 0, QApplication::UnicodeUTF8)
        );
        label_8->setText(QApplication::translate("MainWindow", "Security Pin", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "Output Data", 0, QApplication::UnicodeUTF8));
        decodeEnhancedButton->setText(QApplication::translate("MainWindow", "Decode Enhanced", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(Decoder), QApplication::translate("MainWindow", "Decoder", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "Fusion Operator", 0, QApplication::UnicodeUTF8));
        operatorSelection->clear();
        operatorSelection->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "*", 0, QApplication::UnicodeUTF8)
        );
        addSysButton->setText(QApplication::translate("MainWindow", "Add Number System", 0, QApplication::UnicodeUTF8));
        saveFileLabel->setText(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        saveBrowseButton->setText(QApplication::translate("MainWindow", "Browse", 0, QApplication::UnicodeUTF8));
        useAdvancedBox->setText(QApplication::translate("MainWindow", "Use Advanced Options", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "Customize Systems", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "Set Encoder Directory", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Advanced Options", 0, QApplication::UnicodeUTF8));
        menuFusion_Codes->setTitle(QApplication::translate("MainWindow", "Fusion Codes", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
