#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <requesttoapi.h>
#include <QPixmap>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    RequestToAPI *my_request;
    ~MainWindow();

private:
    Ui::MainWindow *ui;


private slots:
    void update_view(QList<QMap<QString, QString>> data);
    void on_search_button_clicked();
};
#endif // MAINWINDOW_H
