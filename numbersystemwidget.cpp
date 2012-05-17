#include "numbersystemwidget.h"
#include "ui_numbersystemwidget.h"
#include "numberSystem.h"
#include "fibonacciSystem.h"

numberSystemWidget::numberSystemWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::numberSystemWidget)
{
    ui->setupUi(this);
    status = false;
}

numberSystemWidget::~numberSystemWidget()
{
    delete ui;
}

NumberSystem numberSystemWidget::getNumberSystem(){
    if(ui->pValue->text().isEmpty() || ui->startBox->text().isEmpty() || ui->endBox->text().isEmpty()){
        status = false;
        return Fibonacci(0,0,0,0);;
    }else{
        status = true;
    }
    int type = ui->typeBox->currentIndex();
    int op = ui->operatorBox->currentIndex();
    int p = ui->pValue->text().toInt();
    int start = ui->startBox->text().toInt();
    int end = ui->endBox->text().toInt();
    switch(type){
    default:
        return Fibonacci(p,start,end,op);
    }
}

bool numberSystemWidget::isGood(){
    return status;
}

void numberSystemWidget::on_removeButton_released()
{
    delete(this);
}
