#include "numbersystemwidget.h"
#include "ui_numbersystemwidget.h"
#include "numberSystem.h"
#include "fibonacciSystem.h"
#include "goldenRatioSystem.h"
#include "securer.h"
#include <iostream>
numberSystemWidget::numberSystemWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::numberSystemWidget)
{
    ui->setupUi(this);
    ui->pValue->setText(QString::fromStdString("1"));
    ui->qValue->setText(QString::fromStdString("0"));
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
    if(pValue < 0 || qValue < 0 || pValue > MAX_P || qValue > MAX_Q) return false; //if values are negative, system is invalid
    return true;
}

NumberSystem numberSystemWidget::getNumberSystem(int maxValue){
    int type = ui->typeBox->currentIndex();
    int op = ui->operatorBox->currentIndex();
    switch(type){
    case 2:{
        float ratio = ui->pValue->text().isEmpty() ? 1.618 : ui->pValue->text().toFloat();
        return GoldenRatio(maxValue, ratio);
    }
    default:
        int p = ui->pValue->text().toInt();
        int q = ui->qValue->text().isEmpty() ? 0 : ui->qValue->text().toInt();
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
    //Golden Ratio
    case 2:
        ui->pLabel->setText(QString::fromStdString("Ratio"));
        ui->pValue->setText(QString::fromStdString("1.618"));
        ui->operatorBox->setHidden(true);
        ui->qLabel->setHidden(true);
        ui->qValue->setHidden(true);
        break;
        //Fibonacci
    default:
        ui->pLabel->setText(QString::fromStdString("p"));
        ui->qLabel->setHidden(false);
        ui->pValue->setText(QString::fromStdString("1"));
        ui->qValue->setHidden(false);
        ui->qValue->setText(QString::fromStdString("0"));
        ui->operatorBox->setHidden(false);
    }

}
