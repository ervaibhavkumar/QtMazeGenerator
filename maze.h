#ifndef MAZE_H
#define MAZE_H

#include "cell.h"
#include <vector>
#include <QGraphicsView>

class Maze : public QGraphicsView
{
public:
    Maze(QSize sizeOfScreen, QGraphicsView *parent = nullptr);
    void CreateMaze();

private:
    QColor getBackGroundColor();
    int getCellBackground(int hue, int hueShift);

    QSize screenSize;
    std::vector<Cell> *grid = new std::vector<Cell>();
    Cell *current;
    QStack<Cell> *stack = nullptr;

    int numRows;
    int numCols;
    int cellSize = 35;
};

#endif // MAZE_H
