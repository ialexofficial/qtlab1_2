#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , timer(this)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    view = ui->view;
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->canvasView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->canvasView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene = new QGraphicsScene(0, 0, 500, 500, this);
    canvas = new CanvasScene(0, 0, 231, 171, this);

    view->setScene(scene);
    ui->canvasView->setScene(canvas);

    timer.start(1000/60);
    connect(&timer, SIGNAL(timeout()), this, SLOT(advance()));
}

void MainWindow::addItem(Figure *item)
{
    scene->addItem(item);
    view->addFigure(item);
}
MainWindow::~MainWindow()
{
    delete scene;
    delete ui;
}
void MainWindow::advance()
{
    Figure* selected_figure = view->getSelectedFigure();
    ui->areaLabel->setText(selected_figure->getArea());
    ui->radiusLabel->setText(selected_figure->getRadius());
    ui->perimeterLabel->setText(selected_figure->getPerimeter());
    ui->widthLabel->setText(selected_figure->getWidthAndHeight()[0]);
    ui->heightLabel->setText(selected_figure->getWidthAndHeight()[1]);


    QList<Figure*> figures = view->getFigures();
    for(int i = 0; i < figures.size(); i++)
    {
        Figure* selected_figure = figures[i];
        int speedX = 0, speedY = 0;
        QPointF position = selected_figure->pos();
        QPoint goalPos = selected_figure->getGoalCoords();
        int goalRotation = selected_figure->getGoalRotation();
        float goalScale = selected_figure->getGoalScale();
        int rotation = selected_figure->rotation();
        float scale = selected_figure->scale();

        if(goalPos.x() - position.x() > 0)
            speedX = 1;
        else if(goalPos.x() - position.x() < 0)
            speedX = -1;
        if(goalPos.y() - position.y() > 0)
            speedY = 1;
        else if(goalPos.y() - position.y() < 0)
            speedY = -1;
        selected_figure->moveBy(speedX, speedY);

        if(goalRotation > rotation) {
            selected_figure->setRotation(rotation + 1);
        }
        else if(goalRotation < rotation) {
            selected_figure->setRotation(rotation - 1);
        }

        if(goalScale - scale > 0.0009) {
            selected_figure->setScale(scale + 0.01);
        }
        else if(goalScale - scale < -0.0009) {
            selected_figure->setScale(scale - 0.01);
        }
    }
    scene->update();
}


void MainWindow::on_moveToButton_clicked()
{
    view->getSelectedFigure()->setGoalCoords(ui->xPos->value(), ui->yPos->value());
}


void MainWindow::on_rotateButton_clicked()
{
    view->getSelectedFigure()->setGoalRotation(ui->rotation->value());
}

void MainWindow::on_scaleButton_clicked()
{
    view->getSelectedFigure()->setGoalScale(ui->coeff->value());
}

void MainWindow::on_clearButton_clicked()
{
    ui->canvasView->scene()->clear();
}
