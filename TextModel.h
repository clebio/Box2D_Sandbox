/*
 * TextModel.h
 *
 *  Created on: Feb 4, 2011
 *      Author: caleb
 */

#ifndef TEXTMODEL_H_
#define TEXTMODEL_H_

#include <qtextedit.h>
#include "AbstractModel.h"
#include "Box2D_Sandbox/Shape.h"
#include "Box2D_Sandbox/Circle.h"

class TextModel: public AbstractModel {
protected:
	QTextEdit* text;
public:
	TextModel(QTextEdit* textEdit);
	~TextModel();
	void update();
	void addShape(Shape* shape, QGraphicsScene* scn);
};

#endif /* TEXTMODEL_H_ */
