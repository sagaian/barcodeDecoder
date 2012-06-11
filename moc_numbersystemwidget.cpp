/****************************************************************************
** Meta object code from reading C++ file 'numbersystemwidget.h'
**
** Created: Sun Jun 10 23:52:33 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "numbersystemwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'numbersystemwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_numberSystemWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x08,
      53,   47,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_numberSystemWidget[] = {
    "numberSystemWidget\0\0on_removeButton_released()\0"
    "index\0on_typeBox_currentIndexChanged(int)\0"
};

const QMetaObject numberSystemWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_numberSystemWidget,
      qt_meta_data_numberSystemWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &numberSystemWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *numberSystemWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *numberSystemWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_numberSystemWidget))
        return static_cast<void*>(const_cast< numberSystemWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int numberSystemWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_removeButton_released(); break;
        case 1: on_typeBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
