import QtQuick 2.10
import QtQuick.Controls 2.3

SpinBox {
    id: control
    property int topValue: 1045
    property int bottomValue: 0
    contentItem: TextInput {
        z: 2
        text: control.textFromValue(control.value, control.locale)
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        font: control.font
        color: "#ffffff"
        selectionColor: "#21be2b"
        selectedTextColor: "#ffffff"
        horizontalAlignment: Qt.AlignHCenter
        verticalAlignment: Qt.AlignVCenter
        validator: IntValidator {
            bottom: control.bottomValue
            top: control.topValue
        }
        readOnly: !control.editable
        inputMethodHints: Qt.ImhFormattedNumbersOnly
    }

    up.indicator: Rectangle {
        x: control.mirrored ? 0 : parent.width - width
        height: parent.height
        implicitWidth: 40
        implicitHeight: 40
        color: control.up.pressed ? "#2c3e50" : "#34495e"
        border.width: 2
        border.color: "#34495e"

        Text {
            text: "+"
            font.pointSize: 12
            color: "#ffffff"
            anchors.fill: parent
            fontSizeMode: Text.Fit
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }

    down.indicator: Rectangle {
        x: control.mirrored ? parent.width - width : 0
        height: parent.height
        implicitWidth: 40
        implicitHeight: 40
        color: control.down.pressed ? "#2c3e50" : "#34495e"
        border.width: 2
        border.color: "#34495e"

        Text {
            text: "-"
            font.pointSize: 12
            color: "#ffffff"
            anchors.fill: parent
            fontSizeMode: Text.Fit
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }

    background: Rectangle {
        implicitWidth: 165
        color: "#2c3e50"
        border.width: 2
        border.color: "#34495e"
    }
}


