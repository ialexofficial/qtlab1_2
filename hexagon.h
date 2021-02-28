#ifndef HEXAGON_H
#define HEXAGON_H

#include "figure.h"

class Hexagon : public Figure
{
    qreal coorX, coorY, radius;

public:
    Hexagon(qreal x, qreal y, qreal radius, QGraphicsItem *parent = nullptr);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    QString getArea() const;
    QString getRadius() const;
    QString getPerimeter() const;
    QList<QString> getWidthAndHeight() const;
    void dragingHandler(int x, int y);
};

#endif // HEXAGON_H
