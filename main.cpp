#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QScreen>

#include "maze.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Maze *game = new Maze(QSize(1080, 1920));
    game->showMaximized();
    game->CreateMaze();
    return a.exec();
}
