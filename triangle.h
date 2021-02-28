#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"

class Triangle : public Figure
{
    qreal coorX, coorY, radius;

public:
    Triangle(qreal x, qreal y, qreal radius, QGraphicsItem *parent = nullptr);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    QString getArea() const;
    QString getRadius() const;
    QString getPerimeter() const;
    QList<QString> getWidthAndHeight() const;
    void dragingHandler(int x, int y);
};

#endif // TRIANGLE_H
