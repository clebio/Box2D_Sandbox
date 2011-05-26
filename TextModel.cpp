/*
 * TextModel.cpp
 *
 *  Created on: Feb 4, 2011
 *      Author: caleb
 */

#include "TextModel.h"

TextModel::TextModel(QTextEdit* textEdit) : text(textEdit)  {
	text->append("TextModel constructor");
}

TextModel::~TextModel() {
	  for(Iter j = shapes.begin(); j != shapes.end(); j++)
	    delete *j;
}

void TextModel::update() {
	for (Iter i = shapes.begin(); i != shapes.end(); i++) {
		text->append((*i)->name()
				+ " at "
				+ QString::number((*i)->location().x())
				+ ","
				+ QString::number((*i)->location().y())
			);
	}
}

void TextModel::addShape(Shape* shape, QGraphicsScene* scn) {
	AbstractModel::addShape(shape, scn);
}
