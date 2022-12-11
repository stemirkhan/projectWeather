#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    my_request = new RequestToAPI();
    //my_request->send_request("http://ip-api.com/json/24.48.0.1");
    connect(my_request, &RequestToAPI::handler_finished, this, &MainWindow::update_view);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_view(QJsonObject data)
{
    qDebug() << data;
}
