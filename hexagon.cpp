#include "hexagon.h"

Hexagon::Hexagon(qreal x, qreal y, qreal radius, QGraphicsItem *parent)
    : Figure(parent)
    , coorX(x)
    , coorY(y)
    , radius(radius)
{
    setTransformOriginPoint(x, y);
    setGoalCoords(x, y);
}
void Hexagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    const QPoint points[6] = {
        QPoint((int) (coorX + radius * cos(0 * PI / 180)),
            (int) (coorY + radius * sin(0 * PI / 180))
        ),
        QPoint((int) (coorX + radius * cos(60 * PI / 180)),
            (int) (coorY + radius * sin(60 * PI / 180))
        ),
        QPoint((int) (coorX + radius * cos(120 * PI / 180)),
            (int) (coorY + radius * sin(120 * PI / 180))
        ),
        QPoint((int) (coorX + radius * cos(180 * PI / 180)),
            (int) (coorY + radius * sin(180 * PI / 180))
        ),
        QPoint((int) (coorX + radius * cos(240 * PI / 180)),
            (int) (coorY + radius * sin(240 * PI / 180))
        ),
        QPoint((int) (coorX + radius * cos(300 * PI / 180)),
            (int) (coorY + radius * sin(300 * PI / 180))
        ),
    };
    painter->drawPolygon(points, 6);
}
QRectF Hexagon::boundingRect() const
{
    return QRectF(coorX - radius, coorY - radius, radius * 2, radius * 2);
}
QString Hexagon::getArea() const
{
    return QString::number(3 * sqrt(3) / 2 * pow(radius, 2));
}
QString Hexagon::getRadius() const
{
    return QString::number(abs(radius));
}
QString Hexagon::getPerimeter() const
{
    return QString::number(abs(6 * radius));
}
QList<QString> Hexagon::getWidthAndHeight() const
{
    return QList<QString>({QString("None"), QString("None")});
}
void Hexagon::dragingHandler(int x, int y)
{
    radius += abs(x) > abs(y) ? x : y;
    update();
}
