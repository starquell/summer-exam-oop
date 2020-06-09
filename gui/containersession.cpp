#include "containersession.hpp"
#include "ui_mainwindow.h"
#include "AllExam.hpp"
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
        _set = Set<int, lists::SinglyLinkedList>;
        break;
    case DoubleLinked:
        _set = Set<int, lists::DoubleLinkedList>;
        break;
    case DoubleCycled:
        _set = Set<int, lists::CyclicLinkedList>;
        break;
    case

    }
}
}//namespace exam
