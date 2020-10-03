#ifndef LINE_H
#define LINE_H

#include <QGraphicsWidget>

class Line : public QGraphicsItem
{
public:
    Line(QPoint start, QPoint end, QColor color, QGraphicsItem *parent = nullptr);
    Line(const Line &line);

    QPoint getStartPoint() const { return startPoint; }
    QPoint getEndPoint() const { return endPoint; }
    QColor getColor() const { return circleColor; }

protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

private:
    QPoint startPoint;
    QPoint endPoint;
    QColor circleColor;
};
#endif // LINE_H
