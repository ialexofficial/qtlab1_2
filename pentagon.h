#ifndef PENTAGON_H
#define PENTAGON_H

#include "figure.h"

class Pentagon : public Figure
{
    qreal coorX, coorY, radius;

public:
    Pentagon(qreal x, qreal y, qreal radius, QGraphicsItem *parent = nullptr);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    QString getArea() const;
    QString getRadius() const;
    QString getPerimeter() const;
    QList<QString> getWidthAndHeight() const;
    void dragingHandler(int x, int y);
};

#endif // PENTAGON_H
