#include "requesttoapi.h"

RequestToAPI::RequestToAPI(QObject *parent)
    : QObject{parent}
{
    manager = new QNetworkAccessManager(this);
}

void RequestToAPI::get_data(QString url)
{
    QNetworkRequest rq{QUrl(url)};
    repl = manager->get(rq);
    connect(repl, &QNetworkReply::finished, this, &RequestToAPI::readData);
}

void RequestToAPI::readData()
{
    data_buffer.append(repl->readAll());
    QJsonObject data = QJsonDocument::fromJson(data_buffer).object();
    qDebug() << data;
}




