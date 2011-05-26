/*
 * KittyCircle.h
 *
 *  Created on: Feb 10, 2011
 *      Author: caleb
 */

#ifndef KITTYCIRCLE_H_
#define KITTYCIRCLE_H_

#include "qgraphicsitem.h"
#include "qpainter.h"

class KittyCircle : public QGraphicsEllipseItem {
public:
	KittyCircle();
	KittyCircle(QRectF size);
	virtual ~KittyCircle();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
};

#endif /* KITTYCIRCLE_H_ */
