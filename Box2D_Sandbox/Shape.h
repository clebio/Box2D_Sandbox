/*
 * Shape.h
 *
 *  Created on: Jan 31, 2011
 *      Author: caleb
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#include <qgraphicsitem.h>
#include <vector>
#include "resources.h"

class Shape {
protected:
	Point shapeLoc;
	int shapeWidth;
	int shapeHeight;
	int shapeMass;
	float shapeRotation;
	float shapeDensity;
	float shapeFriction;
	float shapeRestitution;
	QGraphicsItem* graphic;
	bool isaWall;
public:
	Shape();
	Shape(Point location, int width = 0, int height = 0, float rotation = 0, float density = 1.0f, float friction =0.3f, float restitution = (qrand() % 10 )/ 10.0f);
	virtual ~Shape();
	virtual void draw();
	virtual QString name() { return "null"; };

	Point location() const { return shapeLoc; };
	void location(Point location) {
		shapeLoc = location;
	};

	int mass() const { return shapeMass; };
	void mass(int mass) { this->shapeMass = mass; };
	int width() const { return shapeWidth; };
	void width(int width) { this->shapeWidth = width; };
	int height() const { return shapeHeight; };
	void height(int height) { this->shapeHeight = height;  };
	float rotation() const { return shapeRotation; };
	void rotation(float rotation) { this->shapeRotation = rotation;  };
	float density() const { return shapeDensity; };
	void density(float density) { this->shapeDensity = density;  };
	float friction() const { return shapeFriction; };
	void friction(float friction) { this->shapeFriction = friction;  };
	float restitution() const { return shapeRestitution; };
	void restitution(float restitution) { this->shapeRestitution = restitution;  };
	bool wall() const { return isaWall; };
	void wall(bool isWall) { this->isaWall = isWall;  };
	void bounds(QRect rect) {
		shapeLoc = Point(rect.x(), rect.y());
		shapeWidth = rect.width();
		shapeHeight = rect.height();
	};
	QRect bounds() { return QRect(shapeLoc.x(), shapeLoc.y(), shapeWidth, shapeHeight); };

	QGraphicsItem* getGraphic();
	void setGraphic(QGraphicsItem* graphic);
};

#endif /* SHAPE_H_ */
