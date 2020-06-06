#pragma once

#include "../include/HashTables/StaticCoalested.hpp"
#include "../include/Random.hpp"

using namespace exam::hashtable;

SCENARIO_TEMPLATE ("Hash tables", HashTable,
        StaticCoalestedHashTable<int, 100>)
{
    auto table = exam::random<HashTable>


}