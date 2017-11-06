#include "oper.h"
#include <QString>
#include <QMutableStringListIterator>
Oper::Oper(QString id, QString name, int level)
{
    _id = id;
    _name = name;
    _level = level;
}

QString Oper::getId() const
{
	return _id;
}

QString Oper::getName() const
{
    return _name;
}

int Oper::getLevel() const
{
    return _level;
}

QString Oper::Oper::getShortName() const
{
	// John Doe -> J.Doe
	QStringList strList = _name.split(QRegExp("\\W+"), QString::SkipEmptyParts);
	QString result = QString("");
	QList<QString>::iterator i;
	for (i = strList.begin(); i + 1 != strList.end(); ++i)
	{
		result = result.append((*i).left(1).toUpper()).append(".");
	}
	result = result.append(strList.last());
	return result;
}
