#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QtSerialPort>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


    void on_scan_released();

    void on_connect_released();

    void on_actionSettings_triggered();

    void readData();




    void on_checkBox_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
    bool connectSerial(const QString &port);
    void updateSerialAdapterList();
    void debug(const QString &text);

};

#endif // MAINWINDOW_H
