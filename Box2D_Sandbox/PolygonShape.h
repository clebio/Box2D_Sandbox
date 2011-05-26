/*
 * PolygonShape.h
 *
 *  Created on: Feb 6, 2011
 *      Author: caleb
 */

#ifndef POLYGONSHAPE_H_
#define POLYGONSHAPE_H_

#include "Shape.h"

typedef std::vector<Point> PointContainer;
typedef PointContainer::iterator PointIter;

class PolygonShape: public Shape {
	PointContainer points;
public:
	PolygonShape();
	PolygonShape(Point location, int width, int height)
	: Shape(location, width, height, 0, 0, 0, 0) {};
	PolygonShape(Point location, int width, int height, float rotation)
	: Shape(location, width, height, rotation, 0, 0, 0) {};
	PolygonShape(Point location, int width, int height, float rotation, float density, float friction, float restitution)
	: Shape(location, width, height, rotation, density, friction, restitution) {};
	virtual ~PolygonShape();
	QString name();
	PointContainer vertices() { return points; };
	void setVertices(PointContainer vertices) { points = vertices; };
};

#endif /* POLYGONSHAPE_H_ */
