#include "LbyFile.h"
#include <QMetaEnum>
#include <QMetaObject>
#include <QDebug>

LbyFile::LbyFile(QObject *parent)
{
	stringFileTypes(); //TODO make tis constexpr
}

LbyFile::~LbyFile()
{
}

void LbyFile::stringFileTypes()
{
	const QMetaObject &mo = LbyFile::staticMetaObject;
	const int index = mo.indexOfEnumerator("LbyExt");
	const QMetaEnum metaEnum = mo.enumerator(index);
	for (size_t i = 0; i < metaEnum.keyCount(); i++)
	{
		fileTypes.append(metaEnum.key(i));
	}
}
