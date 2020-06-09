#pragma once
#include <QStringListModel>

namespace Ui{
class MainWindow;
}

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
    SortSession();

    void createNewSession();
    void sort();


private:
    bool numeric;
    Ui::MainWindow* _ui;
    QStringListModel* _unsortedModel;
    QStringListModel* _sortedModel;
};
