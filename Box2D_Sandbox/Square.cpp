/*
 * Square.cpp
 *
 *  Created on: Jan 31, 2011
 *      Author: caleb
 */

#include "Square.h"

Square::Square() {
	if (shapeWidth != shapeHeight)
		LOG("Square::Square: Square more like a rectangle");
}

Square::~Square() {
	LOG("Square destructor");
}

QString Square::name() {
	return QString("square");
}
