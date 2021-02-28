#ifndef CIRCLE_H
#define CIRCLE_H

#include "figure.h"

class Circle : public Figure
{
    qreal coorX, coorY, radius;
public:
    Circle(qreal x, qreal y, qreal radius, QGraphicsItem *parent = nullptr);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    QString getArea() const;
    QString getRadius() const;
    QString getPerimeter() const;
    QList<QString> getWidthAndHeight() const;
    void dragingHandler(int x, int y);
};

#endif // CIRCLE_H
