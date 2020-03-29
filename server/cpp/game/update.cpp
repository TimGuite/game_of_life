// Contains the functions to update a grid to the next time step
#include <iostream>
#include <vector>

#include "grid.hpp"

using namespace std;

Grid update(Grid currentGrid)
{
    // Create a vector which is the same size as the current grid
    vector<int> nextGrid(currentGrid.values.size());

    for (int y = 0; y < currentGrid.rows; y++)
    {
        for (int x = 0; x < currentGrid.columns; x++)
        {
            // Count the neighbours
            int neighbours = 0;
            neighbours += currentGrid.value_at(x - 1, y - 1);
            neighbours += currentGrid.value_at(x, y - 1);
            neighbours += currentGrid.value_at(x + 1, y - 1);
            neighbours += currentGrid.value_at(x - 1, y);
            neighbours += currentGrid.value_at(x + 1, y);
            neighbours += currentGrid.value_at(x - 1, y + 1);
            neighbours += currentGrid.value_at(x, y + 1);
            neighbours += currentGrid.value_at(x + 1, y + 1);

            //cout << "Neighbours: " << neighbours << endl;

            int index = x + (y * currentGrid.columns);

            if (currentGrid.value_at(x, y) > 0)
            {
                if (neighbours == 2 || neighbours == 3)
                {
                    nextGrid[index] = 1;
                }
                else
                {
                    nextGrid[index] = 0;
                }
            }
            else
            {
                if (neighbours == 3)
                {
                    nextGrid[index] = 1;
                }
                else
                {
                    nextGrid[index] = 0;
                }
            }
        }
    }

    return Grid(nextGrid, currentGrid.rows, currentGrid.columns, currentGrid.boundaryCondition);
}
