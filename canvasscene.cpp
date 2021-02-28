#include "canvasscene.h"

CanvasScene::CanvasScene(qreal x, qreal y, qreal width, qreal height, QObject *parent)
    : QGraphicsScene(x, y, width, height, parent)
{
}
void CanvasScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF pos = event->scenePos();
    addRect(pos.x(), pos.y(), 3, 3, QPen(), QBrush(Qt::black));
}
