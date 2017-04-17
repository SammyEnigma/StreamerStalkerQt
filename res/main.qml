import QtQuick 2.7
import QtQuick.Window 2.2
import Stalker 1.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3

Window {
    visible: true
    width: 200
    height: 600
    title: qsTr("Streamer Stalker (QT)")

    Stalker { id: stalker }
    Timer {
        interval: 30000
        running: true
        onTriggered: stalker.updateAll();
    }

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 10

        Repeater {
            model: stalker.streamers

            Streamer {
                Layout.alignment: Qt.AlignHCenter
                Layout.fillWidth: true
                streamer: modelData
            }
        }

        Rectangle {
            Layout.fillHeight: true
        }

        Button {
            Layout.alignment: Qt.AlignHCenter
            Layout.fillWidth: true

            text: "Update All"
            onClicked: stalker.updateAll()
            style: ButtonStyle {
                label: Text {
                    renderType: Text.NativeRendering
                    horizontalAlignment: Text.AlignHCenter
                    font.family: "Helvetica"
                    font.pointSize: 12
                    color: "black"
                    text: control.text
                }
                background: Rectangle {
                    color: "white"
                    border.color: "black"
                    border.width: 1
                }
            }
        }
    }
}
