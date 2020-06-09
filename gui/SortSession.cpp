#include "SortSession.h"
#include <QStringListModel>

SortSession::SortSession(){}


void SortSession::createNewSession(){
    _unsortedModel = new QStringListModel;
    _sortedModel = new QStringListModel;

}
