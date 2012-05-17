/********************************************************************************
** Form generated from reading UI file 'numbersystemwidget.ui'
**
** Created: Thu May 17 03:47:42 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NUMBERSYSTEMWIDGET_H
#define UI_NUMBERSYSTEMWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_numberSystemWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QComboBox *typeBox;
    QComboBox *operatorBox;
    QLabel *pLabel;
    QLineEdit *pValue;
    QLabel *startLabel;
    QLineEdit *startBox;
    QLabel *endLabel;
    QLineEdit *endBox;
    QPushButton *removeButton;

    void setupUi(QWidget *numberSystemWidget)
    {
        if (numberSystemWidget->objectName().isEmpty())
            numberSystemWidget->setObjectName(QString::fromUtf8("numberSystemWidget"));
        numberSystemWidget->resize(516, 50);
        horizontalLayout = new QHBoxLayout(numberSystemWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        typeBox = new QComboBox(numberSystemWidget);
        typeBox->setObjectName(QString::fromUtf8("typeBox"));

        horizontalLayout->addWidget(typeBox);

        operatorBox = new QComboBox(numberSystemWidget);
        operatorBox->setObjectName(QString::fromUtf8("operatorBox"));

        horizontalLayout->addWidget(operatorBox);

        pLabel = new QLabel(numberSystemWidget);
        pLabel->setObjectName(QString::fromUtf8("pLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pLabel->sizePolicy().hasHeightForWidth());
        pLabel->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pLabel);

        pValue = new QLineEdit(numberSystemWidget);
        pValue->setObjectName(QString::fromUtf8("pValue"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pValue->sizePolicy().hasHeightForWidth());
        pValue->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(pValue);

        startLabel = new QLabel(numberSystemWidget);
        startLabel->setObjectName(QString::fromUtf8("startLabel"));
        sizePolicy.setHeightForWidth(startLabel->sizePolicy().hasHeightForWidth());
        startLabel->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(startLabel);

        startBox = new QLineEdit(numberSystemWidget);
        startBox->setObjectName(QString::fromUtf8("startBox"));
        sizePolicy1.setHeightForWidth(startBox->sizePolicy().hasHeightForWidth());
        startBox->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(startBox);

        endLabel = new QLabel(numberSystemWidget);
        endLabel->setObjectName(QString::fromUtf8("endLabel"));
        sizePolicy.setHeightForWidth(endLabel->sizePolicy().hasHeightForWidth());
        endLabel->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(endLabel);

        endBox = new QLineEdit(numberSystemWidget);
        endBox->setObjectName(QString::fromUtf8("endBox"));
        sizePolicy1.setHeightForWidth(endBox->sizePolicy().hasHeightForWidth());
        endBox->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(endBox);

        removeButton = new QPushButton(numberSystemWidget);
        removeButton->setObjectName(QString::fromUtf8("removeButton"));

        horizontalLayout->addWidget(removeButton);


        retranslateUi(numberSystemWidget);

        QMetaObject::connectSlotsByName(numberSystemWidget);
    } // setupUi

    void retranslateUi(QWidget *numberSystemWidget)
    {
        numberSystemWidget->setWindowTitle(QApplication::translate("numberSystemWidget", "Form", 0, QApplication::UnicodeUTF8));
        typeBox->clear();
        typeBox->insertItems(0, QStringList()
         << QApplication::translate("numberSystemWidget", "Fibonacci", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("numberSystemWidget", "Power", 0, QApplication::UnicodeUTF8)
        );
        operatorBox->clear();
        operatorBox->insertItems(0, QStringList()
         << QApplication::translate("numberSystemWidget", "+", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("numberSystemWidget", "*", 0, QApplication::UnicodeUTF8)
        );
        pLabel->setText(QApplication::translate("numberSystemWidget", "p:", 0, QApplication::UnicodeUTF8));
        startLabel->setText(QApplication::translate("numberSystemWidget", "start:", 0, QApplication::UnicodeUTF8));
        endLabel->setText(QApplication::translate("numberSystemWidget", "end:", 0, QApplication::UnicodeUTF8));
        removeButton->setText(QApplication::translate("numberSystemWidget", "Remove", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class numberSystemWidget: public Ui_numberSystemWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NUMBERSYSTEMWIDGET_H
