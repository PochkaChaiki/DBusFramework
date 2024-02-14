#ifndef DBUSFRAMEWORKADAPTOR_H
#define DBUSFRAMEWORKADAPTOR_H

#include <QDBusAbstractAdaptor>
#include <QObject>
#include <vector>
#include <unordered_set>


class DBusFrameworkAdaptor : QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.example.DBusFramework")

public:
    DBusFrameworkAdaptor(QObject* obj);
    ~DBusFrameworkAdaptor();

    std::unordered_set<QString> formatSet;
    std::unordered_set<QString> invocationSet;

public slots:
    void registerFormat(const QString& serviceName, const QString& format);
    void registerInvocation(const QString& serviceName, const QString& objectPath, const QString& methodName);


signals:
    void formatRegistered(const QString& format);
    void invocationRegistered(const QString& serviceName, const QString& objectPath, const QString& methodName);

public:
    std::vector<QString> getFormat(const QString& serviceName);
    std::vector<QString> getInvokationWay(const QString& serviceName);

};

#endif // DBUSFRAMEWORKADAPTOR_H
