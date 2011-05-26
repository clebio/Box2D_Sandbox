/*
 * SandboxController.cpp
 *
 *  Created on: Jan 31, 2011
 *      Author: caleb
 */

#include "SandboxController.h"

SandboxController::SandboxController(QGraphicsView* gv) : graphics(gv) {
	LOG("SandboxController constructor");

	QRect bounds = gv->rect();
	  QGraphicsScene* scn = new QGraphicsScene(bounds.x(), bounds.y(), bounds.width(), bounds.height());
	  gv->setScene(scn);

//	  shapes.push_back(new Triangle);
/*	  for(Iter i = shapes.begin(); i != shapes.end(); i++)
	    (*i)->draw();
*/
}

SandboxController::~SandboxController() {
}
