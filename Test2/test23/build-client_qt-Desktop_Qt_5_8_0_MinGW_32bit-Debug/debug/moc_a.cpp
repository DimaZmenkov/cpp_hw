/****************************************************************************
** Meta object code from reading C++ file 'a.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../client_qt/a.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'a.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_A_t {
    QByteArrayData data[10];
    char stringdata0[75];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_A_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_A_t qt_meta_stringdata_A = {
    {
QT_MOC_LITERAL(0, 0, 1), // "A"
QT_MOC_LITERAL(1, 2, 6), // "signal"
QT_MOC_LITERAL(2, 9, 0), // ""
QT_MOC_LITERAL(3, 10, 7), // "signal2"
QT_MOC_LITERAL(4, 18, 9), // "currentTS"
QT_MOC_LITERAL(5, 28, 10), // "onValueSet"
QT_MOC_LITERAL(6, 39, 8), // "newValue"
QT_MOC_LITERAL(7, 48, 8), // "onSignal"
QT_MOC_LITERAL(8, 57, 9), // "onSignal2"
QT_MOC_LITERAL(9, 67, 7) // "onTimer"

    },
    "A\0signal\0\0signal2\0currentTS\0onValueSet\0"
    "newValue\0onSignal\0onSignal2\0onTimer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_A[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    1,   51,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   54,    2, 0x0a /* Public */,
       7,    0,   57,    2, 0x0a /* Public */,
       8,    0,   58,    2, 0x0a /* Public */,
       9,    0,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::ULongLong,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void A::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        A *_t = static_cast<A *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal(); break;
        case 1: _t->signal2(); break;
        case 2: _t->currentTS((*reinterpret_cast< quint64(*)>(_a[1]))); break;
        case 3: _t->onValueSet((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->onSignal(); break;
        case 5: _t->onSignal2(); break;
        case 6: _t->onTimer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (A::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&A::signal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (A::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&A::signal2)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (A::*_t)(quint64 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&A::currentTS)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject A::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_A.data,
      qt_meta_data_A,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *A::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *A::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_A.stringdata0))
        return static_cast<void*>(const_cast< A*>(this));
    return QObject::qt_metacast(_clname);
}

int A::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void A::signal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void A::signal2()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void A::currentTS(quint64 _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
