#pragma once

#include <QMainWindow>
#include <QCloseEvent>
#include<QMediaPlayer>

namespace Ui {
    class MainWindow;
}

namespace exam{

class ContainerSession;

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_ConfirmIntro_clicked();

    void on_NewSession_clicked();

private:
    void closeEvent(QCloseEvent *event);
    ContainerSession *_containerSession;
    QMediaPlayer *_music;
    Ui::MainWindow *ui;
};
}//namespace exam
