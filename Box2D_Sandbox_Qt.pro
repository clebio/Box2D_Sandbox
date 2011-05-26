TEMPLATE = app
TARGET = sandbox
QT += core \
    gui
HEADERS += KittyCircle.h \
    box2dview.h \
    Box2D_Sandbox/PolygonShape.h \
    Box2D.h \
    Box2DController.h \
    GraphicsModel.h \
    TextModel.h \
    AbstractModel.h \
    resources.h \
    Box2D_Sandbox/Circle.h \
    Box2D_Sandbox/SandboxController.h \
    Box2D_Sandbox/Shape.h \
    Box2D_Sandbox/Square.h \
    sandbox.h
SOURCES += KittyCircle.cpp \
    Box2DView.cpp \
    Box2D_Sandbox/PolygonShape.cpp \
    Box2D/Collision/Shapes/b2CircleShape.cpp \
    Box2D/Collision/Shapes/b2PolygonShape.cpp \
    Box2D/Collision/b2BroadPhase.cpp \
    Box2D/Collision/b2CollideCircle.cpp \
    Box2D/Collision/b2CollidePolygon.cpp \
    Box2D/Collision/b2Collision.cpp \
    Box2D/Collision/b2Distance.cpp \
    Box2D/Collision/b2DynamicTree.cpp \
    Box2D/Collision/b2TimeOfImpact.cpp \
    Box2D/Common/b2BlockAllocator.cpp \
    Box2D/Common/b2Math.cpp \
    Box2D/Common/b2Settings.cpp \
    Box2D/Common/b2StackAllocator.cpp \
    Box2D/Dynamics/Contacts/b2CircleContact.cpp \
    Box2D/Dynamics/Contacts/b2Contact.cpp \
    Box2D/Dynamics/Contacts/b2ContactSolver.cpp \
    Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.cpp \
    Box2D/Dynamics/Contacts/b2PolygonContact.cpp \
    Box2D/Dynamics/Contacts/b2TOISolver.cpp \
    Box2D/Dynamics/Joints/b2DistanceJoint.cpp \
    Box2D/Dynamics/Joints/b2FrictionJoint.cpp \
    Box2D/Dynamics/Joints/b2GearJoint.cpp \
    Box2D/Dynamics/Joints/b2Joint.cpp \
    Box2D/Dynamics/Joints/b2LineJoint.cpp \
    Box2D/Dynamics/Joints/b2MouseJoint.cpp \
    Box2D/Dynamics/Joints/b2PrismaticJoint.cpp \
    Box2D/Dynamics/Joints/b2PulleyJoint.cpp \
    Box2D/Dynamics/Joints/b2RevoluteJoint.cpp \
    Box2D/Dynamics/Joints/b2WeldJoint.cpp \
    Box2D/Dynamics/b2Body.cpp \
    Box2D/Dynamics/b2ContactManager.cpp \
    Box2D/Dynamics/b2Fixture.cpp \
    Box2D/Dynamics/b2Island.cpp \
    Box2D/Dynamics/b2World.cpp \
    Box2D/Dynamics/b2WorldCallbacks.cpp \
    Box2DController.cpp \
    GraphicsModel.cpp \
    TextModel.cpp \
    AbstractModel.cpp \
    Box2D_Sandbox/Circle.cpp \
    Box2D_Sandbox/SandboxController.cpp \
    Box2D_Sandbox/Shape.cpp \
    Box2D_Sandbox/Square.cpp \
    main.cpp \
    sandbox.cpp
FORMS += sandbox.ui \
    sandbox.ui
RESOURCES += 
QMAKE_LIBDIR += /usr/include/Box2D
