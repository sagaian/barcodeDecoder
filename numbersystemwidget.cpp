#include "numbersystemwidget.h"
#include "ui_numbersystemwidget.h"
#include "numberSystem.h"
#include "pqFibonacciSystem.h"
#include "lucasSystem.h"
#include "fibonacciSystem.h"
#include "goldenRatioSystem.h"
#include "powerSystem.h"
#include "multiBase.h"
#include "securer.h"
#include <iostream>
numberSystemWidget::numberSystemWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::numberSystemWidget)
{
    ui->setupUi(this);
    ui->pValue->setText(QString::fromStdString("1"));
    ui->qValue->setText(QString::fromStdString("0"));
    ui->operatorBox->hide();
}

numberSystemWidget::~numberSystemWidget()
{
    delete ui;
}

bool numberSystemWidget::isValidSystem(){
    int pValue = ui->pValue->text().toInt();
    int qValue = ui->qValue->text().toInt();
    if(pValue == 0 && ui->pValue->text().toStdString().compare("0") != 0) return false; //conversion to int failed
    if(qValue == 0 && ui->qValue->text().toStdString().compare("0") != 0) return false; //conversion to int failed
    if(pValue < 0 || qValue < 0 || pValue > 9 || qValue > 9) return false; //if values are negative, system is invalid
    return true;
}

NumberSystem numberSystemWidget::getNumberSystem(int maxValue){
    int p,q = 0;
    float ratio = 0;
    int type = ui->typeBox->currentIndex();
    int op = ui->operatorBox->currentIndex();
    vector<NumberSystem> powerSystems;
    switch(type){
    case 0:
        p = ui->pValue->text().toInt();
        q = ui->qValue->text().isEmpty() ? 0 : ui->qValue->text().toInt();
        return pqFibonacci(p,q,maxValue,op);
    case 1:
        p = ui->pValue->text().toInt();
        q = ui->qValue->text().isEmpty() ? 0 : ui->qValue->text().toInt();
        return Lucas(p,q,maxValue,op);
    case 2:
        powerSystems.push_back(Power(2,maxValue));
        powerSystems.push_back(Power(3,maxValue));
        return MultiBase(1,&powerSystems);
    case 3:
        ratio = ui->pValue->text().isEmpty() ? 1.618 : ui->pValue->text().toFloat();
        return GoldenRatio(maxValue, ratio);
    default:
        p = ui->pValue->text().toInt();
        q = ui->qValue->text().isEmpty() ? 0 : ui->qValue->text().toInt();
        return Fibonacci(p, maxValue, op);
    }
}

void numberSystemWidget::on_removeButton_released()
{
    delete(this);
}

void numberSystemWidget::on_typeBox_currentIndexChanged(int index)
{
    //set labels to
    switch(index){
    case 2:
        ui->pLabel->setText(QString::fromStdString("Base 1:"));
        ui->pValue->setText(QString::fromStdString("2"));
        ui->qLabel->setText(QString::fromStdString("Base 2:"));
        ui->qValue->setText(QString::fromStdString("3"));
        ui->pValue->setEnabled(false);
        ui->qValue->setEnabled(false);
        break;
    //Golden Ratio
    case 3:
        ui->pLabel->setText(QString::fromStdString("Ratio"));
        ui->pValue->setText(QString::fromStdString("1.618"));
        ui->operatorBox->setHidden(true);
        ui->qLabel->setHidden(true);
        ui->qValue->setHidden(true);
        break;
        //Fibonacci
    default:
        ui->pLabel->show();
        ui->qLabel->show();
        ui->pValue->show();
        ui->qValue->show();
        ui->pValue->setEnabled(true);
        ui->qValue->setEnabled(true);
        ui->pLabel->setText(QString::fromStdString("p:"));
        ui->pValue->setText(QString::fromStdString("1"));
        ui->qLabel->setText(QString::fromStdString("q:"));
        ui->qValue->setText(QString::fromStdString("0"));
    }

}
