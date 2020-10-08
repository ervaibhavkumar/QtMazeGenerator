#pragma once

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QStack>
#include <QThread>
#include <QTimer>
#include <QTime>

#include "cell.h"


class Maze : public QGraphicsView
{
    Q_OBJECT
public slots:
    void generate();

public:
    Maze(QSize size);
    Cell * getFreeNeighbour(Cell * curr);
    void removeWalls(Cell * c, Cell *n);
    int getIndex(int i, int j);

    QSize sizeOfScreen;
    int speed = 20;
    int cellSize = 35;
    int numRows;
    int numCols;
    std::vector<std::unique_ptr<Cell*>> grid;
    QStack<Cell *> history;
    Cell* current_cell = nullptr;
    Cell* next = nullptr;
    QTimer *timer;

private:
    void CreateBackGroundColor();
    void CreateCellColorFromBg();
    void CreateWallColor();

    QColor bgColor;
    QColor cellColor;
    QColor wallColor;
};
