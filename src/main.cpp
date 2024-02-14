#include <QCoreApplication>
#include "dbusframework.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Create an instance of the DBusFramework
    DBusFramework dbusFramework;

    // Register formats and invocations
    dbusFramework.registerFormat("text");
    dbusFramework.registerInvocation("org.example.Service", "/org/example/Object", "methodName");

    return a.exec();
}
