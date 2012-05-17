#-------------------------------------------------
#
# Project created by QtCreator 2012-05-08T01:23:14
#
#-------------------------------------------------

QT       += core gui

TARGET = barcodeGui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    multiBase.cpp \
    numberSystem.cpp \
    novelBarcodeDecorder.cpp \
    fibonacciSystem.cpp \
    decoder.cpp \
    greedyAlgorithm.cpp \
    numbersystemwidget.cpp

HEADERS  += mainwindow.h \
    fibonacciSystem.h \
    numberSystem.h \
    multiBase.h \
    goldenRatioSystem.h \
    histogramResult.h \
    decoder.h \
    greedyAlgorithm.h \
    numbersystemwidget.h

FORMS    += mainwindow.ui \
    numbersystemwidget.ui

unix:!macx:!symbian: LIBS += -L$$PWD/../../../../usr/local/lib/ -lMagick++

INCLUDEPATH += $$PWD/../../../../usr/local/include/ImageMagick
DEPENDPATH += $$PWD/../../../../usr/local/include/ImageMagick

unix:!macx:!symbian: LIBS += -L$$PWD/../../../../usr/local/lib/ -lMagickCore

INCLUDEPATH += $$PWD/../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../usr/local/include

unix:!macx:!symbian: LIBS += -L$$PWD/../../../../usr/local/lib/ -lMagickWand

INCLUDEPATH += $$PWD/../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../usr/local/include

OTHER_FILES += \
    sample_barcode_2.gif \
    usefulCodeSipets.txt \
    sample_barcode_2.gif \
    sample_barcode.gif
