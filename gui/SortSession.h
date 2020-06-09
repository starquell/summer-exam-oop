#pragma once
#include <QStringListModel>

namespace Ui{
class MainWindow;
}
namespace exam{
enum class Sortings{
    Select,
    Quick,
    Merge,
    Bucket,
    Insert,
    Heap,
    Radix,
    Counting
};


class SortSession{
public:
    SortSession() = default;
    SortSession(Ui::MainWindow* ui);

    void createNewSession(const std::vector<int>& vec);
    void sort();
private:
    void _display_sorted(const std::vector<int>& sorted);
    void _display_unsorted();
    Ui::MainWindow* _ui;
    QStringListModel* _unsortedModel;
    QStringListModel* _sortedModel;
    std::vector<int> _unsorted;
};

}
