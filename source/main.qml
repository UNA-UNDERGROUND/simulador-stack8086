import QtQuick 2.12
import QtQuick.Controls 2.3



ApplicationWindow
{
    visible: true
    width: 640
    height: 480
    property alias button: button
    property alias progressBar: progressBar
    property alias dial: dial
    title: qsTr("ejemplo QML")

    Button {
        id: button
        x: 0
        y: 440
        text: qsTr("Salir")
    }

    Dial {
        id: dial
        x: 249
        y: 165
        width: 143
        height: 150
    }

    ProgressBar {
        id: progressBar
        x: 6
        y: 7
        width: 634
        height: 6
        value: 0.5
    }
}
