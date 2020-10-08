#include "maze.h"
#include "utilities.h"

#include <QDebug>

Maze::Maze(QSize size)
    : QGraphicsView(),
      sizeOfScreen(size)
{
    qsrand(QTime::currentTime().msec());

    QGraphicsScene *s = new QGraphicsScene();
    s->setSceneRect(0, 0, sizeOfScreen.width(), sizeOfScreen.height());
    CreateBackGroundColor();
    CreateCellColorFromBg();
    CreateWallColor();
    s->setBackgroundBrush(QBrush(bgColor, Qt::SolidPattern));
    setScene(s);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(sizeOfScreen.height(), sizeOfScreen.width());

    numRows = floor(sizeOfScreen.width() / cellSize);
    numCols = floor(sizeOfScreen.height() / cellSize);

    //setup grid and prepare first cell
    for(int i = 0; i < numRows; i++)
    {
        for(int j = 0; j < numCols; j++)
        {
            grid.push_back(std::make_unique<Cell*>( new Cell(i, j, cellSize, cellColor, wallColor, s)));
        }
    }

    current_cell = *grid.at(Utilities::random(0, grid.size()));
    current_cell->setVisited(true);
    current_cell->Show();
    history.push(current_cell);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(generate()));
    timer->start(speed);
}

void Maze::CreateBackGroundColor() {
    int r = Utilities::random(0, 255);
    int g = Utilities::random(0, 255);
    int b = Utilities::random(0, 255);

    bgColor = QColor(r, g, b);
}

void Maze::CreateCellColorFromBg() {
    cellColor = QColor(255 - bgColor.red(), 255 - bgColor.green(), 255 - bgColor.red());
}

void Maze::CreateWallColor() {
    wallColor = QColor(abs(bgColor.red() - cellColor.red()) / 2,
                       abs(bgColor.green() - cellColor.green()) / 2,
                       abs(bgColor.blue() - cellColor.blue()) / 2);
}

void Maze::generate()
{
    next = getFreeNeighbour(current_cell);
    if(next != nullptr)
    {
        current_cell->Hide();
        next->Show();
        history.push(next);
        next->setVisited(true);
        removeWalls(current_cell, next);
        current_cell = next;
    }
    else if(!history.isEmpty())
    {
        //backtracing
        current_cell->Hide();
        current_cell = history.pop();
        current_cell->Show();
    }
    else if(history.isEmpty())
    {
        //end
        timer->stop();
        current_cell->Hide();
    }
}

void Maze::removeWalls(Cell * c, Cell *n)
{
    int cx = c->getRowIndex(),
            cy = c->getColIndex(),
            nx = n->getRowIndex(),
            ny = n->getColIndex();

    switch(cx-nx)
    {
    case 1:
        c->left->hide();
        n->right->hide();
        //scene()->removeItem(n->d);
        //scene()->removeItem(c->a);
        break;
    case -1:
        c->right->hide();
        n->left->hide();
        /*remove*/
        //scene()->removeItem(c->d);
        //scene()->removeItem(n->a);
        break;
    }

    switch(cy-ny)
    {
    case 1:
        c->top->hide();
        n->bottom->hide();
        //scene()->removeItem(c->w);
        //scene()->removeItem(n->s);
        break;
    case -1:
        c->bottom->hide();
        n->top->hide();
        //scene()->removeItem(c->s);
        //scene()->removeItem(n->w);
        break;
    }
}

Cell * Maze::getFreeNeighbour(Cell * curr)
{
    int curX = curr->getRowIndex(), curY = curr->getColIndex();
    QVector<Cell*> available;

    int leftIndex = getIndex(curX - 1, curY);
    if(leftIndex != -1 && !(*grid.at(leftIndex))->isVisited()) //left
    {
        available.push_back(*grid.at(leftIndex));
    }
    int rightIndex = getIndex(curX + 1, curY);
    if(rightIndex != -1 && !(*grid.at(rightIndex))->isVisited()) // right
    {
        available.push_back(*grid.at(rightIndex));
    }
    int topIndex = getIndex(curX, curY - 1);
    if(topIndex != -1 && !(*grid.at(topIndex))->isVisited()) // top
    {
        available.push_back(*grid.at(topIndex));
    }
    int bottomIndex = getIndex(curX, curY + 1);
    if(bottomIndex != -1 && !(*grid.at(bottomIndex))->isVisited())
    {
        available.push_back(*grid.at(bottomIndex));
    }

    int len = available.size();
    if(len)
    {
        return available.at(qrand() % len);
    }

    return nullptr;
}

int Maze::getIndex(int i, int j) {
    if (i < 0 || j < 0 || i > numRows - 1 || j > numCols - 1)
        return -1;

    return (i * numCols) + j;
}
