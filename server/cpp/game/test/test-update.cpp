#include "catch.hpp"

#include <vector>

#include "update.hpp"

TEST_CASE("Test static updates", "[static]")
{
    SECTION("Closed grid")
    {
        Grid g(
            {0, 0, 0, 0,
             0, 1, 1, 0,
             0, 1, 1, 0,
             0, 0, 0, 0},
            4,
            4,
            closed);

        REQUIRE(g.values == update(g).values);
    }
}