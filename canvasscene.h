#ifndef CANVASSCENE_H
#define CANVASSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QColor>

class CanvasScene : public QGraphicsScene
{
public:
    CanvasScene(qreal x, qreal y, qreal width, qreal height, QObject *parent = nullptr);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};

#endif // CANVASSCENE_H
