#include "Stalker.hh"
#include <QtDebug>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>

#include "Streamer.hh"
#include "IUpdater.hh"
#include "ShortLambda.hh"
#include "Functional.hh"
#include "TwitchUpdater.hh"

Stalker::Stalker()
{
    mUpdaters.emplace_back(new TwitchUpdater());

    QFile jfile(":/streamers.json");
    jfile.open(QFile::ReadOnly);
    auto json = QJsonDocument::fromJson(jfile.readAll());
    auto arr = json.array();

    for (auto&& e : arr)
    {
        addStreamer(e.toString());
    }
}

Stalker::~Stalker()
{

}

void Stalker::updateAll()
{
    qDebug() << "Updating streamers";
    for (auto&& s : mStreamers)
    {
        auto handler = s->getHandler();
        handler->updateStreamer(*s);
    }
}

void Stalker::addStreamer(const QString &url)
{
    auto it = fnc::find_if(mUpdaters, SL1(a->doesHandle(url)));

    if (it != end(mUpdaters)) {
        auto streamer = new Streamer(this, url);
        streamer->setHandler(it->get());
        mStreamers.push_back(streamer);

        qDebug() << "Using handler " << it->get()->getName() << " for Streamer-URL " << url;
        emit onStreamersChanged();
    } else {
        qDebug() << "No handler for " << url << " found.";
    }
}

QVariantList Stalker::getVariantStreamers() {
    QVariantList result;
    for (auto&& s : mStreamers)
    {
        result.push_back(QVariant::fromValue(s));
    }
    return result;
}
