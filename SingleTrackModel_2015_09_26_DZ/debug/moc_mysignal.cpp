/****************************************************************************
** Meta object code from reading C++ file 'mysignal.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mysignal.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mysignal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_mySignal_t {
    QByteArrayData data[6];
    char stringdata[82];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mySignal_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mySignal_t qt_meta_stringdata_mySignal = {
    {
QT_MOC_LITERAL(0, 0, 8), // "mySignal"
QT_MOC_LITERAL(1, 9, 21), // "checkBoxCheckedSignal"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 23), // "checkBoxUncheckedSignal"
QT_MOC_LITERAL(4, 56, 19), // "checkboxChangedSlot"
QT_MOC_LITERAL(5, 76, 5) // "state"

    },
    "mySignal\0checkBoxCheckedSignal\0\0"
    "checkBoxUncheckedSignal\0checkboxChangedSlot\0"
    "state"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mySignal[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    0,   30,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   31,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    5,

       0        // eod
};

void mySignal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        mySignal *_t = static_cast<mySignal *>(_o);
        switch (_id) {
        case 0: _t->checkBoxCheckedSignal(); break;
        case 1: _t->checkBoxUncheckedSignal(); break;
        case 2: _t->checkboxChangedSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (mySignal::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&mySignal::checkBoxCheckedSignal)) {
                *result = 0;
            }
        }
        {
            typedef void (mySignal::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&mySignal::checkBoxUncheckedSignal)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject mySignal::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_mySignal.data,
      qt_meta_data_mySignal,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *mySignal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mySignal::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_mySignal.stringdata))
        return static_cast<void*>(const_cast< mySignal*>(this));
    return QObject::qt_metacast(_clname);
}

int mySignal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void mySignal::checkBoxCheckedSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void mySignal::checkBoxUncheckedSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
