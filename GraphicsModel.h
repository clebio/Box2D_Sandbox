/*
 * GraphicsModel.h
 *
 *  Created on: Feb 4, 2011
 *      Author: caleb
 */

#ifndef GRAPHICSMODEL_H_
#define GRAPHICSMODEL_H_

#include <qgraphicsview.h>
#include "AbstractModel.h"
#include "qstyleoption.h"
#include "KittyCircle.h"

class GraphicsModel: public AbstractModel {

protected:
	QGraphicsView *outputView;

public:
	GraphicsModel(QGraphicsView *view);
	virtual ~GraphicsModel();
	void update();
	void addShape(Shape* shape, QGraphicsScene* scn);
	void deleteShape(Shape* shape, QGraphicsScene* scn);
	void renderShapes(QGraphicsScene* scn);
};

#endif /* GRAPHICSMODEL_H_ */
