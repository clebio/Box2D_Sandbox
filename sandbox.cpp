#include "sandbox.h"

sandbox::sandbox(QWidget *parent)
    : QMainWindow(parent), selected(new Shape()), last(0.0, 0.0), mouseStartPt(0.0, 0.0)
{
	lineItem = new QGraphicsLineItem(QLine(QPoint(0,0), QPoint(0,0)));
	ui.setupUi(this);
	view = ui.graphicsView;
	timestep = 1.0f/30;

	connect(ui.densitySlider, SIGNAL(sliderMoved(int)), this, SLOT(setDensity(int)));
	connect(ui.restitutionSlider, SIGNAL(sliderMoved(int)), this, SLOT(setRestitution(int)));
	connect(ui.frictionSlider, SIGNAL(sliderMoved(int)), this, SLOT(setFriction(int)));
	connect(view, SIGNAL(mousePress(QPoint)), this, SLOT(selectShape(QPoint)));
	connect(view, SIGNAL(mouseRelease(QPoint)), this, SLOT(createObject(QPoint)));
	connect(view, SIGNAL(mouseRelease(QPoint)), this, SLOT(unselectShape(QPoint)));
	connect(view, SIGNAL(mouseMove(QPoint)), this, SLOT(moveShape(QPoint)));
	connect(ui.resetButton, SIGNAL(clicked()), this, SLOT(resetWorld()));

    b2controller = new Box2DController();
	createModels();
	createObjects();
	setupEventLoop();
	setupPhysics();
	connect(view->scene(), SIGNAL(sceneRectChanged( const QRectF & )),
			this, SLOT(updateView( const QRectF & )));
}

void sandbox::resetWorld() {
	view->scene()->clear();
	clearPhysics();
	deleteWalls();
	createWalls();
	createObjects();
	setupPhysics();
}

void sandbox::createObjects() {
	QRect bRect = view->rect();

	// create a few objects in the world
	for (int i = 1; i < MAXOBJS; i++) {
		int rad = 10 + qrand() % 40; // radius
		double width = 10 + qrand() % (bRect.width() - 20);
		double height = 10 + qrand() % (bRect.height() - 20);
		Circle* c = new Circle(Point(width, height), rad, rad, 0, 5 + qrand() % 500, 0.9, (qrand() % 100)/100);
		addShape(c);
	}


	double sqwidth = 10 + qrand() % (bRect.width() - 20);
	double sqheight = 10 + qrand() % (bRect.height() - 20);
	Square* sq = new Square(Point(sqwidth, sqheight), 150, 10, qrand() % 90, 50.0, 0.4, 0.1);
	addShape(sq);

	for (int i = 1; i < MAXOBJS; i++ ) {
		double width = 10 + qrand() % (bRect.width() - 20);
		double height = 10 + qrand() % (bRect.height() - 20);
		PolygonShape* pshape = new PolygonShape(Point(width, height), 15, 30, qrand() % 360, 5 + qrand() % 500, 0.7, 0.9);
		vector<Point> vertices;
		// counter-clockwise order
		vertices.push_back(Point(0.0, 0.0));
		vertices.push_back(Point(30.0, 0.0));
		vertices.push_back(Point(45.0, 15.0));
		vertices.push_back(Point(40.0, 25.0));
		vertices.push_back(Point(30.0, 40.0));
		vertices.push_back(Point(0.0, 20.0));
		pshape->setVertices(vertices);
		addShape(pshape);
	}
}

void sandbox::addShape(Shape* shape) {
	shapes.push_back(shape);
	b2controller->addObject(shape);
	for (ModelIter i = models.begin(); i != models.end(); i++) {
		(*i)->addShape(shape, view->scene());
	}
}

void sandbox::removeShape(Shape* shape) {
	for (ModelIter i = models.begin(); i != models.end(); i++) {
		(*i)->deleteShape(shape, view->scene());
	}
	b2controller->removeBody(shape);
	for (ShapeIter i = shapes.begin(); i != shapes.end(); i++) {
		if ( (*i) == shape ) {
			i = shapes.erase(i);
		}
	}
}
void sandbox::createModels() {
	// create the world models (how the world is represented)
//	TextModel* tm = new TextModel(ui.textEdit);
//	models.push_back(tm);
	GraphicsModel* gm = new GraphicsModel(view);
	models.push_back(gm);
}

void sandbox::setupPhysics() {
// moved to addShape();
/*	for (ShapeIter j = shapes.begin(); j != shapes.end(); j++) {
	    	b2controller->addObject((*j));
	} */
}


void sandbox::clearPhysics() {
	while (shapes.size() != 0 ){
			Shape* s = shapes.back();
	    	b2controller->removeBody(s);
	    	shapes.pop_back();
	}

	for (ModelIter i = models.begin(); i != models.end(); i++) {
		(*i)->deleteAllShapes();
	}
}

void sandbox::setupEventLoop() {
	timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(timestep);
}

void sandbox::linkModels() { // link the rendering models to the objects
	// moved to addShape();
/*	for (ModelIter i = models.begin(); i != models.end(); i++) {
		for (ShapeIter j = shapes.begin(); j != shapes.end(); j++) {
			(*i)->addShape(*j, view->scene());
		}
		(*i)->renderShapes(view->scene());
	}
*/
}

sandbox::~sandbox()
{
	for (ModelIter i = models.begin(); i != models.end(); i++) {
		delete *i;
	}
}

void sandbox::update() {
	b2controller->update(timestep);
	for (ShapeIter i = shapes.begin(); i != shapes.end(); i++) {
		b2controller->updateShape((*i));
	}

	for (ModelIter i = models.begin(); i != models.end(); i++) {
			(*i)->update();
	}
}

void sandbox::selectShape(QPoint location) {
	mouseStartPt = location;
	QGraphicsItem* item = view->itemAt(location);
	for (ShapeIter i = shapes.begin(); i != shapes.end(); i++) {
			if (item == (*i)->getGraphic() ) {
				item->setScale(1.2);
				selected = (*i);
			}
	}
}

void sandbox::unselectShape(QPoint location) {
	if (selected->width() != 0) {
		selected->getGraphic()->setScale(1.0);
	}

	if (lineItem->line().x2() != 0)
		view->scene()->removeItem(lineItem);
}

void sandbox::moveShape(QPoint impulse) {
	if (selected->width() == 0) { // if no object is selected
		if (lineItem->line().x2() != 0) // and line is currently defined
			view->scene()->removeItem(lineItem); // remove old line
		QLine line = QLine(mouseStartPt, impulse); // create new line
		lineItem = view->scene()->addLine(line, QPen(Qt::red)); // render new line
	}

	QPoint dist = impulse - last;
	if (selected->width() != 0) {
		b2controller->applyImpulse(selected, dist);
		last = QPoint(selected->location().x(), selected->location().y());
	}
}

void sandbox::setRestitution(int value) {
	if (selected->width() != 0) {
		selected->restitution(value/100.0);
		b2controller->alterBody(selected);
	}
}

void sandbox::setDensity(int value) {
	if (selected->width() != 0) {
		selected->density(value);
		b2controller->alterBody(selected);
	}
}


void sandbox::setFriction(int value) {
	if (selected->width() != 0) {
		selected->friction(value/100.0);
		b2controller->alterBody(selected);
	}
}
void sandbox::updateView( const QRectF & ) {
	resetWorld();
}

void sandbox::deleteWalls() {
	for (ShapeIter i = shapes.begin(); i != shapes.end(); ) {
		if ( (*i)->wall() ) {
			for (ModelIter j = models.begin(); j != models.end(); j++) {
				(*j)->deleteShape(*i, view->scene());
			}
			b2controller->removeBody(*i);
			i = shapes.erase(i);
		} else {
			i++;
		}
	}
}

void sandbox::createWalls() {
	QRect bRect = view->rect();
	int wide = 10;
	// create some walls
	Square* leftWall = new Square(Point(0, 0), wide, bRect.height(), 0, 0, 0.9,0);
	leftWall->wall(true);
	addShape(leftWall);
	Square* rightWall = new Square(Point(bRect.width() - wide, 0), wide, bRect.height(), 0, 0, 0.9,0);
	rightWall->wall(true);
	addShape(rightWall);
	Square* bottomWall = new Square(Point(wide, bRect.height() - wide), bRect.width() - 2*wide, 10, 0, 0, 0.9,0);
	bottomWall->wall(true);
	addShape(bottomWall);
}

void sandbox::createObject(QPoint location) {
	QPoint size = location - mouseStartPt;
	QRect bRect = view->rect();
	QRadioButton* rb = (QRadioButton*)ui.createGroup->checkedButton();
	QString name = rb->objectName();
	QGraphicsItem* item = view->itemAt(location);
	if (selected->width() == 0) {
		if (name == "circleRadio") {
			int rad = 2*sqrt( size.x()*size.x() + size.y()*size.y() ); // radius
			Circle* c = new Circle(Point(mouseStartPt.x() - rad/2, mouseStartPt.y() - rad/2), rad, rad, 0, 5 + qrand() % 50, 0.9, (qrand() % 100)/100);
			addShape(c);
		} else if (name == "rectRadio") {
			Square* sq = new Square(Point(location.x() - size.x()/2, location.y() - size.y()/2), abs(size.x()), abs(size.y()), 0, 5.0, 0.4, 0.1);
			addShape(sq);
		} else if (name == "polyRadio") {
			PolygonShape* pshape = new PolygonShape(Point(location.x(), location.y()), 15, 30, qrand() % 360, 1.0, 0.7, 0.9);
			vector<Point> vertices;
			// counter-clockwise order
			vertices.push_back(Point(0.0, 0.0));
			vertices.push_back(Point(30.0, 0.0));
			vertices.push_back(Point(45.0, 15.0));
			vertices.push_back(Point(40.0, 25.0));
			vertices.push_back(Point(30.0, 40.0));
			vertices.push_back(Point(0.0, 20.0));
			pshape->setVertices(vertices);
			addShape(pshape);
		} else {
			// you shouldn't get here
		}
	}
}
