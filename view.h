#ifndef VIEW_H
#define VIEW_H

#include "figure.h"
#include <QGraphicsView>
#include <QMouseEvent>

class View : public QGraphicsView
{
    Figure *selected_figure = nullptr;
    QList<Figure*> figures;
    QGraphicsRectItem *seeker = nullptr;
public:
    View(QWidget *widget = nullptr);

    void addFigure(Figure *figure);
    void mousePressEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    Figure* getSelectedFigure();
    QList<Figure*> getFigures();
};

#endif // VIEW_H
