#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include <QMediaPlayer>
#include <QCloseEvent>
#include <QMessageBox>
#include <gui/containersession.hpp>
#include <AllExam.hpp>

namespace exam{
MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    _music = new QMediaPlayer();
    _music->setVolume(70);

    _music->setMedia(QUrl("qrc:/sounds/Everlasting.mp3"));
    _music->play();
    _containerSession = new ContainerSession(ui);
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



void MainWindow::closeEvent(QCloseEvent *event)
{
    event->ignore();
    this->_music->pause();
    QMediaPlayer *good_bye = new QMediaPlayer();
    good_bye->setVolume(70);

    good_bye->setMedia(QUrl("qrc:/sounds/Bye.mp3"));
    good_bye->play();
    if (QMessageBox::Yes == QMessageBox::question(this, "Завершити подоріж?", "Ви справді хочете завершити нашу сумісну"
                                                  "  подоріж довжиною в два семестра? Дякуюмо вам за цей прекрасний рік :)", QMessageBox::Yes | QMessageBox::No))
    {
        event->accept();
    }
    good_bye->stop();
    this->_music->play();

}
}

void exam::MainWindow::on_NewSession_clicked()
{
    _containerSession->startNewSession();
}
