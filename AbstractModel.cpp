/*
 * AbstractModel.cpp
 *
 *  Created on: Feb 4, 2011
 *      Author: caleb
 */

#include "AbstractModel.h"

AbstractModel::AbstractModel() {
}

AbstractModel::~AbstractModel() {
	// TODO Auto-generated destructor stub
}


Container AbstractModel::getShapes() {
	return shapes;
}

void AbstractModel::addShape(Shape* shape, QGraphicsScene* scn) {
	shapes.push_back(shape);
}

void AbstractModel::deleteShape(Shape* shape, QGraphicsScene* scn) {
	for (Iter i = shapes.begin(); i != shapes.end(); ) {
		if ((*i) == shape)
			i = shapes.erase(i);
		else
			i++;
	}
}
void AbstractModel::deleteAllShapes() {
	shapes.clear();
}
