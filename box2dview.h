/*
 * box2dview.h
 *
 *  Created on: Feb 7, 2011
 *      Author: caleb
 */

#ifndef BOX2DVIEW_H_
#define BOX2DVIEW_H_

#include "qobject.h"
#include "qgraphicsview.h"
#include "qgraphicsitem.h"
#include "qstyleoption.h"
#include "qevent.h"
#include "resources.h"

class Box2DView : public QGraphicsView {
	Q_OBJECT
	QPoint last;
public:
	Box2DView();
	Box2DView(QWidget* widget = 0);
	virtual ~Box2DView();

	virtual void focusInEvent ( QFocusEvent * event );
	virtual void focusOutEvent ( QFocusEvent * event );
	virtual void keyPressEvent ( QKeyEvent * event );
	virtual void keyReleaseEvent ( QKeyEvent * event );
	virtual void mouseDoubleClickEvent ( QMouseEvent * event );
	virtual void mouseMoveEvent ( QMouseEvent * event );
	virtual void mousePressEvent ( QMouseEvent * event );
	virtual void mouseReleaseEvent ( QMouseEvent * event );
	virtual void wheelEvent ( QWheelEvent * event );
	void resizeEvent ( QResizeEvent * event );

signals:
	void mousePress( QPoint location );
	void mouseRelease( QPoint location );
	void mouseMove( QPoint impulse);
};

#endif /* BOX2DVIEW_H_ */
