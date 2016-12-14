#ifndef ROUTEHANDLER_H
#define ROUTEHANDLER_H

#include <QProcess>
#include <QtNetwork/QHostAddress>
#include <QSysInfo>
#include <QDebug>
#include <QStringList>

class RouteHandler
{
public:
    RouteHandler();
    void deleteGateways();
    void addRoute(QHostAddress gateway, uint metric);

    bool isFirstRoute();

private:
    bool isWindows;
    bool _isFirstRoute;

    void linuxDeleteGateways();
    int linuxAddRoute(QHostAddress gateway, uint metric);

    void windowsDeleteGateways();
    void windowsAddRoute(QHostAddress gateway, uint metric);
};

#endif // ROUTEHANDLER_H
