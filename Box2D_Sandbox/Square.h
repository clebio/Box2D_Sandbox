/*
 * Square.h
 *
 *  Created on: Jan 31, 2011
 *      Author: caleb
 */

#ifndef SQUARE_H_
#define SQUARE_H_

#include "Shape.h"

class Square: public Shape {
private:
	void init();
public:
	Square();
	Square(Point location, int width, int height)
	: Shape(location, width, height, 0, 0, 0, 0) {};
	Square(Point location, int width, int height, float rotation, float density, float friction, float restitution)
	: Shape(location, width, height, rotation, density, friction, restitution) {};
	virtual ~Square();
	void draw() {
		LOG("Square draw()");
	};
	QString name();
};

#endif /* SQUARE_H_ */
