#pragma once

#include "../include/ToString.hpp"
#include "../include/Trees/Splay.hpp"
#include "../include/HashTables/StaticCoalested.hpp"

#include <vector>
#include <array>

TEST_CASE ("To String") {

    REQUIRE (exam::to_string("hello world") == "hello world");
    REQUIRE (exam::to_string(2144) == "2144");
    REQUIRE (exam::to_string(std::vector {34, 124, 44}) == "34 124 44");
    REQUIRE (exam::to_string(std::array {"somebody", "once", "told", "me"}, " (0_0) ")
             == "somebody (0_0) once (0_0) told (0_0) me");
}