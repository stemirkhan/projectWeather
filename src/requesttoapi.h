#ifndef REQUESTTOAPI_H
#define REQUESTTOAPI_H

#include <QObject>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QJsonObject>

class RequestToAPI : public QObject
{
    Q_OBJECT
public:
    explicit RequestToAPI(QObject *parent = nullptr);
    QNetworkAccessManager *manager;
    QNetworkRequest rq;
    QNetworkReply *repl;
    QByteArray data_buffer;

public slots:
    void get_data(QString url);
    void readData();

signals:

};

#endif // REQUESTTOAPI_H
