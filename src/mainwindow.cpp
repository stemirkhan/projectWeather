#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    my_request = new RequestToAPI();
    my_request->send_request("http://api.openweathermap.org/data/2.5/forecast?q=Voronezh&appid=7c88289d3a5d79050c2e473adc10dad0&lang=ru");
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
