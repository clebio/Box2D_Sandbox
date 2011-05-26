/*
 * KittyCircle.cpp
 *
 *  Created on: Feb 10, 2011
 *      Author: caleb
 */

#include "KittyCircle.h"

KittyCircle::KittyCircle() {
	// TODO Auto-generated constructor stub

}

KittyCircle::KittyCircle(QRectF size) : QGraphicsEllipseItem(size) {}


KittyCircle::~KittyCircle() {
	// TODO Auto-generated destructor stub
}



QRectF KittyCircle::boundingRect() const {
	return rect();
}

void KittyCircle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
	QPixmap pm("resources/kitty-head.png");
	painter->scale(rect().width()/pm.size().width(), rect().height() / pm.size().height());
	painter->drawPixmap(QPoint(0, 0), pm);
}
