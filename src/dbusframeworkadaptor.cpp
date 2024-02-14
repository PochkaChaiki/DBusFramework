#include "dbusframeworkadaptor.h"
#include <QObject>

DBusFrameworkAdaptor::DBusFrameworkAdaptor(QObject* obj) : QDBusAbstractAdaptor(obj) {

    // Connect to the session bus
    QDBusConnection sessionBus = QDBusConnection::sessionBus();

    // Register our object on the bus
    sessionBus.registerObject("/", this);

    // Register our service on the bus
    sessionBus.registerService("org.example.DBusFramework");
}

DBusFrameworkAdaptor::~DBusFrameworkAdaptor(){

    // Unregister the object from the bus
    QDBusConnection::sessionBus().unregisterObject("/");

    // Unregister the service from the bus
    QDBusConnection::sessionBus().unregisterService("org.example.DBusFramework");
}

void DBusFrameworkAdaptor::registerFormat(const QString& serviceName, const QString& format)
{

    formatSet.insert({serviceName, format});
    emit formatRegistered(format);
}

void DBusFrameworkAdaptor::registerInvocation(const QString& serviceName, const QString& objectPath, const QString& methodName)
{
    invocationSet.insert({serviceName, methodName});
    emit invocationRegistered(serviceName, objectPath, methodName);
}


// std::vector<QString> DBusFrameworkAdaptor::getFormat(const QString& serviceName)
// {
//     std::vector<QString> availableFormats;
//     for (auto it = set.begin(); it != set.end(); ++it){
//         availableFormats.push_back(it->second);
//     }
//     return availableFormats;
// }

// std::vector<QString> DBusFrameworkAdaptor::getInvokationWay(const QString& serviceName)
// {
//     std::vector<QString> availableInvokationWays;
//     auto range = invocationMap.equal_range(serviceName);
//     for (auto it = range.first; it != range.second; ++it){
//         availableInvokationWays.push_back(it->second);
//     }
//     return availableInvokationWays;
// }
