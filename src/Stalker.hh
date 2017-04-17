#pragma once

#include <QQuickItem>
#include <memory>

class IUpdater;
class Streamer;
class Stalker : public QQuickItem
{
    Q_OBJECT

public:
    Stalker();
    virtual ~Stalker();

    Q_INVOKABLE void updateAll();
    void addStreamer(QString const& url);
    QVariantList getVariantStreamers();

    Q_PROPERTY(QVariantList streamers READ getVariantStreamers NOTIFY onStreamersChanged)
signals:
    void onStreamersChanged();

protected:

    std::vector<std::unique_ptr<IUpdater>> mUpdaters;
    std::vector<Streamer*> mStreamers;
};




