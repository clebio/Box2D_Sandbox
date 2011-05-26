/*
 * Box2DController.h
 *
 *  Created on: Feb 5, 2011
 *      Author: caleb
 */

#ifndef BOX2DCONTROLLER_H_
#define BOX2DCONTROLLER_H_

#include <map>
#include <utility>
#include "Box2D/Box2D.h"
#include "Box2D_Sandbox/Shape.h"
#include "Box2D_Sandbox/Circle.h"
#include "Box2D_Sandbox/Square.h"
#include "Box2D_Sandbox/PolygonShape.h"

static const float G = 9.81;
static const int velocityIterations = 10;
static const int positionIterations = 10;

typedef map<Shape*, b2Body*> BodyMap;
typedef BodyMap::iterator BodyIter;

class Box2DController {
	int timerId;
	b2World *world;
	b2Body *groundBody;
	BodyMap bodyMap;
public:
	Box2DController();
	virtual ~Box2DController();
	void createWorld();
	void addObject(Shape* shape);
	void update(float timeStep);
	void updateShape(Shape* shape);
	void removeBody(Shape* shape);
	void alterBody(Shape* shape);
	QPoint getCOM(Shape* shape);
	void applyImpulse(Shape* shape, QPoint impulse);
};

#endif /* BOX2DCONTROLLER_H_ */
