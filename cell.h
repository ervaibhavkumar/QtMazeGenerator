#pragma once

#include <QGraphicsLineItem>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsRectItem>


class Cell
{
private:
    bool visited;
    int idx;
    int idy;
    QColor cellColor;
    QColor wallColor;
public:
    int cellSize;
    QGraphicsLineItem *top; //up
    QGraphicsLineItem *right; //right
    QGraphicsLineItem *bottom; //down
    QGraphicsLineItem *left; //left
    QGraphicsRectItem *rect;


    Cell(int x, int y, int size, QColor color, QColor wall, QGraphicsScene *s);
    bool isVisited() const;
    void setVisited(bool state);
    int getRowIndex() const { return idx; }
    int getColIndex() const { return idy; }
    void Show();
    void Hide();
};
