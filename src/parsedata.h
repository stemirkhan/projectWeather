#ifndef PARSEDATA_H
#define PARSEDATA_H

#include <QObject>
#include <QJsonObject>
#include <QList>

class ParseData : public QObject
{
    Q_OBJECT
public:
    explicit ParseData(QObject *parent = nullptr);
    ParseData (QJsonObject data);
    QList<QJsonValue> parse_data();

private:
    QJsonObject data;

signals:

};

#endif // PARSEDATA_H
