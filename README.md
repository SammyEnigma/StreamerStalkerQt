# StreamerStalkerQt

A QML app to keep an eye on your favourite streamers on different platforms and alert when any of them goes live.

## Building + Running (Linux)
1. clone the repo
2. copy `res/twitch_auth.example.json` to `res/twitch_auth.json` and add your twitch.tv client-id to it
3. `cmake .`
4. `make`
5. `./stalker`

## Roadmap

- [x] twitch.tv support
- [ ] hitbox.tv support
- [ ] beam.pro support

- [x] diplaying online streams
- [ ] displaying stream title + game
- [ ] notifications when streamer goes live
