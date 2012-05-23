#ifndef NUMBERSYSTEMWIDGET_H
#define NUMBERSYSTEMWIDGET_H

#include <QWidget>
#include "numberSystem.h"

namespace Ui {
    class numberSystemWidget;
}

class numberSystemWidget : public QWidget
{
    Q_OBJECT

public:
    NumberSystem getNumberSystem(int maxValue);
    explicit numberSystemWidget(QWidget *parent = 0);
    ~numberSystemWidget();

private slots:
    void on_removeButton_released();
    void on_typeBox_currentIndexChanged(int index);

private:
    Ui::numberSystemWidget *ui;
};

#endif // NUMBERSYSTEMWIDGET_H
