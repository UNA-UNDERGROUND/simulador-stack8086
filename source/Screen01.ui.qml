import QtQuick 2.12
import qtest 1.0
import QtQuick.Controls 2.3

Rectangle {
    width: Constants.width
    height: Constants.height

    color: Constants.backgroundColor
    property alias dial: dial
    property alias progressBar: progressBar
    property alias button: button

    Button {
        id: button
        x: 8
        y: 432
        text: qsTr("Salir")
    }

    ProgressBar {
        id: progressBar
        x: 8
        y: 8
        width: 624
        height: 7
        value: 0.5
    }

    Dial {
        id: dial
        x: 267
        y: 188
        width: 107
        height: 104
    }
}
