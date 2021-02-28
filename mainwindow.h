#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>

#include "view.h"
#include "canvasscene.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QGraphicsScene *scene;
    CanvasScene *canvas;
    View *view;
    QTimer timer;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void addItem(Figure *item);

private slots:
    void on_moveToButton_clicked();
    void advance();

    void on_rotateButton_clicked();

    void on_scaleButton_clicked();

    void on_clearButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
