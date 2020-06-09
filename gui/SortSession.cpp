#include "SortSession.h"
#include <QStringListModel>
#include <include/Sort.hpp>

#include "ui_mainwindow.h"

namespace exam{
namespace detail{
auto to_sort_policy(std::size_t i)
{
    return static_cast<typename std::underlying_type<sort::Sorter<int>::SortType>::type>(i);
}
}//namespace detail

SortSession::SortSession(Ui::MainWindow* ui): _ui(ui){}


void SortSession::createNewSession(const std::vector<int>& vec){

    _unsorted = vec;
    _display_unsorted();
}

void SortSession::_display_unsorted(){
    _unsortedModel = new QStringListModel();
    QStringList view;
    for(const auto& i: _unsorted)
        view << QString::fromStdString(std::to_string(i));
    _unsortedModel->setStringList(view);
    _ui->CurrentContainer->setModel(_unsortedModel);
}

void SortSession::_display_sorted(const std::vector<int>& sorted){
    _sortedModel = new QStringListModel();
    QStringList view;
    for(const auto& i: sorted)
        view << QString::fromStdString(std::to_string(i));
    _sortedModel->setStringList(view);
    _ui->SortedContainer->setModel(_sortedModel);
}

void SortSession::sort(){
    auto index = _ui->typeSort->currentIndex();
    auto policy = (sort::Sorter<int>::SortType)index;
    std::vector<int> sorted = _unsorted;
    sort::Sorter<int>{}.sort_type(policy)
                       .comparator(std::less<int>{})
                       .sort(sorted.begin(), sorted.end());
   _display_sorted(sorted);

}


}

