#ifndef FIGURE_H
#define FIGURE_H

#define PI 3.14

#include <QGraphicsItem>
#include <QTimer>
#include <QGraphicsItemAnimation>
#include <math.h>
#include <QPainter>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>

class Figure : public QGraphicsItem
{
    int goalX = 0, goalY = 0, goalRotation = 0;
    float goalScale = 1.0;
    QPointF mousePrevPos = QPointF(0, 0);
public:
    Figure(QGraphicsItem *parent = nullptr);
    void transform(int deg);
    void scale(qreal factor);
    float scale();
    void setPos(qreal x, qreal y);

    void setGoalCoords(int x, int y);
    void setGoalRotation(int rotation);
    void setGoalScale(float scale);

    QPoint getGoalCoords();
    int getGoalRotation();
    float getGoalScale();

    virtual QString getArea() const = 0;
    virtual QString getRadius() const = 0;
    virtual QString getPerimeter() const = 0;
    virtual QList<QString> getWidthAndHeight() const = 0;
    virtual void dragingHandler(int x, int y) = 0;

    void mouseMoveEvent(QMouseEvent *event);
};



#endif // FIGURE_H
