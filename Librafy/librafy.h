#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_librafy.h"

class Librafy : public QMainWindow
{
    Q_OBJECT

public:
    Librafy(QWidget *parent = Q_NULLPTR);

private:
    Ui::LibrafyClass ui;
};
