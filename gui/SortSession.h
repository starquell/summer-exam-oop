#pragma once
#include <QStringListModel>


namespace Ui {
class MainWindow;
}


class SortSession{
public:
    SortSession() = default;

private:
    Ui::MainWindow* _ui;
    QStringListModel* _unsortedModel;
    QStringListModel* _sortedModel;
};
