#include "mainwindow.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include "pentagon.h"
#include "hexagon.h"

#include <QApplication>
#include <QGraphicsScene>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;

    Circle circle(0, 0, 50);
    Rectangle rect(0, 0, 50, 60);
    Triangle triangl(0, 0, 50);
    Pentagon penta(0, 0, 50);
    Hexagon hexa(0, 0, 80);

    circle.setPos(50, 50);
    triangl.setPos(250, 250);
    rect.setPos(150, 400);
    penta.setPos(400, 400);
    hexa.setPos(250, 110);

    window.addItem(&circle);
    window.addItem(&rect);
    window.addItem(&triangl);
    window.addItem(&penta);
    window.addItem(&hexa);

    window.show();
    return a.exec();
}
