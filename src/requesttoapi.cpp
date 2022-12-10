#include "requesttoapi.h"

RequestToAPI::RequestToAPI(QObject *parent)
    : QObject{parent}
{
    manager = new QNetworkAccessManager(this);
}

QByteArray RequestToAPI::get_requests_to_api(QString url)
{
    QNetworkReply *response = manager->get(QNetworkRequest(QUrl(url)));

    return response->readAll();

}
