#ifndef CONTAINERSESSION_HPP
#define CONTAINERSESSION_HPP

#include<QStringListModel>
#include<any>
#include <AnySet.hpp>
#include "AVL.hpp"
#include "RedBlack.hpp"
#include "Splay.hpp"
#include "SinglyLinked.hpp"
#include <unordered_set>

namespace Ui {
class MainWindow;
}
namespace exam{
enum ContainerBase{
    SingleLinked,
    DoubleLinked,
    DoubleCycled,
    AVL,
    RB,
    Splay,
    StdUnorderedSet
};



class ContainerSession
{
public:
    ContainerSession() = default;
    ContainerSession(Ui::MainWindow* ui);

    void startNewSession();

    void insert();

    void erase();

    private:
    ContainerBase _curPolicy;
    void _display();
    Ui::MainWindow* _ui;
    QStringListModel* _setModel;
    AnySet<std::string, tree::SplayTree, tree::RedBlackTree, tree::AVLTree, lists::SinglyLinkedList,
             lists::DoubleLinkedList, lists::CyclicLinkedList, std::unordered_set> _set;

};
}

#endif // CONTAINERSESSION_HPP
