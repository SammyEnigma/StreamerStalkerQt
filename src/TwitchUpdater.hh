#pragma once

#include "IUpdater.hh"

#include <QString>
#include <QRegExp>

class TwitchUpdater : public IUpdater {
public:
    TwitchUpdater();

    void updateStreamer(Streamer&streamer) override;
    void fetchAvatar(Streamer&) override {}
    bool doesHandle(QString const& url) override;
protected:
    QString clientId;
    QRegExp userRegex = QRegExp{"twitch\\.tv/(\\w+)$"};
};


