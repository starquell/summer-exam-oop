#pragma once

#include <QMainWindow>
#include <QCloseEvent>
#include<QMediaPlayer>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_ConfirmIntro_clicked();

private:
    void closeEvent(QCloseEvent *event);

    QMediaPlayer *_music;
    Ui::MainWindow *ui;
};
