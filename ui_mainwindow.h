/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Jun 11 00:19:23 2012
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
    QTabWidget *Analytics_2;
    QWidget *Encoder;
    QLabel *encodedBarcode;
    QLabel *encodedBarcodeLabel;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_6;
    QLabel *encodedBinaryLabel;
    QTextEdit *encodedBinaryBox;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_13;
    QComboBox *typeSelection;
    QLabel *label_3;
    QComboBox *modeSelection;
    QLabel *label_4;
    QSlider *securityValue;
    QPushButton *encodeButton;
    QFrame *line;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QLineEdit *encoderPin;
    QFrame *line_2;
    QLabel *label_6;
    QLineEdit *inputTextBox;
    QLabel *encodeErrorLabel;
    QWidget *Decoder;
    QLabel *picLabel;
    QPushButton *decodeButton;
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
    QLineEdit *decoderPin;
    QLabel *label_9;
    QPushButton *decodeEnhancedButton;
    QLineEdit *resultLabel;
    QWidget *Advanced_Options;
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
    QLabel *systemErrorLabel;
    QWidget *Analytics;
    QLabel *barcode_code39;
    QLabel *label_15;
    QLabel *barcode_fusion;
    QLabel *label_fusion;
    QLabel *label_code39_length;
    QLabel *label_fusion_length;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *Analytics_Input;
    QComboBox *Analytics_modeSelection;
    QPushButton *Analytics_EncodeButton;
    QLabel *Analytics_encodeErrorLabel;
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
        Analytics_2 = new QTabWidget(centralWidget);
        Analytics_2->setObjectName(QString::fromUtf8("Analytics_2"));
        Analytics_2->setGeometry(QRect(0, 0, 661, 621));
        Encoder = new QWidget();
        Encoder->setObjectName(QString::fromUtf8("Encoder"));
        encodedBarcode = new QLabel(Encoder);
        encodedBarcode->setObjectName(QString::fromUtf8("encodedBarcode"));
        encodedBarcode->setGeometry(QRect(20, 270, 611, 90));
        encodedBarcode->setMaximumSize(QSize(16777215, 90));
        encodedBarcode->setFrameShape(QFrame::WinPanel);
        encodedBarcode->setFrameShadow(QFrame::Sunken);
        encodedBarcode->setScaledContents(false);
        encodedBarcodeLabel = new QLabel(Encoder);
        encodedBarcodeLabel->setObjectName(QString::fromUtf8("encodedBarcodeLabel"));
        encodedBarcodeLabel->setGeometry(QRect(20, 240, 67, 21));
        horizontalLayoutWidget = new QWidget(Encoder);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 470, 611, 80));
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

        horizontalLayoutWidget_2 = new QWidget(Encoder);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(6, 10, 636, 80));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(horizontalLayoutWidget_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_3->addWidget(label_13);

        typeSelection = new QComboBox(horizontalLayoutWidget_2);
        typeSelection->setObjectName(QString::fromUtf8("typeSelection"));

        horizontalLayout_3->addWidget(typeSelection);

        label_3 = new QLabel(horizontalLayoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        modeSelection = new QComboBox(horizontalLayoutWidget_2);
        modeSelection->setObjectName(QString::fromUtf8("modeSelection"));

        horizontalLayout_3->addWidget(modeSelection);

        label_4 = new QLabel(horizontalLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        securityValue = new QSlider(horizontalLayoutWidget_2);
        securityValue->setObjectName(QString::fromUtf8("securityValue"));
        securityValue->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(securityValue);

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

        encoderPin = new QLineEdit(horizontalLayoutWidget_3);
        encoderPin->setObjectName(QString::fromUtf8("encoderPin"));

        horizontalLayout_7->addWidget(encoderPin);

        line_2 = new QFrame(Encoder);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(20, 420, 611, 16));
        line_2->setFrameShadow(QFrame::Sunken);
        line_2->setLineWidth(2);
        line_2->setFrameShape(QFrame::HLine);
        label_6 = new QLabel(Encoder);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 440, 161, 17));
        inputTextBox = new QLineEdit(Encoder);
        inputTextBox->setObjectName(QString::fromUtf8("inputTextBox"));
        inputTextBox->setGeometry(QRect(20, 100, 611, 111));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(inputTextBox->sizePolicy().hasHeightForWidth());
        inputTextBox->setSizePolicy(sizePolicy);
        inputTextBox->setFrame(true);
        encodeErrorLabel = new QLabel(Encoder);
        encodeErrorLabel->setObjectName(QString::fromUtf8("encodeErrorLabel"));
        encodeErrorLabel->setEnabled(true);
        encodeErrorLabel->setGeometry(QRect(260, 560, 131, 17));
        encodeErrorLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        Analytics_2->addTab(Encoder, QString());
        Decoder = new QWidget();
        Decoder->setObjectName(QString::fromUtf8("Decoder"));
        picLabel = new QLabel(Decoder);
        picLabel->setObjectName(QString::fromUtf8("picLabel"));
        picLabel->setGeometry(QRect(20, 130, 261, 221));
        picLabel->setFrameShape(QFrame::WinPanel);
        picLabel->setFrameShadow(QFrame::Sunken);
        picLabel->setScaledContents(false);
        decodeButton = new QPushButton(Decoder);
        decodeButton->setObjectName(QString::fromUtf8("decodeButton"));
        decodeButton->setGeometry(QRect(60, 510, 131, 27));
        enhanceButton = new QPushButton(Decoder);
        enhanceButton->setObjectName(QString::fromUtf8("enhanceButton"));
        enhanceButton->setGeometry(QRect(260, 510, 131, 27));
        enhanceButton->setCheckable(false);
        enhanceButton->setAutoDefault(false);
        enhanceButton->setFlat(false);
        enhanceLabel = new QLabel(Decoder);
        enhanceLabel->setObjectName(QString::fromUtf8("enhanceLabel"));
        enhanceLabel->setGeometry(QRect(340, 130, 261, 221));
        enhanceLabel->setScaledContents(false);
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

        decoderPin = new QLineEdit(horizontalLayoutWidget_5);
        decoderPin->setObjectName(QString::fromUtf8("decoderPin"));

        horizontalLayout_9->addWidget(decoderPin);

        label_9 = new QLabel(Decoder);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(20, 380, 101, 17));
        decodeEnhancedButton = new QPushButton(Decoder);
        decodeEnhancedButton->setObjectName(QString::fromUtf8("decodeEnhancedButton"));
        decodeEnhancedButton->setGeometry(QRect(460, 510, 131, 27));
        resultLabel = new QLineEdit(Decoder);
        resultLabel->setObjectName(QString::fromUtf8("resultLabel"));
        resultLabel->setGeometry(QRect(20, 410, 601, 61));
        resultLabel->setDragEnabled(false);
        resultLabel->setReadOnly(false);
        Analytics_2->addTab(Decoder, QString());
        Advanced_Options = new QWidget();
        Advanced_Options->setObjectName(QString::fromUtf8("Advanced_Options"));
        layoutWidget_2 = new QWidget(Advanced_Options);
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

        scrollArea = new QScrollArea(Advanced_Options);
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
        layoutWidget_3 = new QWidget(Advanced_Options);
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

        useAdvancedBox = new QCheckBox(Advanced_Options);
        useAdvancedBox->setObjectName(QString::fromUtf8("useAdvancedBox"));
        useAdvancedBox->setGeometry(QRect(200, 380, 191, 22));
        useAdvancedBox->setCheckable(true);
        useAdvancedBox->setChecked(false);
        label_10 = new QLabel(Advanced_Options);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 20, 131, 17));
        label_11 = new QLabel(Advanced_Options);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(20, 260, 171, 17));
        systemErrorLabel = new QLabel(Advanced_Options);
        systemErrorLabel->setObjectName(QString::fromUtf8("systemErrorLabel"));
        systemErrorLabel->setEnabled(true);
        systemErrorLabel->setGeometry(QRect(240, 420, 121, 17));
        systemErrorLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        Analytics_2->addTab(Advanced_Options, QString());
        Analytics = new QWidget();
        Analytics->setObjectName(QString::fromUtf8("Analytics"));
        barcode_code39 = new QLabel(Analytics);
        barcode_code39->setObjectName(QString::fromUtf8("barcode_code39"));
        barcode_code39->setGeometry(QRect(15, 130, 271, 211));
        barcode_code39->setFrameShape(QFrame::WinPanel);
        barcode_code39->setFrameShadow(QFrame::Sunken);
        barcode_code39->setScaledContents(true);
        label_15 = new QLabel(Analytics);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(15, 100, 91, 31));
        QFont font1;
        font1.setPointSize(16);
        label_15->setFont(font1);
        barcode_fusion = new QLabel(Analytics);
        barcode_fusion->setObjectName(QString::fromUtf8("barcode_fusion"));
        barcode_fusion->setGeometry(QRect(365, 130, 271, 211));
        barcode_fusion->setFrameShape(QFrame::WinPanel);
        barcode_fusion->setFrameShadow(QFrame::Sunken);
        barcode_fusion->setScaledContents(true);
        label_fusion = new QLabel(Analytics);
        label_fusion->setObjectName(QString::fromUtf8("label_fusion"));
        label_fusion->setGeometry(QRect(365, 100, 151, 31));
        label_fusion->setFont(font1);
        label_code39_length = new QLabel(Analytics);
        label_code39_length->setObjectName(QString::fromUtf8("label_code39_length"));
        label_code39_length->setGeometry(QRect(15, 380, 261, 31));
        label_fusion_length = new QLabel(Analytics);
        label_fusion_length->setObjectName(QString::fromUtf8("label_fusion_length"));
        label_fusion_length->setGeometry(QRect(365, 380, 261, 31));
        layoutWidget = new QWidget(Analytics);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(15, 40, 611, 29));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        Analytics_Input = new QLineEdit(layoutWidget);
        Analytics_Input->setObjectName(QString::fromUtf8("Analytics_Input"));

        horizontalLayout_4->addWidget(Analytics_Input);

        Analytics_modeSelection = new QComboBox(layoutWidget);
        Analytics_modeSelection->setObjectName(QString::fromUtf8("Analytics_modeSelection"));

        horizontalLayout_4->addWidget(Analytics_modeSelection);

        Analytics_EncodeButton = new QPushButton(layoutWidget);
        Analytics_EncodeButton->setObjectName(QString::fromUtf8("Analytics_EncodeButton"));

        horizontalLayout_4->addWidget(Analytics_EncodeButton);

        Analytics_encodeErrorLabel = new QLabel(Analytics);
        Analytics_encodeErrorLabel->setObjectName(QString::fromUtf8("Analytics_encodeErrorLabel"));
        Analytics_encodeErrorLabel->setEnabled(true);
        Analytics_encodeErrorLabel->setGeometry(QRect(260, 560, 131, 17));
        Analytics_encodeErrorLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        Analytics_2->addTab(Analytics, QString());
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

        Analytics_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        encodedBarcode->setText(QString());
        encodedBarcodeLabel->setText(QApplication::translate("MainWindow", "Barcode", 0, QApplication::UnicodeUTF8));
        encodedBinaryLabel->setText(QApplication::translate("MainWindow", "Binary", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "Type", 0, QApplication::UnicodeUTF8));
        typeSelection->clear();
        typeSelection->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1D", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "2D", 0, QApplication::UnicodeUTF8)
        );
        label_3->setText(QApplication::translate("MainWindow", " Data", 0, QApplication::UnicodeUTF8));
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
        encodeErrorLabel->setText(QApplication::translate("MainWindow", "CANNOT ENCODE", 0, QApplication::UnicodeUTF8));
        Analytics_2->setTabText(Analytics_2->indexOf(Encoder), QApplication::translate("MainWindow", "Encoder", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_ACCESSIBILITY
        picLabel->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        picLabel->setText(QString());
        decodeButton->setText(QApplication::translate("MainWindow", "Decode Original", 0, QApplication::UnicodeUTF8));
        enhanceButton->setText(QApplication::translate("MainWindow", "Enhance", 0, QApplication::UnicodeUTF8));
        enhanceLabel->setText(QString());
        label->setText(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QApplication::translate("MainWindow", "/home/jose/Desktop/Final Barcode cs194/barcodeDecoder2/encoded.gif", 0, QApplication::UnicodeUTF8));
        browseButton->setText(QApplication::translate("MainWindow", "Browse", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", " Type", 0, QApplication::UnicodeUTF8));
        systemBox->clear();
        systemBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Fuse 1D", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Fuse 2D", 0, QApplication::UnicodeUTF8)
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
        Analytics_2->setTabText(Analytics_2->indexOf(Decoder), QApplication::translate("MainWindow", "Decoder", 0, QApplication::UnicodeUTF8));
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
        systemErrorLabel->setText(QApplication::translate("MainWindow", "INVALID SYSTEM", 0, QApplication::UnicodeUTF8));
        Analytics_2->setTabText(Analytics_2->indexOf(Advanced_Options), QApplication::translate("MainWindow", "Advanced Options", 0, QApplication::UnicodeUTF8));
        barcode_code39->setText(QString());
        label_15->setText(QApplication::translate("MainWindow", "Code 39", 0, QApplication::UnicodeUTF8));
        barcode_fusion->setText(QString());
        label_fusion->setText(QApplication::translate("MainWindow", "Fusion Code", 0, QApplication::UnicodeUTF8));
        label_code39_length->setText(QApplication::translate("MainWindow", "Length:", 0, QApplication::UnicodeUTF8));
        label_fusion_length->setText(QApplication::translate("MainWindow", "Length:", 0, QApplication::UnicodeUTF8));
        Analytics_modeSelection->clear();
        Analytics_modeSelection->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Numeric", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Alpha", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "AlphaNumeric", 0, QApplication::UnicodeUTF8)
        );
        Analytics_EncodeButton->setText(QApplication::translate("MainWindow", "Encode", 0, QApplication::UnicodeUTF8));
        Analytics_encodeErrorLabel->setText(QApplication::translate("MainWindow", "CANNOT ENCODE", 0, QApplication::UnicodeUTF8));
        Analytics_2->setTabText(Analytics_2->indexOf(Analytics), QApplication::translate("MainWindow", "Analytics", 0, QApplication::UnicodeUTF8));
        menuFusion_Codes->setTitle(QApplication::translate("MainWindow", "Fusion Codes", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
