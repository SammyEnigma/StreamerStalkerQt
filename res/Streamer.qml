import QtQuick 2.0
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3

ColumnLayout {
    property var streamer;

    RowLayout {
        Layout.fillWidth: true

        Rectangle {
            width: 16
            height: 16
            radius: 16
            color: streamer.online ? "green" : "red"
        }

        Label {
            color: "black"
            text: streamer.name
            Layout.fillWidth: true
            horizontalAlignment: Text.AlignHCenter
            font.bold: true
            font.family: "Helvetica"
            font.pixelSize: 18
        }

    }


}
