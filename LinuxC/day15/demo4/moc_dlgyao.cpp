/****************************************************************************
** Meta object code from reading C++ file 'dlgyao.h'
**
** Created: Tue Feb 10 14:10:33 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "dlgyao.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dlgyao.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DlgYao[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
      22,    7,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_DlgYao[] = {
    "DlgYao\0\0control(bool)\0yao()\0"
};

void DlgYao::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DlgYao *_t = static_cast<DlgYao *>(_o);
        switch (_id) {
        case 0: _t->control((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->yao(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData DlgYao::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DlgYao::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DlgYao,
      qt_meta_data_DlgYao, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DlgYao::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DlgYao::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DlgYao::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DlgYao))
        return static_cast<void*>(const_cast< DlgYao*>(this));
    return QWidget::qt_metacast(_clname);
}

int DlgYao::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void DlgYao::control(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
