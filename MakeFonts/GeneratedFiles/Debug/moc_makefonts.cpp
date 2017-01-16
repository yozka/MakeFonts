/****************************************************************************
** Meta object code from reading C++ file 'makefonts.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../makefonts.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'makefonts.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MakeFonts_t {
    QByteArrayData data[7];
    char stringdata[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MakeFonts_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MakeFonts_t qt_meta_stringdata_MakeFonts = {
    {
QT_MOC_LITERAL(0, 0, 9), // "MakeFonts"
QT_MOC_LITERAL(1, 10, 16), // "slot_addTextFile"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 19), // "slot_removeTextFile"
QT_MOC_LITERAL(4, 48, 12), // "slot_addFont"
QT_MOC_LITERAL(5, 61, 15), // "slot_removeFont"
QT_MOC_LITERAL(6, 77, 13) // "slot_generate"

    },
    "MakeFonts\0slot_addTextFile\0\0"
    "slot_removeTextFile\0slot_addFont\0"
    "slot_removeFont\0slot_generate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MakeFonts[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a /* Public */,
       3,    0,   40,    2, 0x0a /* Public */,
       4,    0,   41,    2, 0x0a /* Public */,
       5,    0,   42,    2, 0x0a /* Public */,
       6,    0,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MakeFonts::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MakeFonts *_t = static_cast<MakeFonts *>(_o);
        switch (_id) {
        case 0: _t->slot_addTextFile(); break;
        case 1: _t->slot_removeTextFile(); break;
        case 2: _t->slot_addFont(); break;
        case 3: _t->slot_removeFont(); break;
        case 4: _t->slot_generate(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MakeFonts::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MakeFonts.data,
      qt_meta_data_MakeFonts,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MakeFonts::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MakeFonts::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MakeFonts.stringdata))
        return static_cast<void*>(const_cast< MakeFonts*>(this));
    return QDialog::qt_metacast(_clname);
}

int MakeFonts::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
