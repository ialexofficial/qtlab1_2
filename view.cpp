#include "view.h"

View::View(QWidget *widget)
    : QGraphicsView(widget)
{
}
void View::addFigure(Figure *figure)
{
    figures.append(figure);
    selected_figure = figure;
}
Figure* View::getSelectedFigure()
{
    return selected_figure;
}
QList<Figure*> View::getFigures()
{
    return figures;
}
void View::mousePressEvent(QMouseEvent *event)
{
    QPointF pos = event->localPos();
    if(seeker == nullptr) {
        seeker = scene()->addRect(0, 0, 5, 5);
        seeker->hide();
    }
    seeker->setPos(pos.x() - 2.5, pos.y() - 2.5);
    for(int i = 0; i < figures.size(); i++) {
        if(seeker->collidesWithItem(figures[i])) {
            selected_figure = figures[i];
            break;
        }
    }
}
void View::mouseDoubleClickEvent(QMouseEvent *event)
{
    QPointF pos = event->localPos();
    selected_figure->setTransformOriginPoint(selected_figure->mapFromScene(pos));
}
void View::mouseReleaseEvent(QMouseEvent *event)
{
}
void View::mouseMoveEvent(QMouseEvent *event)
{
    selected_figure->mouseMoveEvent(event);
}
