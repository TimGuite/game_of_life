#include "catch.hpp"

#include "grid.hpp"

TEST_CASE("Test simple grid", "[grid]")
{
    SECTION("Single line grids")
    {
        Grid g = Grid({1, 2, 3, 4, 5}, 1, 5, closed);
        REQUIRE(g.value_at(2, 0) == 3);
        REQUIRE(g.value_at(4, 0) == 5);

        Grid g2 = Grid({1, 2, 3, 4, 5}, 5, 1, closed);
        REQUIRE(g2.value_at(0, 2) == 3);
        REQUIRE(g2.value_at(0, 4) == 5);
    }

    SECTION("Single line grid with wrap")
    {
        Grid g = Grid({1, 2, 3, 4, 5}, 1, 5, wrap);
        REQUIRE(g.value_at(2, 0) == 3);
        REQUIRE(g.value_at(5, 0) == 1);
        REQUIRE(g.value_at(-1, 0) == 5);

        Grid g2 = Grid({1, 2, 3, 4, 5}, 5, 1, wrap);
        REQUIRE(g2.value_at(0, 2) == 3);
        REQUIRE(g2.value_at(0, 5) == 1);
        REQUIRE(g2.value_at(0, -1) == 5);
    }

    SECTION("Small grid - closed")
    {
        Grid g = Grid({1, 2, 3, 4, 5, 6, 7, 8, 9}, 3, 3, closed);
        REQUIRE(g.value_at(0, 0) == 1);
        REQUIRE(g.value_at(1, 1) == 5);
        REQUIRE(g.value_at(2, 2) == 9);
        REQUIRE(g.value_at(3, 3) == 0);
    }

    SECTION("Small grid - wrapped")
    {
        Grid g = Grid({1, 2, 3, 4, 5, 6, 7, 8, 9}, 3, 3, wrap);
        REQUIRE(g.value_at(0, 0) == 1);
        REQUIRE(g.value_at(1, 1) == 5);
        REQUIRE(g.value_at(2, 2) == 9);
        REQUIRE(g.value_at(3, 3) == 1);
        REQUIRE(g.value_at(-1, -1) == 9);
    }
}