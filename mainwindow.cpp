#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "routehandler.h"


#include <QtNetwork/QHostAddress>
#include <QSystemTrayIcon>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Load Icons for system tray icon
    slowIcon = QIcon("./slowicon.png");
    fastIcon = QIcon("./fasticon.png");


    metricDisabled = 200;
    metricEnabled = 2;

    // Add tray icon to system tray
    trayIcon = new QSystemTrayIcon(slowIcon, this);
    trayIcon->show();

    isSlowNet = true;

    // Instantate route handler
    routeHander = RouteHandler();

    firstRoute = QHostAddress("192.168.1.1");
    secondRoute = QHostAddress("192.168.1.2");

    routeHander.deleteGateways();
    routeHander.addRoute(firstRoute, metricEnabled);
    routeHander.addRoute(secondRoute, metricDisabled);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete trayIcon;
}


void MainWindow::on_pushButton_clicked()
{
     on_trayicon_activated(QSystemTrayIcon::DoubleClick);
}

void MainWindow::on_trayicon_activated(QSystemTrayIcon::ActivationReason reason) {
    // Toggle gateways on double click and change icon
    if (reason == QSystemTrayIcon::DoubleClick) {
        routeHander.deleteGateways();
        if (isSlowNet) {
            routeHander.addRoute(secondRoute, metricEnabled);
            routeHander.addRoute(firstRoute, metricDisabled);
            trayIcon->setIcon(fastIcon);
            isSlowNet = false;
        } else {
            routeHander.addRoute(firstRoute, metricEnabled);
            routeHander.addRoute(secondRoute, metricDisabled);
            trayIcon->setIcon(slowIcon);
            isSlowNet = true;
        }
    } else if (reason == QSystemTrayIcon::MiddleClick) {
        show();
    }

}

void MainWindow::on_menu_settings_triggered() {
   // SettingsWindow settings;

}

void MainWindow::on_actionSettings_triggered()
{
    settings.setModal(true);
    settings.exec();
}
