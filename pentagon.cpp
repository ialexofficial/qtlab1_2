#include "pentagon.h"

Pentagon::Pentagon(qreal x, qreal y, qreal radius, QGraphicsItem *parent)
    : Figure(parent)
    , coorX(x)
    , coorY(y)
    , radius(radius)
{
    setTransformOriginPoint(x, y);
    setGoalCoords(x, y);
}
void Pentagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    const QPoint points[5] = {
        QPoint((int) (coorX + radius * cos(54 * PI / 180)),
            (int) (coorY + radius * sin(54 * PI / 180))
        ),
        QPoint((int) (coorX + radius * cos(126 * PI / 180)),
            (int) (coorY + radius * sin(126 * PI / 180))
        ),
        QPoint((int) (coorX + radius * cos(198 * PI / 180)),
            (int) (coorY + radius * sin(198 * PI / 180))
        ),
        QPoint((int) (coorX + radius * cos(270 * PI / 180)),
            (int) (coorY + radius * sin(270 * PI / 180))
        ),
        QPoint((int) (coorX + radius * cos(342 * PI / 180)),
            (int) (coorY + radius * sin(342 * PI / 180))
        ),
    };
    painter->drawPolygon(points, 5);
}
QRectF Pentagon::boundingRect() const
{
    return QRectF(coorX - radius, coorY - radius, radius * 2, radius * 2);
}
QString Pentagon::getArea() const
{
    return QString::number(5 / 2 * pow(radius, 2) * sin(2 * PI / 5));
}
QString Pentagon::getRadius() const
{
    return QString::number(abs(radius));
}
QString Pentagon::getPerimeter() const
{
    return QString::number(abs(5 * sqrt((5 - sqrt(5)) / 2) * radius));
}
QList<QString> Pentagon::getWidthAndHeight() const
{
    return QList<QString>({QString("None"), QString("None")});
}
void Pentagon::dragingHandler(int x, int y)
{
    radius += abs(x) > abs(y) ? x : y;
    update();
}
