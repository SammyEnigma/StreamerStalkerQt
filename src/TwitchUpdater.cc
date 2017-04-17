#include "TwitchUpdater.hh"

#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>

#include "Streamer.hh"

namespace {
    const QString stream_pattern("https://api.twitch.tv/kraken/streams/%1?client_id=%2");
    QNetworkAccessManager netacc;
}

TwitchUpdater::TwitchUpdater()
    : IUpdater("TwitchUpdater")
{
    QFile jfile(":/twitch_auth.json");
    jfile.open(QFile::ReadOnly);
    auto json = QJsonDocument::fromJson(jfile.readAll());
    auto obj = json.object();
    clientId = obj["clientId"].toString();
}

void TwitchUpdater::updateStreamer(Streamer &streamer) {
    if (userRegex.indexIn(streamer.getUrl()) != -1)
    {
        QString user = userRegex.cap(1);
        QUrl url(stream_pattern.arg(user).arg(clientId));

        QNetworkRequest request;
        request.setUrl(url);
        auto reply = netacc.get(request);

        auto onFinished = [&streamer,reply]()
        {
            auto obj = QJsonDocument::fromJson(reply->readAll()).object();
            auto stream = obj["stream"];
            if (stream.isNull())
            {
                streamer.setOnline(false);
            } else {
                auto stream_obj = stream.toObject();
                auto channel = stream_obj["channel"].toObject();

                streamer.setOnline(true);
                streamer.setName(channel["name"].toString());
                streamer.setGame(channel["game"].toString());
                streamer.setTitle(channel["status"].toString());
            }

            reply->deleteLater();
        };
        QObject::connect(reply, &QNetworkReply::finished, reply, onFinished);
    }
}

bool TwitchUpdater::doesHandle(const QString &url)
{
    QRegExp regex("^https?://www.twitch.tv/\\w*$");
    return regex.indexIn(url) != -1;
}
