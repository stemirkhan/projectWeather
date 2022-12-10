#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    my_request = new RequestToAPI();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QByteArray data_buffer = my_request->get_requests_to_api("http://ip-api.com/json/");

    QJsonObject data = QJsonDocument::fromJson(data_buffer).object();
    QString ip = data["query"].toString();

    ui->textEdit->setText(ip);
    qDebug() << "fddfd";
}

