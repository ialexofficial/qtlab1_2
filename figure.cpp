#include <figure.h>

Figure::Figure(QGraphicsItem *parent)
    : QGraphicsItem(parent)
{
}
void Figure::setGoalCoords(int x, int y)
{
    goalX = x;
    goalY = y;
}
void Figure::setGoalRotation(int rotation)
{
    goalRotation = rotation;
}
void Figure::setGoalScale(float scale)
{
    goalScale = scale;
}
QPoint Figure::getGoalCoords()
{
    return QPoint(goalX, goalY);
}
int Figure::getGoalRotation()
{
    return goalRotation;
}
float Figure::getGoalScale()
{
    return goalScale;
}
float Figure::scale()
{
    return QGraphicsItem::scale();
}
void Figure::setPos(qreal x, qreal y)
{
    setGoalCoords(x, y);
    QGraphicsItem::setPos(x, y);
}
void Figure::mouseMoveEvent(QMouseEvent *event)
{
    QPointF currentPos = mapFromScene(event->localPos());
    dragingHandler(currentPos.x() - mousePrevPos.x(), currentPos.y() - mousePrevPos.y());
    mousePrevPos = currentPos;
}
