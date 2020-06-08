#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include <QMediaPlayer>


#include <AllExam.hpp>

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    QMediaPlayer *music = new QMediaPlayer();
    music->setVolume(70);

    music->setMedia(QUrl("qrc:/sounds/Everlasting.mp3"));
    music->play();
    ui->Greeting->setPlainText("  Привіт, мене звати Алісочка. Рада вас бачити на літньому екзамені в таборі <<Совеня>>!"
                               " Тут ми пройдемося по алеї дерев різних видів, зіставимо списки членів табора "
                               "(списки також ріноманітні), відсортуємо книжки(як самотужки, так і разом з друзями "
                               "з сім'ї з дивним прізвишем Потік) а також розставимо їх в бібліотеці і"
                               " створимо для навігації по ній різного роду хеші. Також будемо організовувати роботу "
                               "підприємств і налагоджувати випуск книг \n  Ви підете зі мною?");
}

MainWindow::~MainWindow()
{
    delete ui;
}
    

void MainWindow::on_ConfirmIntro_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
