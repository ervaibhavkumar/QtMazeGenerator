#include "cell.h"
#include <QPainter>

Cell::Cell(int x, int y, int size, QColor color, QColor wall, QGraphicsScene *scene)
{
    visited = false;
    idx = x;
    idy = y;
    cellSize = size;
    cellColor = color;
    wallColor = wall;
    x *= size;
    y *= size;

    rect = new QGraphicsRectItem(x,y,size,size); //for marking
    rect->setBrush(QBrush(cellColor, Qt::SolidPattern));
    rect->setPen(Qt::NoPen);
    rect->hide();

    top = new QGraphicsLineItem (x, y, x+size, y);
    top->setPen(wallColor);
    right = new QGraphicsLineItem (x+size, y, x+size, y+size);
    right->setPen(wallColor);
    bottom = new QGraphicsLineItem (x, y+size, x+size, y+size);
    bottom->setPen(wallColor);
    left = new QGraphicsLineItem (x, y, x, y+size);
    left->setPen(wallColor);

    scene->addItem(top);
    scene->addItem(bottom);
    scene->addItem(left);
    scene->addItem(right);
    scene->addItem(rect);
}

bool Cell::isVisited() const
{
    return visited;
}

void Cell::setVisited(bool state)
{
    visited = state;
}

void Cell::Show()
{
    rect->show();
}

void Cell::Hide()
{
    rect->hide();
}

