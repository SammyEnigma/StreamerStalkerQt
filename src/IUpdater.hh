#pragma once
#include <QString>

class Streamer;
class IUpdater {
public:
    IUpdater(QString _name) : name(_name) {}

    virtual void updateStreamer(Streamer&) = 0;
    virtual void fetchAvatar(Streamer&) = 0;
    virtual bool doesHandle(QString const&) = 0;

    QString const& getName() const { return name; }
protected:
    QString name;
};
