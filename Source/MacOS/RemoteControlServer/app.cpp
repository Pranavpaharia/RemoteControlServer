#include "apiv2.h"
#include "apiv3.h"
#include "app.h"
#include "authentication.h"
#include "logger.h"
#include "settings.h"

App::App()
{
    ip = "Unknown";
    appVersion = "Unknown";
    appName = "Unknown";
    deviceName = "Unknown";
    pin = "";

    isConnected = false;
}

void App::onConnect()
{
    isConnected = true;
    Logger::Instance()->add(QString(deviceName) + " connected");
    // Server.gui.showNotification
    QString label = (appName == "Unknown" || appVersion == "Unknown")
            ? deviceName: QString(appName) + " " + QString(appVersion) + " on a " + QString(deviceName);
    Logger::Instance()->trackEvent("App", "Connect", label);
    Settings::Instance()->showGuide = false;
}

void App::onDisconnect()
{
    isConnected = false;
    Logger::Instance()->add(QString(deviceName) + " disconnected");
}

void App::onPause()
{
    Logger::Instance()->add(QString(deviceName) + " paused the connection");
}

void App::onResume()
{
    Logger::Instance()->add(QString(deviceName) + " resumed the connection");
}

void App::onBroadCast(Command *command)
{
    Logger::Instance()->add("Connection request from " + ip);
    if (Authentication::Instance()->isAuthenticated(ip, pin))
    {
        Logger::Instance()->add("Allowing to connec");
    }
}

void App::answerBroadCast(Command *command)
{
    switch (command->api) {
    case (3):
//        ApiV2::Instance()->answerBroadcast
        break;
    }
}