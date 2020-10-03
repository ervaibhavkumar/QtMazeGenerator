#ifndef CELL_H
#define CELL_H

#include <QPainter>
#include <QGraphicsWidget>

#include <vector>
#include <memory>
#include "line.h"

class Cell : public QGraphicsWidget
{
public:
    Cell(int row, int col, int size, QColor color, QGraphicsWidget *parent = nullptr);
    Cell(const Cell &other);

    bool getVisited() const { return visited; }
    void setVisited(bool state);

    int getRowIndex() const { return rowIndex; }
    void setRowIndex(int index);

    int getColIndex() const { return colIndex; }
    void setColIndex(int index);

    QMap<QString, bool> getWalls() const { return walls; }
    void setWalls(QMap<QString, bool> map);

    int getCellSize() const { return cellSize; }
    void setCellSize(int size);

    QColor getBackGroundColor() const { return backgroundColor; }
    void setBackgroundColor(QColor color);

    bool getValueForTheKey(QString str);
    void getLineAtIndex(int index, QGraphicsScene *scene);

    Line* getTopWall() const { return top; }
    void setTopWall(Line *wall);

    Line* getBottomWall() const { return bottom; }
    void setBottomWall(Line *wall);

    Line* getLeftWall() const { return left; }
    void setLeftWall(Line *wall);

    Line* getRightWall() const { return right; }
    void setRightWall(Line *wall);

    void Highlight();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

private:
    void CreateWalls();

    int rowIndex;
    int colIndex;
    QMap<QString, bool> walls;
    QColor backgroundColor;
    bool visited = false;
    int cellSize;
    Line *bottom = nullptr;
    Line *top = nullptr;
    Line *left = nullptr;
    Line *right = nullptr;
};

#endif // CELL_H
