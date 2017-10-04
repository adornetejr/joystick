/****************************************************************************
** Meta object code from reading C++ file 'manualwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../manual-control/manualwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'manualwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ManualWindow_t {
    QByteArrayData data[10];
    char stringdata0[206];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ManualWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ManualWindow_t qt_meta_stringdata_ManualWindow = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ManualWindow"
QT_MOC_LITERAL(1, 13, 20), // "on_on_button_clicked"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 7), // "checked"
QT_MOC_LITERAL(4, 43, 25), // "on_id_box_editingFinished"
QT_MOC_LITERAL(5, 69, 26), // "on_ang_box_editingFinished"
QT_MOC_LITERAL(6, 96, 26), // "on_vel_box_editingFinished"
QT_MOC_LITERAL(7, 123, 26), // "on_dri_box_editingFinished"
QT_MOC_LITERAL(8, 150, 27), // "on_kick_box_editingFinished"
QT_MOC_LITERAL(9, 178, 27) // "on_pass_box_editingFinished"

    },
    "ManualWindow\0on_on_button_clicked\0\0"
    "checked\0on_id_box_editingFinished\0"
    "on_ang_box_editingFinished\0"
    "on_vel_box_editingFinished\0"
    "on_dri_box_editingFinished\0"
    "on_kick_box_editingFinished\0"
    "on_pass_box_editingFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ManualWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x08 /* Private */,
       4,    0,   52,    2, 0x08 /* Private */,
       5,    0,   53,    2, 0x08 /* Private */,
       6,    0,   54,    2, 0x08 /* Private */,
       7,    0,   55,    2, 0x08 /* Private */,
       8,    0,   56,    2, 0x08 /* Private */,
       9,    0,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ManualWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ManualWindow *_t = static_cast<ManualWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_on_button_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->on_id_box_editingFinished(); break;
        case 2: _t->on_ang_box_editingFinished(); break;
        case 3: _t->on_vel_box_editingFinished(); break;
        case 4: _t->on_dri_box_editingFinished(); break;
        case 5: _t->on_kick_box_editingFinished(); break;
        case 6: _t->on_pass_box_editingFinished(); break;
        default: ;
        }
    }
}

const QMetaObject ManualWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ManualWindow.data,
      qt_meta_data_ManualWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ManualWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ManualWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ManualWindow.stringdata0))
        return static_cast<void*>(const_cast< ManualWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ManualWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
