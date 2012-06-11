/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sun Jun 10 23:52:33 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      39,   11,   11,   11, 0x08,
      66,   11,   11,   11, 0x08,
      97,   11,   11,   11, 0x08,
     124,   11,   11,   11, 0x08,
     151,   11,   11,   11, 0x08,
     179,   11,   11,   11, 0x08,
     220,  214,   11,   11, 0x08,
     255,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_decodeButton_released()\0"
    "on_browseButton_released()\0"
    "on_saveBrowseButton_released()\0"
    "on_encodeButton_released()\0"
    "on_addSysButton_released()\0"
    "on_enhanceButton_released()\0"
    "on_decodeEnhancedButton_released()\0"
    "index\0on_Analytics_2_currentChanged(int)\0"
    "on_Analytics_EncodeButton_released()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_decodeButton_released(); break;
        case 1: on_browseButton_released(); break;
        case 2: on_saveBrowseButton_released(); break;
        case 3: on_encodeButton_released(); break;
        case 4: on_addSysButton_released(); break;
        case 5: on_enhanceButton_released(); break;
        case 6: on_decodeEnhancedButton_released(); break;
        case 7: on_Analytics_2_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: on_Analytics_EncodeButton_released(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
