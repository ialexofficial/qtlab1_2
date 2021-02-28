#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"

class Rectangle : public Figure
{
    qreal coorX, coorY, width, height;

public:
    Rectangle(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = nullptr);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    QString getArea() const;
    QString getRadius() const;
    QString getPerimeter() const;
    QList<QString> getWidthAndHeight() const;
    void dragingHandler(int x, int y);
};

#endif // RECTANGLE_H
