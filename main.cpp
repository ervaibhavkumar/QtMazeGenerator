#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QScreen>

#include "maze.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Maze *game = new Maze(QSize(800,800));
    game->show();
    return a.exec();
}
