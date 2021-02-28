#include "circle.h"

Circle::Circle(qreal x, qreal y, qreal radius, QGraphicsItem *parent)
    : Figure(parent)
    , coorX(x)
    , coorY(y)
    , radius(radius)
{
    setTransformOriginPoint(x, y);
    setGoalCoords(x, y);
}
void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawEllipse(coorX - radius, coorY - radius, radius * 2, radius * 2);
}
QRectF Circle::boundingRect() const
{
    return QRectF(coorX - radius, coorY - radius, radius * 2, radius * 2);
}
QString Circle::getArea() const
{
    return QString::number(PI * pow(radius, 2));
}
QString Circle::getRadius() const
{
    return QString::number(abs(radius));
}
QString Circle::getPerimeter() const
{
    return QString::number(abs(2*PI*radius));
}
QList<QString> Circle::getWidthAndHeight() const
{
    return QList<QString>({QString("None"), QString("None")});
}
void Circle::dragingHandler(int x, int y)
{
    radius += abs(x) > abs(y) ? x : y;
    update();
}
