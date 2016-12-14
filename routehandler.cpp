#include "routehandler.h"

RouteHandler::RouteHandler()
{
    isWindows = QSysInfo::windowsVersion() != 0;
    _isFirstRoute = true;
}

void RouteHandler::deleteGateways() {
    if (isWindows) {
        windowsDeleteGateways();
    } else {
        linuxDeleteGateways();
    }
}

void RouteHandler::addRoute(QHostAddress gateway, uint metric) {

    if (isWindows) {
        windowsAddRoute(gateway, metric);
    } else {
        linuxAddRoute(gateway, metric);
    }

}

int RouteHandler::linuxAddRoute(QHostAddress gateway, uint metric) {

// route add default gw 192.168.1.2
    QProcess route;
    route.start("route", QStringList() << "add" << "default" << "gw" << gateway.toString() << "metric" << QString::number(metric));
   // route.start("echo", QStringList() << "Hello" << "There");
    route.waitForFinished();
    QByteArray output = route.readAll();


    // Linux Errors
    // 7: File Exists

}

void RouteHandler::windowsAddRoute(QHostAddress gateway, uint metric) {
    QProcess route;
    route.start("route", QStringList() << "-p" << "add" << "0.0.0.0" << "mask" << "0.0.0.0" << gateway.toString() << "metric" << QString::number(metric));
    route.waitForFinished();
}

void RouteHandler::linuxDeleteGateways() {
    QProcess process;
    process.start("route", QStringList() << "del" << "default");
    process.waitForFinished();
}

void RouteHandler::windowsDeleteGateways() {
    QProcess process;
    process.start("route", QStringList() << "delete" << "0.0.0.0");
    process.waitForFinished();
}

bool RouteHandler::isFirstRoute() {
    return _isFirstRoute;
}
