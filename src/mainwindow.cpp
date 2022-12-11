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

void MainWindow::update_view(QList<QMap<QString, QString>> data)
{

    QPixmap icon;

    icon.load("../icons/" +data[0]["icon"] + ".png");
    ui->temperature_first_line->setText(data[0]["temp"]);
    ui->image_first_line->setPixmap(icon);
    ui->pressure_first_line->setText(data[0]["pressure"]);
    ui->wind_speed_first_line->setText(data[0]["speed"]);
    ui->time_first_line->setText(data[0]["date"]);

    icon.load("../icons/" +data[1]["icon"] + ".png");
    ui->temperature_second_line->setText(data[1]["temp"]);
    ui->image_second_line->setPixmap(icon);
    ui->pressure_second_line->setText(data[1]["pressure"]);
    ui->wind_speed_second_line->setText(data[1]["speed"]);
    ui->time_second_line->setText(data[1]["date"]);

    icon.load("../icons/" +data[2]["icon"] + ".png");
    ui->temperature_third_line->setText(data[2]["temp"]);
    ui->image_third_line->setPixmap(icon);
    ui->pressure_third_line->setText(data[2]["pressure"]);
    ui->wind_speed_third_line->setText(data[2]["speed"]);
    ui->time_third_line->setText(data[2]["date"]);
}

void MainWindow::on_search_button_clicked()
{
    QString city = ui->search_line_edit->text();
    my_request->send_request("http://api.openweathermap.org/data/2.5/forecast?q="+ city + "&appid=7c88289d3a5d79050c2e473adc10dad0&lang=ru&"
                                                                                          "units=metric");
}
