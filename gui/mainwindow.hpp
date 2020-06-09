#pragma once

#include <QMainWindow>
#include <QCloseEvent>
#include<QMediaPlayer>

namespace Ui {
    class MainWindow;
}

namespace exam{

class ContainerSession;
class SortSession;

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_ConfirmIntro_clicked();

    void on_NewSession_clicked();

    void on_insertContainer();

    void on_Erase_clicked();

    void on_gen();

    void on_new_unsorted();

    void on_sort();

private:
    void closeEvent(QCloseEvent *event);
    ContainerSession *_containerSession;
    SortSession *_sortSession;
    QMediaPlayer *_music;
    Ui::MainWindow *ui;
};
}//namespace exam
