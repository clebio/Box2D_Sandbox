/****************************************************************************
** Meta object code from reading C++ file 'sandbox.h'
**
** Created: Sun Apr 24 09:41:48 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../sandbox.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sandbox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_sandbox[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x0a,
      18,    8,    8,    8, 0x0a,
      40,   31,    8,    8, 0x0a,
      60,   31,    8,    8, 0x0a,
      81,   31,    8,    8, 0x0a,
     111,  103,    8,    8, 0x0a,
     135,  129,    8,    8, 0x0a,
     155,  129,    8,    8, 0x0a,
     171,  129,    8,    8, 0x0a,
     188,    8,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_sandbox[] = {
    "sandbox\0\0update()\0resetWorld()\0location\0"
    "selectShape(QPoint)\0createObject(QPoint)\0"
    "unselectShape(QPoint)\0impulse\0"
    "moveShape(QPoint)\0value\0setRestitution(int)\0"
    "setDensity(int)\0setFriction(int)\0"
    "updateView(QRectF)\0"
};

const QMetaObject sandbox::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_sandbox,
      qt_meta_data_sandbox, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &sandbox::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *sandbox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *sandbox::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_sandbox))
        return static_cast<void*>(const_cast< sandbox*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int sandbox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: update(); break;
        case 1: resetWorld(); break;
        case 2: selectShape((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 3: createObject((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 4: unselectShape((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 5: moveShape((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 6: setRestitution((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: setDensity((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: setFriction((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: updateView((*reinterpret_cast< const QRectF(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
