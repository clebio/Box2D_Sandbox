/*
 * Box2DController.cpp
 *
 *  Created on: Feb 5, 2011
 *      Author: caleb
 */

#include "Box2DController.h"

Box2DController::Box2DController() {
	createWorld();
}

Box2DController::~Box2DController() {
	// TODO Auto-generated destructor stub
	delete world;
}

void Box2DController::createWorld() {
    // Define world, gravity
  world = new b2World(b2Vec2(0.0f, G) ) ; // , true);
}

void Box2DController::addObject(Shape* shape) {
	b2Body* body;
	b2BodyDef bodyDef;
	if (shape->density() == 0)
		bodyDef.type = b2_staticBody;
	else
		bodyDef.type = b2_dynamicBody;
	Point loc = shape->location();
	bodyDef.position.Set(loc.x() + shape->width()/2, loc.y() + shape->height()/2);
	bodyDef.allowSleep = TRUE;
	body = world->CreateBody(&bodyDef);

	b2Shape* objectShape;
	if (shape->name() == "square") {
	    b2PolygonShape* b2polyShape = new b2PolygonShape();
	    b2polyShape->SetAsBox(shape->width()/2, shape->height()/2);
		objectShape = b2polyShape;
	} if (shape->name() == "circle") {
		b2CircleShape* dynamicShape = new b2CircleShape();
		dynamicShape->m_radius = shape->width()/2;
		objectShape = dynamicShape;
	} else if (shape->name() == "polygon") { // all that remains are polygons
		vector<Point> vertices = ((PolygonShape*)shape)->vertices();
		vector<Point>::iterator iter;

		b2PolygonShape* b2poly = new b2PolygonShape();
		int vsize = vertices.size();
		b2Vec2* v = new b2Vec2[vsize];
		int idx = 0;
		for (iter = vertices.begin(); iter != vertices.end(); iter++) {
			Point p = (*iter);
			v[idx++].Set(p.x(), p.y());
		}
		b2poly->Set(v, idx);
		objectShape = b2poly;
	}
	b2FixtureDef fixtureDef;
	fixtureDef.shape = objectShape;
	fixtureDef.density = shape->density();
	fixtureDef.friction = shape->friction();
	fixtureDef.restitution = shape->restitution();
	body->CreateFixture(&fixtureDef);
	body->SetTransform(body->GetPosition(), shape->rotation());

	bodyMap.insert(make_pair(shape, body));
	delete objectShape;
}

void Box2DController::update(float timeStep) {
	world->Step(timeStep, velocityIterations, positionIterations);
	world->ClearForces();
}

void Box2DController::updateShape(Shape* shape) {
	BodyIter iter = bodyMap.find(shape);
	b2Body* body = iter->second;
	b2Vec2 position = body->GetPosition();
	shape->location(Point(position.x, position.y));
	shape->rotation(body->GetAngle() * (180/3.141592));
}

void Box2DController::applyImpulse(Shape* shape, QPoint impulse) {
	BodyIter iter = bodyMap.find(shape);
	b2Body* body = iter->second;
	b2Vec2 at = body->GetWorldCenter();
	body->ApplyLinearImpulse(body->GetMass()*b2Vec2(impulse.x(), impulse.y()), at); // doesn't appear to do anything
}

QPoint Box2DController::getCOM(Shape* shape) {
	BodyIter iter = bodyMap.find(shape);
	b2Body* body = iter->second;
	b2Vec2 vec = body->GetLocalCenter();
	return QPoint(vec.x, vec.y);
}

void Box2DController::removeBody(Shape* shape) {
	BodyIter iter = bodyMap.find(shape);
	b2Body* body = iter->second;
	world->DestroyBody(body);
	bodyMap.erase(iter);
}

void Box2DController::alterBody(Shape* shape) {
	BodyIter iter = bodyMap.find(shape);
	b2Body* body = iter->second;
	b2Fixture* fix = body->GetFixtureList();
	b2FixtureDef fixDef;
	fixDef.shape = fix->GetShape();
	fixDef.restitution = shape->restitution();
	fixDef.density = shape->density();
	fixDef.friction = shape->friction();
	body->CreateFixture(&fixDef);
}
