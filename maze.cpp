#include "maze.h"
#include "utilities.h"

#include <QDebug>

Maze::Maze(QSize sizeOfScreen, QGraphicsView *parent)
    : QGraphicsView(parent),
      screenSize(sizeOfScreen)
{
    QGraphicsScene *scene = new QGraphicsScene();
    setScene(scene);

    scene->setSceneRect(0,0,screenSize.height() - 20, screenSize.width() - 20);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setWindowTitle("QT Maze Generaator");
    current = nullptr;
}

void Maze::CreateMaze() {
    scene()->clear();
    grid->clear();
    numRows = floor(screenSize.height() / cellSize);
    numCols = floor(screenSize.width() / cellSize);

    int r = Utilities::random(0, 100);
    int g = Utilities::random(0, 100);
    int b = Utilities::random(0, 100);
    setBackgroundBrush(QBrush(QColor(r, g, b)));

    for (auto i = 0; i < numRows; i++) {
        for (auto j = 0; j < numCols; j++) {
            Cell *newSize = new Cell(i, j, cellSize, QColor(255 - r, 255 - g, 255 - b));
            grid->push_back(*newSize);
        }
    }

//    int r = 255;
//    int g = 0;
//    int b = 0;
//    setBackgroundBrush(QBrush(QColor(r, g, b)));
//    qDebug() << "back " << backgroundBrush();

//    for (auto i = 0; i < numRows; i++) {
//        for (auto j = 0; j < numCols; j++) {
//            Cell *newSize = new Cell(i, j, cellSize, QColor(0, 255, 0));
//            grid->push_back(*newSize);
//        }
//    }

    int index = Utilities::random(1, grid->size());
    current = &grid->at(index);

    stack = nullptr;
    scene()->addItem(current);
    current->Highlight();

    QMap<QString, bool> map = current->getWalls();

    for (auto i = map.keyBegin(); i != map.keyEnd(); i++) {
        if (current->getValueForTheKey(*i)) {
            if (*i == "Top") {
                current->getLineAtIndex(0, scene());
            }
            else if (*i == "Bottom") {
                current->getLineAtIndex(1, scene());
            }
            else if (*i == "Left") {
                current->getLineAtIndex(2, scene());
            }
            else if (*i == "Right") {
                current->getLineAtIndex(3, scene());
            }
        }
    }
    scene()->update();
}

QColor Maze::getBackGroundColor() {
    int r = Utilities::random(0, 255);
    int g = Utilities::random(0, 255);
    int b = Utilities::random(0, 255);
    return QColor(r, g, b);
}

int Maze::getCellBackground(int hue, int hueShift) {
//    int r = color.red() + hueShift;
//    while (r > 255) {
//        r -= 255;
//    }
//    while (r < 0) {
//        r += 255;
//    }
//    color.setRed(255 - color.red());

//    int g = color.green() + hueShift;
//    while (g > 255) {
//        g -= 255;
//    }
//    while (g < 0) {
//        g += 255;
//    }
//    color.setGreen(255 - color.green());

//    int b = color.blue() + hueShift;
//    while (b > 255) {
//        b -= 255;
//    }
//    while (b < 0) {
//        b += 255;
//    }
//    color.setBlue(255 - color.blue());

    hue += hueShift;
    while (hue >= 360) {
        hue -= 360;
    }

    return hue;
}





