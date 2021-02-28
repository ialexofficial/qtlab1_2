#include "rectangle.h"

Rectangle::Rectangle(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent)
    : Figure(parent)
    , coorX(x)
    , coorY(y)
    , width(width)
    , height(height)
{
    setTransformOriginPoint(x, y);
    setGoalCoords(x, y);
}
void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawRect(coorX - width / 2, coorY - height / 2, width, height);
}
QRectF Rectangle::boundingRect() const
{
    return QRectF(coorX - width / 2, coorY - height / 2, width, height);
}
QString Rectangle::getArea() const
{
    return QString::number(abs(width * height));
}
QString Rectangle::getRadius() const
{
    return QString("None");
}
QString Rectangle::getPerimeter() const
{
    return QString::number(abs(width * 2 + height * 2));
}
QList<QString> Rectangle::getWidthAndHeight() const
{
    return QList<QString>({QString::number(abs(width)), QString::number(abs(height))});
}
void Rectangle::dragingHandler(int x, int y)
{
    width += x;
    height += y;
    update();
}
