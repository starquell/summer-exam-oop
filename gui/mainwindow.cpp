#include "mainwindow.hpp"

#include <QMediaPlayer>
#include <QCloseEvent>
#include <QMessageBox>
#include <gui/containersession.hpp>
#include <gui/SortSession.h>
#include <AllExam.hpp>
#include "ui_mainwindow.h"

#include<vector>

namespace exam{
MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    connect(ui->InsertContainer,SIGNAL(clicked()),this,SLOT(on_insertContainer()));
    connect(ui->Erase, SIGNAL(clicked()), this, SLOT(on_Erase_clicked()));
    connect(ui->GenerateValue, SIGNAL(clicked()), this, SLOT(on_gen()));
    connect(ui->GenArr, SIGNAL(clicked()), this, SLOT(on_new_unsorted()));
    connect(ui->SortArr, SIGNAL(clicked()), this, SLOT(on_sort()));
    _music = new QMediaPlayer();
    _music->setVolume(70);

    _music->setMedia(QUrl("qrc:/sounds/Everlasting.mp3"));
    _music->play();
    _containerSession = new ContainerSession(ui);
    _sortSession = new SortSession(ui);
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

void MainWindow::on_Erase_clicked(){
    _containerSession->erase();
}

void MainWindow::on_NewSession_clicked()
{
    _containerSession->startNewSession();
}

void MainWindow::on_insertContainer(){
    _containerSession->insert();
}

void MainWindow::on_gen(){
    ui->ValueToInsert->setPlainText(QString::fromStdString(random<std::string>()));
}

void MainWindow::on_new_unsorted(){
    auto size = ui->ContainerSize->value();
    auto new_vec = random<std::vector<int>>(size, 0, 100000);
    _sortSession->createNewSession(new_vec);
}

void MainWindow::on_sort(){
    _sortSession->sort();
}
}//namespace exam




