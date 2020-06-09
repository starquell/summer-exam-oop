#include <QApplication>
#include "mainwindow.hpp"

int main (int argc, char* argv[]) {

    QApplication app(argc, argv);
    exam::MainWindow w;
    w.show();

    return app.exec();
}
