/*
 * GraphicsModel.cpp
 *
 *  Created on: Feb 4, 2011
 *      Author: caleb
 */

#include "GraphicsModel.h"

GraphicsModel::GraphicsModel(QGraphicsView* view) : outputView(view) {
	view->setAlignment(Qt::AlignTop | Qt::AlignLeft);
	QRect bounds = view->rect();
	QGraphicsScene* scn = new QGraphicsScene(bounds.x(), bounds.y(), bounds.width(), bounds.height());
	view->setScene(scn);
}

void GraphicsModel::renderShapes(QGraphicsScene* scn) {
	// moved to addShape();
}

GraphicsModel::~GraphicsModel() {
	// TODO Auto-generated destructor stub
}

void GraphicsModel::update() {
	for (Iter i = shapes.begin(); i != shapes.end(); i++) {
		Shape* shape = (*i);
		QGraphicsItem* item = shape->getGraphic();
		Point p = shape->location();
		QPointF pointf;
		pointf.setX(p.x() - shape->width()/2);
		pointf.setY(p.y() - shape->height()/2);
		item->setPos(pointf);
		item->setRotation(shape->rotation());
	}
}

void GraphicsModel::addShape(Shape* shape, QGraphicsScene* scn) {
	AbstractModel::addShape(shape, scn);
	QGraphicsItem* item;
	Point p = shape->location();
	QRect rect = QRect(0, 0, shape->width(), shape->height());
	if (shape->name() == "circle") {
		item = new QGraphicsEllipseItem(rect);

		// add a line to see rotation
		QGraphicsItem* dLine = new QGraphicsLineItem(0, 0, shape->width()/3, shape->height()/3, item, 0);
		dLine->setPos(shape->width()/2, shape->height()/2);

//			item = new KittyCircle(rect);
		item->setTransformOriginPoint(shape->width()/2, shape->height()/2);
	} else if (shape->name() == "square") {
		item = new QGraphicsRectItem(rect);
		item->setTransformOriginPoint(shape->width()/2, shape->height()/2);
	} else if (shape->name() == "polygon") {
		vector<Point> vertices = ((PolygonShape*)shape)->vertices();
		vector<Point>::iterator iter;
		QPolygonF qpoly;
		for (iter = vertices.begin(); iter != vertices.end(); iter++) {
			Point p = (*iter);
			qpoly << QPoint(p.x(), p.y());
		}
		item = new QGraphicsPolygonItem(qpoly);
		item->translate(shape->width()/2, shape->height()/2 );
		item->setRotation(shape->rotation());
	}
	shape->setGraphic(item);
	scn->addItem(item);

}

void GraphicsModel::deleteShape(Shape* shape, QGraphicsScene* scn) {
	scn->removeItem(shape->getGraphic());
	AbstractModel::deleteShape(shape, scn);
}

