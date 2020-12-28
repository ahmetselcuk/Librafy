#pragma once
#include <Qstring>
#include <QVector>
#include <QtCore/QVariant>
#include "LbyReading.h"
#include "LbyTag.h"

class LbyFile : public QObject
{
	Q_OBJECT

public:
	explicit LbyFile::LbyFile(QObject *parent = nullptr);
	virtual LbyFile::~LbyFile();
	QVector<QString> authors_;
	QString title_;
	QString pubYear_;
	QString note;
	QString fileTypes;

	enum LbyExt {
		CHM,
		DJVU,
		DOC,
		DOCX,
		EPUB,
		PDF,
		PS
	};
	Q_ENUM(LbyExt)
	
protected:
	LbyReading lbyReading;
	LbyTag lbyTag;
	void stringFileTypes();
};

