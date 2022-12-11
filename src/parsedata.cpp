#include "parsedata.h"

ParseData::ParseData(QObject *parent) : QObject(parent)
{

}

ParseData::ParseData(QJsonObject data)
{
    this->data = data;
}

QList<QJsonValue> ParseData::parse_data()
{
    QJsonValue arr = data["list"];
    QList<QJsonValue> list_data;
    for (int i = 0; i < 3; i++){
        list_data.append(arr[i]);
    };
    return list_data;
}
