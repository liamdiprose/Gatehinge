#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "routehandler.h"
#include "settingsdialog.h"

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QIcon>
#include <QDebug>

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
    void on_checkBox_toggled(bool checked);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_trayicon_activated(QSystemTrayIcon::ActivationReason reason);

    void on_menu_settings_triggered();

    void on_actionSettings_triggered();

private:
    QSystemTrayIcon* trayIcon;
    Ui::MainWindow *ui;
    QIcon fastIcon;
    QIcon slowIcon;

    bool isSlowNet;
    RouteHandler routeHander;

    QHostAddress firstRoute;
    QHostAddress secondRoute;

    uint16_t metricDisabled;
    uint16_t metricEnabled;

    SettingsDialog settings;
};

#endif // MAINWINDOW_H
