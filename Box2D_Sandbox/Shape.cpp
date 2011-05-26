/*
 * Shape.cpp
 *
 *  Created on: Jan 31, 2011
 *      Author: caleb
 */

#include "Shape.h"

Shape::Shape() {
	shapeLoc = Point(0, 0);
	shapeWidth = 0;
	shapeHeight = 0;
	shapeMass = 1;
	isaWall = false;
}

Shape::Shape(Point location, int width, int height, float rotation, float density, float friction, float restitution) :
				shapeLoc(location), shapeWidth(width), shapeHeight(height), shapeRotation(rotation), shapeDensity(density),
				shapeFriction(friction), shapeRestitution(restitution), isaWall(false) {
}

Shape::~Shape() {
	LOG("Shape destructor");
}

QGraphicsItem* Shape::getGraphic() {
	return graphic;
}

void Shape::setGraphic(QGraphicsItem* graphic) {
	this->graphic = graphic;
}

void Shape::draw() {
	LOG("Shape::draw()");
}
