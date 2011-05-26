/*
 * AbstractModel.h
 *
 *  Created on: Feb 4, 2011
 *      Author: caleb
 */

#ifndef ABSTRACTMODEL_H_
#define ABSTRACTMODEL_H_

#include <vector>
#include <qwidget.h>
#include "resources.h"
#include "Box2D_Sandbox/Shape.h"
#include "Box2D_Sandbox/Circle.h"
#include "Box2D_Sandbox/PolygonShape.h"

typedef std::vector<Shape*> Container;
typedef Container::iterator Iter;

class AbstractModel {

protected:
	Container shapes;
public:
	AbstractModel();
	virtual ~AbstractModel();

	virtual void update() {};
	Container getShapes();
	virtual void addShape(Shape* shape, QGraphicsScene* scn);
	void deleteShape(Shape* shape, QGraphicsScene* scn);
	void deleteAllShapes();
	virtual void renderShapes(QGraphicsScene* scn) = 0;
};

#endif /* ABSTRACTMODEL_H_ */
