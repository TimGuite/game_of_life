#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include <iostream>
#include <vector>

#include "grid.h"

using namespace std;

Grid::Grid(vector<int> values, int rows, int columns, BoundaryCondition boundaryCondition)
    : values(values), rows(rows), columns(columns), boundaryCondition(boundaryCondition)
{
}

int Grid::value_at(int x, int y)
{
    if (x >= 0 && x < columns && y >= 0 && y < rows)
    {
        return values[x + (y * columns)];
    }
    else if (boundaryCondition == closed)
    {
        return 0;
    }
    else
    {
        // Necessary calculation due to C++ modulo calculation
        // https://stackoverflow.com/questions/13794171/how-to-make-the-mod-of-a-negative-number-to-be-positive?rq=1
        //((x % divisor) + divisor) % divisor
        x = ((x % columns) + columns) % columns;
        y = ((y % rows) + rows) % rows;
        return values[x + (y * columns)];
    }
}

void Grid::print()
{
    // Iterate over the vector, printing 'X' when value is > 0 and '.' otherwise
    for (int y = 0; y < rows; y++)
    {
        for (int x = 0; x < columns; x++)
        {
            if (value_at(x, y) > 0)
            {
                cout << "X ";
            }
            else
            {
                cout << ". ";
            }
        }
        // Print a line break
        cout << endl;
    }
}

// int main()
// {
//     vector<int> v = {1, 2, 3, 4, 5};

//     Grid g = Grid(v, 1, 5, closed);

//     cout << g.value_at(3, 0) << endl;
//     cout << g.value_at(1, 1) << endl; // Should be 0

//     vector<int> y = {1, 2, 3, 4, 5, 6, 7, 8, 9};

//     Grid g2 = Grid(y, 3, 3, wrap);

//     cout << g2.value_at(1, 1) << endl; // Should be 5
//     cout << g2.value_at(3, 1) << endl; // Should be 4

//     Grid g3 = Grid({0, 0, 0, 0, 1, 0, 0, 0, 0}, 3, 3, closed);
//     g3.print();

//     return 0;
// }

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