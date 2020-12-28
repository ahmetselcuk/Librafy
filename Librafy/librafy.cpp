#include "librafy.h"
#include "stdafx.h"
#include "LbyFile.h"
#include <QFileSystemModel>
#include <QDir>
#include <QString>
#include <QFileInfo>
#include <QModelIndex>

Librafy::Librafy(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	QString startPath = "D:\\";
	dirModel = new QFileSystemModel(this);
	dirModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
	dirModel->setRootPath(startPath);
	ui.treeView->setModel(dirModel);

	ui.treeView->setRootIndex(dirModel->index(startPath, 0));
	ui.treeView->hideColumn(1);
	ui.treeView->hideColumn(2);
	ui.treeView->hideColumn(3);


	fileModel = new QFileSystemModel(this);
	fileModel->setFilter(QDir::NoDotAndDotDot | QDir::Files);
	fileModel->setRootPath(startPath);
	ui.listView->setModel(fileModel);

	ui.listView->setRootIndex(fileModel->index(startPath, 0));
	

	QObject::connect(ui.treeView, SIGNAL(clicked(QModelIndex)), this, SLOT(updateListView(QModelIndex)));

}

void Librafy::updateListView(QModelIndex index)
{
	QString sPath = dirModel->fileInfo(index).absoluteFilePath();
	ui.listView->setRootIndex(fileModel->setRootPath(sPath));

}
