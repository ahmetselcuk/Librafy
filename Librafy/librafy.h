#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_librafy.h"

class QFileSystemModel;
class QModelIndex;

class Librafy : public QMainWindow
{
    Q_OBJECT

public:
    Librafy(QWidget *parent = Q_NULLPTR);

public slots:
	void updateListView(QModelIndex index);

private:
    Ui::LibrafyClass ui;
	QFileSystemModel* dirModel;
	QFileSystemModel* fileModel; 
	
};
