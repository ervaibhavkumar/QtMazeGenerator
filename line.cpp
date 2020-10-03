#include "line.h"

#include <QPainter>

Line::Line(QPoint start, QPoint end, QColor color, QGraphicsItem *parent)
    : QGraphicsItem(parent),
      startPoint(start),
      endPoint(end),
      circleColor(color)
{

}

Line::Line(const Line &line) {
    this->startPoint = line.getStartPoint();
    this->endPoint = line.getEndPoint();
    this->circleColor = line.getColor();
//    update();
}

QRectF Line::boundingRect() const {
    return QRectF(startPoint, endPoint);
}

void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(QPen(circleColor, 2));
    painter->setBrush(QColor(circleColor));
    painter->drawLine(startPoint.x(), startPoint.y(), endPoint.x(), endPoint.y());
}

