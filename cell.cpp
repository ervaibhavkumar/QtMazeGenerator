#include "cell.h"
#include "line.h"

#include <QDebug>
#include <QGraphicsScene>

Cell::Cell(int row, int col, int size, QColor color, QGraphicsWidget *parent)
    : QGraphicsWidget(parent),
      rowIndex(row),
      colIndex(col),
      backgroundColor(color),
      cellSize(size)
{
    walls["Top"] = true;
    walls["Bottom"] = true;
    walls["Right"] = true;
    walls["Left"] = true;
    setVisited(false);

    CreateWalls();
}

Cell::Cell(const Cell &other) {
    this->setVisited(other.getVisited());
    this->setRowIndex(other.getRowIndex());
    this->setColIndex(other.getColIndex());
    this->setCellSize(other.getCellSize());
    this->setWalls(other.getWalls());
    this->setBackgroundColor(other.getBackGroundColor());
    this->setTopWall(other.getTopWall());
    this->setBottomWall(other.getBottomWall());
    this->setLeftWall(other.getLeftWall());
    this->setRightWall(other.getRightWall());
}

void Cell::CreateWalls() {
    const int x = this->rowIndex * cellSize;
    const int y = this->colIndex * cellSize;
    // Top
    top = new Line(QPoint(x,y), QPoint(x + cellSize, y), QColor(255,0,0));
    // Bottom
    bottom = new Line(QPoint(x + cellSize, y + cellSize), QPoint(x , y + cellSize), QColor(255,0,0));
    // Left
    left = new Line(QPoint(x, y + cellSize), QPoint(x, y), QColor(255,0,0));
    // Right
    right = new Line(QPoint(x + cellSize, y), QPoint(x + cellSize, y + cellSize), QColor(255,0,0));
}

void Cell::getLineAtIndex(int index, QGraphicsScene *scene) {
    qDebug() << "index " << index;
    if (index == 0) {
        scene->addItem(top);
    }
    else if (index == 1) {
        scene->addItem(bottom);
    }
    else if (index == 2) {
        scene->addItem(left);
    }
    else if (index == 3) {
        scene->addItem(right);
    }
}

bool Cell::getValueForTheKey(QString str) {
    return walls[str];
}

void Cell::setVisited(bool state) {
    visited = state;
}

void Cell::setRowIndex(int index) {
    rowIndex = index;
}

void Cell::setColIndex(int index) {
    colIndex = index;
}

void Cell::setWalls(QMap<QString, bool> map) {
    walls = map;
}

void Cell::setCellSize(int size) {
    cellSize = size;
}

void Cell::setBackgroundColor(QColor color) {
    backgroundColor = color;
}

void Cell::setTopWall(Line *wall) {
    top = wall;
}

void Cell::setBottomWall(Line *wall) {
    bottom = wall;
}

void Cell::setLeftWall(Line *wall) {
    left = wall;
}

void Cell::setRightWall(Line *wall) {
    right = wall;
}

void Cell::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    int x = rowIndex * cellSize;
    int y = colIndex * cellSize;

    painter->setPen(QPen(backgroundColor, 3));
    painter->setBrush(QColor(backgroundColor));

//    painter->eraseRect(rect());
//    painter->drawRect(rect());
//    painter->drawLine(QPointF(100, 100), QPointF(150,150));


    painter->drawRect(x, y, cellSize, cellSize);
    qDebug() << "rect " << x << " " << y << " " << cellSize;

//    painter->drawLine(100,150,200,250);
//    painter->setPen(QPen(QColor(0,0,255), 3));
//    painter->setBrush(QColor(0,0,255));
//    painter->drawRect(x, y, cellSize, 0);
//    qDebug() << "Test top " << top->getStartPoint();
//    painter->drawLine(100,150,200,250);

    // Top
//    top = new Line(QPoint(x,y), QPoint(x + cellSize, y), QColor(255,0,0));
//    painter->drawLine(x, y, x + cellSize, y);
}

void Cell::Highlight() {
    update();
}
