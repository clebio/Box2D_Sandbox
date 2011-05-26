/*
 * Box2DView.cpp
 *
 *  Created on: Feb 7, 2011
 *      Author: caleb
 */

#include "box2dview.h"

Box2DView::Box2DView() {
	// TODO Auto-generated constructor stub

}

Box2DView::Box2DView(QWidget* widget) : QGraphicsView(widget) {}

Box2DView::~Box2DView() {
	// TODO Auto-generated destructor stub
}

void Box2DView::mousePressEvent(QMouseEvent * event ) {
	last = event->pos();
	emit mousePress( event->pos() );
}

void Box2DView::mouseReleaseEvent ( QMouseEvent * event ) {
	emit mouseRelease( event->pos() );
}

void Box2DView::focusInEvent ( QFocusEvent * event ) {}
void Box2DView::focusOutEvent ( QFocusEvent * event ) {}
void Box2DView::keyPressEvent ( QKeyEvent * event ) {}
void Box2DView::keyReleaseEvent ( QKeyEvent * event ) {}
void Box2DView::mouseDoubleClickEvent ( QMouseEvent * event ) {}

void Box2DView::mouseMoveEvent ( QMouseEvent * event ) {
	emit mouseMove(event->pos());
//	last = curr;
}
void Box2DView::wheelEvent ( QWheelEvent * event ) {}

void Box2DView::resizeEvent ( QResizeEvent * event ) {
	scene()->setSceneRect(QRect(0, 0, event->size().width(), event->size().height()));
}
