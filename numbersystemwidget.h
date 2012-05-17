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
    bool isGood();
    NumberSystem getNumberSystem();
    explicit numberSystemWidget(QWidget *parent = 0);
    ~numberSystemWidget();

private slots:
    void on_removeButton_released();

    void on_pValue_cursorPositionChanged(int arg1, int arg2);

private:
    bool status;
    Ui::numberSystemWidget *ui;
};

#endif // NUMBERSYSTEMWIDGET_H
