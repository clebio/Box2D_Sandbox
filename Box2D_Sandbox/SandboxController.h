/*
 * SandboxController.h
 *
 *  Created on: Jan 31, 2011
 *      Author: caleb
 */

#ifndef SANDBOXCONTROLLER_H_
#define SANDBOXCONTROLLER_H_

#include <QtGui>

#include "resources.h"
#include "Shape.h"
#include "Circle.h"
#include "Square.h"

class SandboxController {
	QGraphicsView* graphics;
public:
	SandboxController(QGraphicsView* gv = 0);
	virtual ~SandboxController();
};


#endif /* SANDBOXCONTROLLER_H_ */
