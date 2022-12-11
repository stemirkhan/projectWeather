#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    my_request = new RequestToAPI(this);
    connect(my_request, &RequestToAPI::handler_finished, this, &MainWindow::update_view);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_view(QList<QJsonValue> data)
{
    QPixmap icon("D:\\Work\\Smth\\Weather\\projectWeather\\icons\\01d (2).png");
    ui->temperature_first_line->setText(QString::number(data[0]["main"]["temp"].toDouble()));
    ui->image_first_line->setPixmap(icon);
}

void MainWindow::on_search_button_clicked()
{
    QString city = ui->search_line_edit->text();
    my_request->send_request("http://api.openweathermap.org/data/2.5/forecast?q="+ city + "&appid=7c88289d3a5d79050c2e473adc10dad0&lang=ru");
}
