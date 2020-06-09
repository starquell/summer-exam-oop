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

ContainerSession::ContainerSession(Ui::MainWindow* ui): _ui(ui){}


void ContainerSession::startNewSession(){
    auto index = _ui->comboBox_2->currentIndex();
    auto basePolicy = detail::to_container_base_policy(index);

    switch (basePolicy){
    case SingleLinked:
        _set = Set<int, lists::SinglyLinkedList>();
        _ui->Setup->setPlainText("SingleLinkedList<int>");
        break;
    case DoubleLinked:
        _set = Set<int, lists::DoubleLinkedList>();
        _ui->Setup->setPlainText("DoubleLinkedList<int>");
        break;
    case DoubleCycled:
        _set = Set<int, lists::CyclicLinkedList>();
        _ui->Setup->setPlainText("CyclicLinkedList<int>");
        break;
    case AVL:
        _set = Set<int, tree::AVLTree>();
        _ui->Setup->setPlainText("AVL<int>");
        break;
    case Splay:
        _set = Set<int, tree::SplayTree>();
        _ui->Setup->setPlainText("Splay<int>");
        break;
    case RB:
        _set = Set<int, tree::RedBlackTree>();
        _ui->Setup->setPlainText("RedBlack<int>");
        break;
    case StdUnorderedSet:
        _set = Set<int, std::unordered_set>();
        _ui->Setup->setPlainText("std::unordered_set<int>");
        break;
    }
}

void ContainerSession::_display(){
    delete(_setModel);
    _setModel = new QStringListModel();
    QStringList view;
}


}//namespace exam
