#include "parsedata.h"

ParseData::ParseData(QObject *parent) : QObject(parent)
{

}

ParseData::ParseData(QJsonObject data)
{
    this->data = data;
}

QList<QMap<QString, QString>> ParseData::parse_data()
{
    QJsonValue arr = data["list"];
    QList<QMap<QString, QString>> list_data;
    QMap<QString, QString> buffer;

    for (int i = 0; i < 3; i++){
        buffer["date"] = arr[i]["dt_txt"].toString();
        buffer["temp"] = QString::number(arr[i]["main"]["temp"].toDouble());
        buffer["icon"] = arr[i]["weather"][0]["icon"].toString();
        buffer["speed"] = QString::number(arr[i]["wind"]["speed"].toDouble());
        buffer["pressure"] = QString::number(arr[i]["main"]["pressure"].toInt());
        list_data.append(buffer);
        buffer.clear();
    };

    qDebug() << list_data;

    return list_data;
}
