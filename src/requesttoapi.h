#ifndef REQUESTTOAPI_H
#define REQUESTTOAPI_H

#include <QObject>
#include <QNetworkReply>
#include <QNetworkAccessManager>

class RequestToAPI : public QObject
{
    Q_OBJECT
public:
    explicit RequestToAPI(QObject *parent = nullptr);
    QNetworkAccessManager *manager;
    QNetworkRequest *rq;
    QByteArray get_requests_to_api(QString url);

signals:

};

#endif // REQUESTTOAPI_H
