/****************************************************************************
** Meta object code from reading C++ file 'chatclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Project Q/chatclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chatclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ChatClient_t {
    QByteArrayData data[38];
    char stringdata0[407];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChatClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChatClient_t qt_meta_stringdata_ChatClient = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ChatClient"
QT_MOC_LITERAL(1, 11, 9), // "connected"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 8), // "loggedIn"
QT_MOC_LITERAL(4, 31, 10), // "loginError"
QT_MOC_LITERAL(5, 42, 6), // "reason"
QT_MOC_LITERAL(6, 49, 12), // "disconnected"
QT_MOC_LITERAL(7, 62, 15), // "messageReceived"
QT_MOC_LITERAL(8, 78, 6), // "sender"
QT_MOC_LITERAL(9, 85, 4), // "text"
QT_MOC_LITERAL(10, 90, 5), // "error"
QT_MOC_LITERAL(11, 96, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(12, 125, 11), // "socketError"
QT_MOC_LITERAL(13, 137, 10), // "userJoined"
QT_MOC_LITERAL(14, 148, 8), // "username"
QT_MOC_LITERAL(15, 157, 8), // "userLeft"
QT_MOC_LITERAL(16, 166, 12), // "formReceived"
QT_MOC_LITERAL(17, 179, 12), // "turnReceived"
QT_MOC_LITERAL(18, 192, 13), // "farbeReceived"
QT_MOC_LITERAL(19, 206, 13), // "kopieReceived"
QT_MOC_LITERAL(20, 220, 15), // "connectToServer"
QT_MOC_LITERAL(21, 236, 12), // "QHostAddress"
QT_MOC_LITERAL(22, 249, 7), // "address"
QT_MOC_LITERAL(23, 257, 4), // "port"
QT_MOC_LITERAL(24, 262, 5), // "login"
QT_MOC_LITERAL(25, 268, 8), // "userName"
QT_MOC_LITERAL(26, 277, 11), // "sendMessage"
QT_MOC_LITERAL(27, 289, 10), // "sendPoints"
QT_MOC_LITERAL(28, 300, 8), // "sendTurn"
QT_MOC_LITERAL(29, 309, 18), // "disconnectFromHost"
QT_MOC_LITERAL(30, 328, 10), // "nextPlayer"
QT_MOC_LITERAL(31, 339, 9), // "sendFarbe"
QT_MOC_LITERAL(32, 349, 11), // "QJsonArray&"
QT_MOC_LITERAL(33, 361, 5), // "array"
QT_MOC_LITERAL(34, 367, 8), // "sendForm"
QT_MOC_LITERAL(35, 376, 9), // "sendKopie"
QT_MOC_LITERAL(36, 386, 11), // "onReadyRead"
QT_MOC_LITERAL(37, 398, 8) // "ticktock"

    },
    "ChatClient\0connected\0\0loggedIn\0"
    "loginError\0reason\0disconnected\0"
    "messageReceived\0sender\0text\0error\0"
    "QAbstractSocket::SocketError\0socketError\0"
    "userJoined\0username\0userLeft\0formReceived\0"
    "turnReceived\0farbeReceived\0kopieReceived\0"
    "connectToServer\0QHostAddress\0address\0"
    "port\0login\0userName\0sendMessage\0"
    "sendPoints\0sendTurn\0disconnectFromHost\0"
    "nextPlayer\0sendFarbe\0QJsonArray&\0array\0"
    "sendForm\0sendKopie\0onReadyRead\0ticktock"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChatClient[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      12,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  134,    2, 0x06 /* Public */,
       3,    0,  135,    2, 0x06 /* Public */,
       4,    1,  136,    2, 0x06 /* Public */,
       6,    0,  139,    2, 0x06 /* Public */,
       7,    2,  140,    2, 0x06 /* Public */,
      10,    1,  145,    2, 0x06 /* Public */,
      13,    1,  148,    2, 0x06 /* Public */,
      15,    1,  151,    2, 0x06 /* Public */,
      16,    2,  154,    2, 0x06 /* Public */,
      17,    2,  159,    2, 0x06 /* Public */,
      18,    2,  164,    2, 0x06 /* Public */,
      19,    2,  169,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      20,    2,  174,    2, 0x0a /* Public */,
      24,    1,  179,    2, 0x0a /* Public */,
      26,    1,  182,    2, 0x0a /* Public */,
      27,    1,  185,    2, 0x0a /* Public */,
      28,    1,  188,    2, 0x0a /* Public */,
      29,    0,  191,    2, 0x0a /* Public */,
      30,    0,  192,    2, 0x0a /* Public */,
      31,    1,  193,    2, 0x0a /* Public */,
      34,    1,  196,    2, 0x0a /* Public */,
      35,    1,  199,    2, 0x0a /* Public */,
      36,    0,  202,    2, 0x08 /* Private */,
      37,    0,  203,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    8,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QString, QMetaType::QJsonArray,    8,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QJsonArray,    8,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QJsonArray,    8,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QJsonArray,    8,    9,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 21, QMetaType::UShort,   22,   23,
    QMetaType::Void, QMetaType::QString,   25,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QJsonArray,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 32,   33,
    QMetaType::Void, 0x80000000 | 32,   33,
    QMetaType::Void, 0x80000000 | 32,   33,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ChatClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ChatClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connected(); break;
        case 1: _t->loggedIn(); break;
        case 2: _t->loginError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->disconnected(); break;
        case 4: _t->messageReceived((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 5: _t->error((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 6: _t->userJoined((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->userLeft((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->formReceived((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QJsonArray(*)>(_a[2]))); break;
        case 9: _t->turnReceived((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QJsonArray(*)>(_a[2]))); break;
        case 10: _t->farbeReceived((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QJsonArray(*)>(_a[2]))); break;
        case 11: _t->kopieReceived((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QJsonArray(*)>(_a[2]))); break;
        case 12: _t->connectToServer((*reinterpret_cast< const QHostAddress(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2]))); break;
        case 13: _t->login((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->sendMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 15: _t->sendPoints((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: _t->sendTurn((*reinterpret_cast< const QJsonArray(*)>(_a[1]))); break;
        case 17: _t->disconnectFromHost(); break;
        case 18: _t->nextPlayer(); break;
        case 19: _t->sendFarbe((*reinterpret_cast< QJsonArray(*)>(_a[1]))); break;
        case 20: _t->sendForm((*reinterpret_cast< QJsonArray(*)>(_a[1]))); break;
        case 21: _t->sendKopie((*reinterpret_cast< QJsonArray(*)>(_a[1]))); break;
        case 22: _t->onReadyRead(); break;
        case 23: _t->ticktock(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ChatClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChatClient::connected)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ChatClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChatClient::loggedIn)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ChatClient::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChatClient::loginError)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ChatClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChatClient::disconnected)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ChatClient::*)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChatClient::messageReceived)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ChatClient::*)(QAbstractSocket::SocketError );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChatClient::error)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (ChatClient::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChatClient::userJoined)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (ChatClient::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChatClient::userLeft)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (ChatClient::*)(const QString & , const QJsonArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChatClient::formReceived)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (ChatClient::*)(const QString & , const QJsonArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChatClient::turnReceived)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (ChatClient::*)(const QString & , const QJsonArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChatClient::farbeReceived)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (ChatClient::*)(const QString & , const QJsonArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChatClient::kopieReceived)) {
                *result = 11;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ChatClient::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_ChatClient.data,
    qt_meta_data_ChatClient,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ChatClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChatClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ChatClient.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ChatClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    }
    return _id;
}

// SIGNAL 0
void ChatClient::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ChatClient::loggedIn()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ChatClient::loginError(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ChatClient::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ChatClient::messageReceived(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ChatClient::error(QAbstractSocket::SocketError _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ChatClient::userJoined(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void ChatClient::userLeft(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void ChatClient::formReceived(const QString & _t1, const QJsonArray & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void ChatClient::turnReceived(const QString & _t1, const QJsonArray & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void ChatClient::farbeReceived(const QString & _t1, const QJsonArray & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void ChatClient::kopieReceived(const QString & _t1, const QJsonArray & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
