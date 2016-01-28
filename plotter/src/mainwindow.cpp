#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSerialPort/QtSerialPort>
#include <QThread>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusBar->showMessage("Disconnected");

    serial = new QSerialPort(this);
    connect(serial, SIGNAL(readyRead()), this, SLOT(readData()));
    updateSerialAdapterList();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_scan_released()
{
    updateSerialAdapterList();
}

void MainWindow::on_connect_released()
{
    if(!ui->serialAdapter->currentText().isEmpty())
    {
        ui->statusBar->showMessage("Connecting...");
        ui->connect->setDisabled(true);
        if(connectSerial(ui->serialAdapter->currentText()))
        {
            ui->connect->setText("Disconnect");
            ui->connect->setEnabled(true);
        }
        else
        {
            ui->connect->setText("Connect");
            ui->connect->setEnabled(true);
        }
    }
}

void MainWindow::on_actionSettings_triggered()
{

}

void MainWindow::readData()
{
    char *temp = new char[serial->size()];

    serial->read(temp, serial->size());
    qDebug() << "Recieved:" << *temp;
}

bool MainWindow::connectSerial(const QString &port)
{
    serial->setPortName(port);
    serial->setBaudRate(QSerialPort::Baud19200);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::HardwareControl);
    return serial->open(QIODevice::ReadWrite);
}

void MainWindow::updateSerialAdapterList()
{
    ui->serialAdapter->clear();
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        ui->serialAdapter->addItem(info.portName());
    }
    debug("Update list.");
}

void MainWindow::debug(const QString &text)
{
    ui->debugField->append(text);
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if (arg1)
    {
        ui->debugField->show();
    }
    else
    {
        ui->debugField->hide();
    }
}
