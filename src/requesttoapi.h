#ifndef REQUESTTOAPI_H
#define REQUESTTOAPI_H

#include <QObject>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QJsonObject>
#include <parsedata.h>

class RequestToAPI : public QObject
{
    Q_OBJECT
public:
    explicit RequestToAPI(QObject *parent = nullptr);

private:
    QNetworkAccessManager *manager;
    QJsonObject data;

public slots:
    void send_request(QString url);

private slots:
    void respone_handler(QNetworkReply *repl);

signals:
    void handler_finished(QList<QJsonValue> data);
};

#endif // REQUESTTOAPI_H
