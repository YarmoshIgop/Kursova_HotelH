#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <secondwindow.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString login = ui->login->text();
    QString password = ui->pass->text();

    if(login == "admin" && password == "test"){
        //QMessageBox::information(this,"message","YcTTiX"); Вивід повідомлення в окремому вікні
        ui->statusbar->showMessage("ВИ успішно авторизувалися"); //Вивід повідомлення внизу вікна

        hide();
        window = new secondwindow(this);
        window->show();

    }else{
        //QMessageBox::warning(this,"oh","gg");
        ui->statusbar->showMessage("пароль або логін невірний!");


    }

}
