import QtQuick 2.12
import qtest 1.0

Item {
    width: Constants.width
    height: Constants.height

    Screen01 {
        dial.onValueChanged: {
            progressBar.value=dial.value;
        }
        button.onClicked: {
            Qt.quit();
        }
    }
}
