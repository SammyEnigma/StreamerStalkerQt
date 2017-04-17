#pragma once

#include <QObject>

#define SETTER(type, name, member, slot) \
    void set##name(type const& _##member) { \
        if (_##member != member) { \
            member = _##member; \
            emit slot(); \
        } \
    }

class IUpdater;
class Streamer : public QObject {
    Q_OBJECT

public:
    Streamer(QObject* parent, QString const& stream_url)
        : QObject(parent), url(stream_url) {}

    void setOnline(bool _online);
    void setHandler(IUpdater* _handler);

    SETTER(QString, Name, name, changed);
    SETTER(QString, Game, game, changed);
    SETTER(QString, Title, title, changed);

    Q_PROPERTY(bool    online MEMBER online NOTIFY changed);
    Q_PROPERTY(QString title  MEMBER title  NOTIFY changed);
    Q_PROPERTY(QString game   MEMBER game   NOTIFY changed);
    Q_PROPERTY(QString name   MEMBER name   NOTIFY changed);
    Q_PROPERTY(QString url    MEMBER url    CONSTANT);

    QString const& getUrl() const { return url; }
    IUpdater* getHandler() const { return handler; }

signals:
    void changed();
    void wentOnline();
    void wentOffline();

protected:
    bool online = false;
    const QString url;
    QString title = "...";
    QString game = "...";
    QString name = "...";
    IUpdater* handler;
};
#undef SETTER

inline void Streamer::setOnline(bool _online) {
    if (_online != online) {
        if (_online) {
            emit wentOnline();
        } else {
            emit wentOffline();
        }
        online = _online;
        emit changed();
    }
}

inline void Streamer::setHandler(IUpdater *_handler) {
    handler = _handler;
}
