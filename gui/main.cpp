#include <QGuiApplication>
#include <QMainWindow>
#include <QtWidgets/QApplication>

int main (int argc, char* argv[]) {

    QApplication app {argc, argv};
    QMainWindow window;
    window.show();

    return QGuiApplication::exec();
}