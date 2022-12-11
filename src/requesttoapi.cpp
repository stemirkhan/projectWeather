#include "requesttoapi.h"

RequestToAPI::RequestToAPI(QObject *parent)
    : QObject{parent}
{
    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &RequestToAPI::respone_handler);
}

void RequestToAPI::send_request(QString url)
{
    manager->get(QNetworkRequest(QUrl(url)));
}

void RequestToAPI::respone_handler(QNetworkReply *repl)
{
    if(!repl->error())
    {
        QByteArray data_buffer = repl->readAll();
        data = QJsonDocument::fromJson(data_buffer).object();
        emit handler_finished(data);
    }
}
