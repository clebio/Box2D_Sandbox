/*
 * Circle.cpp
 *
 *  Created on: Jan 31, 2011
 *      Author: caleb
 */

#include "Circle.h"

Circle::Circle() {
	LOG("Circle constructor");
}

Circle::~Circle() {
	LOG("Circle destructor");
}

void Circle::draw() {
		LOG("Circle draw()");
}

QString Circle::name() {
	return QString("circle");
}
