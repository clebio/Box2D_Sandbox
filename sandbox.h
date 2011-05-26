#ifndef SANDBOX_H
#define SANDBOX_H

#include <QtGui/QMainWindow>
#include <QtCore/QTimer>
#include <qdebug.h>
#include "qstyleoption.h"
#include <vector>
#include "ui_sandbox.h"
#include "resources.h"
#include "AbstractModel.h"
#include "TextModel.h"
#include "GraphicsModel.h"
#include "Box2D_Sandbox/Circle.h"
#include "Box2D_Sandbox/Square.h"
#include "Box2D_Sandbox/PolygonShape.h"
#include "Box2DController.h"
#include "box2dview.h"

typedef std::vector<AbstractModel*> ModelContainer;
typedef ModelContainer::iterator ModelIter;

typedef std::vector<Shape*> ShapeContainer;
typedef ShapeContainer::iterator ShapeIter;

static const int MOVESIZE = 10;
static const int MAXOBJS = 8; // number of dynamic objects to put into the world

class sandbox : public QMainWindow
{
    Q_OBJECT
    Ui::sandboxClass ui;
    Box2DView* view;
    ModelContainer models;
    ShapeContainer shapes;
    Box2DController* b2controller;
    QTimer* timer;
    float timestep;
    Shape* selected;
    QPoint last;
    QPoint mouseStartPt;
    QGraphicsLineItem* lineItem;

    void createObjects();
    void addShape(Shape* shape);
    void removeShape(Shape* shape);
    void linkModels();
    void setupEventLoop();
    void setupPhysics();
    void createModels();
    void clearPhysics();
    void createWalls();
    void deleteWalls();

public:
    sandbox(QWidget *parent = 0);
    ~sandbox();

public slots:
    void update();
    void resetWorld();
    void selectShape(QPoint location);
    void createObject(QPoint location);
    void unselectShape(QPoint location);
    void moveShape(QPoint impulse);
    void setRestitution(int value);
    void setDensity(int value);
    void setFriction(int value);
    void updateView( const QRectF & );
};

#endif // SANDBOX_H
