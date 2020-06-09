#ifndef CONTAINERSESSION_HPP
#define CONTAINERSESSION_HPP

#include<QStringListModel>
#include<any>

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

//    void insert();

//    void erase();
private:
    ContainerBase _curPolicy;
    void _display();
    Ui::MainWindow* _ui;
    QStringListModel* _setModel;
    std::any _set;

};
}

#endif // CONTAINERSESSION_HPP
