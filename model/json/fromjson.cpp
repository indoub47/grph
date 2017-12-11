#include "fromjson.h"
#include <QString>
#include <QJsonDocument>
#include <QFile>

FromJson::FromJson(QString jsonFileName)
{
    _fileName = jsonFileName;
}

void FromJson::charge()
{
    QString val;
    QFile file;
    file.setFileName(_fileName);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();
    _job = QJsonDocument::fromJson(val.toUtf8()).object();
}
