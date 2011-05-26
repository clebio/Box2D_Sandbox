/*
 * Circle.h
 *
 *  Created on: Jan 31, 2011
 *      Author: caleb
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_

#include <qpainter.h>
#include "Shape.h"

class Circle: public Shape {
public:
	Circle();
	Circle(Point location, int width, int height)
	: Shape(location, width, height) {};
	Circle(Point location, int width, int height, float rotation, float density, float friction, float restitution)
	: Shape(location, width, height, rotation, density, friction, restitution) {};
	virtual ~Circle();
	void draw();
	QString name();
};

#endif /* CIRCLE_H_ */
