#include <vector>

// Enum to dictate the boundary condition
enum BoundaryCondition
{
    closed,
    wrap
};

class Grid
{
private:
    std::vector<int> values;
    int rows;
    int columns;
    BoundaryCondition boundaryCondition;

public:
    Grid(std::vector<int>, int, int, BoundaryCondition);
    int value_at(int, int);
    void print();
};