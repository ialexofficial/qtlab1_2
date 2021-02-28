#include "triangle.h"

Triangle::Triangle(qreal x, qreal y, qreal radius, QGraphicsItem *parent)
    : Figure(parent)
    , coorX(x)
    , coorY(y)
    , radius(radius)
{
    setTransformOriginPoint(x, y);
    setGoalCoords(x, y);
}
void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    const QPoint points[3] = {
        QPoint((int) (coorX + radius * cos(30 * PI / 180)),
            (int) (coorY + radius * sin(30 * PI / 180))
        ),
        QPoint((int) (coorX + radius * cos(150 * PI / 180)),
            (int) (coorY + radius * sin(150 * PI / 180))
        ),
        QPoint((int) (coorX + radius * cos(270 * PI / 180)),
            (int) (coorY + radius * sin(270 * PI / 180))
        ),
    };
    painter->drawPolygon(points, 3);
}
QRectF Triangle::boundingRect() const
{
    return QRectF(coorX - radius, coorY - radius, radius * 2, radius * 2);
}
QString Triangle::getArea() const
{
    return QString::number(3 * sqrt(3) * pow(radius, 2) / 4);
}
QString Triangle::getRadius() const
{
    return QString::number(abs(radius));
}
QString Triangle::getPerimeter() const
{
    return QString::number(abs(3 * sqrt(3) * radius));
}
QList<QString> Triangle::getWidthAndHeight() const
{
    return QList<QString>({QString("None"), QString("None")});
}
void Triangle::dragingHandler(int x, int y)
{
    radius += abs(x) > abs(y) ? x : y;
    update();
}
