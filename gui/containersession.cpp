#include "containersession.hpp"
#include "ui_mainwindow.h"
#include "Set.hpp"
#include "AVL.hpp"
#include "RedBlack.hpp"
#include "Splay.hpp"
#include "SinglyLinked.hpp"
#include <unordered_set>


namespace exam{
namespace detail{
auto to_container_base_policy(std::size_t i)
{
    return static_cast<typename std::underlying_type<ContainerBase>::type>(i);
}
}//namespace detail

ContainerSession::ContainerSession(Ui::MainWindow* ui): _ui(ui), _set(Set<std::string, lists::SinglyLinkedList>{}){}


void ContainerSession::startNewSession(){
    auto index = _ui->comboBox_2->currentIndex();
    auto basePolicy = detail::to_container_base_policy(index);

    switch (basePolicy){
    case SingleLinked:
        _set.assign( Set<std::string, lists::SinglyLinkedList>());
        _ui->Setup->setPlainText("SingleLinkedList<std::string>");
        break;
    case DoubleLinked:
        _set.assign( Set<std::string, lists::DoubleLinkedList>());
        _ui->Setup->setPlainText("DoubleLinkedList<std::string>");
        break;
    case DoubleCycled:
        _set.assign( Set<std::string, lists::CyclicLinkedList>());
        _ui->Setup->setPlainText("CyclicLinkedList<std::string>");
        break;
    case AVL:
        _set.assign( Set<std::string, tree::AVLTree>());
        _ui->Setup->setPlainText("AVL<std::string>");
        break;
    case Splay:
        _set.assign( Set<std::string, tree::SplayTree>());
        _ui->Setup->setPlainText("Splay<std::string>");
        break;
    case RB:
        _set.assign(Set<std::string, tree::RedBlackTree>());
        _ui->Setup->setPlainText("RedBlack<std::string>");
        break;
    case StdUnorderedSet:
        _set.assign( Set<std::string, std::unordered_set>());
        _ui->Setup->setPlainText("std::unordered_set<std::string>");
        break;
    }
}

void ContainerSession::_display(){
    _setModel = new QStringListModel();
    QStringList view;
    for(const auto& i: _set)
        view << QString::fromStdString(i);
    _setModel->setStringList(view);
    _ui->currentContainer->setModel(_setModel);
}

void ContainerSession::insert(){
    std::string val = _ui->ValueToInsert->toPlainText().toStdString();
    _set.insert(val);
    _display();
}


void ContainerSession::erase(){
    std::string val = _ui->ValueToInsert->toPlainText().toStdString();
    _set.erase(val);
    _display();
}


}//namespace exam
