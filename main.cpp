#include "mainwindow.h"
#include "networkthread.h"
#include "runguard.h"
#include <QApplication>
#include <QDebug>
#include "fileutils.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    RunGuard guard("WifiMouseServer");
    if( !guard.tryToRun() ) {
        QSystemTrayIcon dummy;
        dummy.show();
        dummy.showMessage("WifiMouseServer", "Already running");
        dummy.hide();
        return 0;
    }

    MainWindow w;
    NetworkThread networkThread;
    networkThread.mainWindow = &w;
    networkThread.start();

    return a.exec();
}
