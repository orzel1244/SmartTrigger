import QtQuick 2.10
import QtQuick.Controls 2.3
import "./components"
ApplicationWindow {
    id: window
    visible: true
    width: 380
    height: 260
    title: qsTr("Smart Trigger")
    Rectangle {
        anchors.fill: parent
        color: "#34495e"
    }
    Column {
        id: column
        anchors.fill: parent
        spacing: 8
        Item { width: 1; height: 1;}
        Rectangle {
            color: "#2c3e50"
            width: parent.width
            height: 65
            anchors.horizontalCenter: parent.horizontalCenter
            Row {
                spacing: 8
                width: parent.width-20
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                CustomSpinBox {
                    id: delaySpinBox
                    anchors.verticalCenter: parent.verticalCenter
                    value: 15
                    onValueChanged: {
                        triggerbot.setDelay(value)
                    }

                    validator: IntValidator {
                        bottom: 0
                        top: 250
                    }
                }
                Text {
                    text: "Delay before shooting (ms)"
                    anchors.verticalCenter: parent.verticalCenter
                    font.pointSize: 11
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    wrapMode: Text.Wrap
                    height: 50
                    width: parent.width-delaySpinBox.width-15
                    color: "#ffffff"
                }
            }
        }

        Rectangle {
            color: "#2c3e50"
            width: parent.width
            height: 65
            anchors.horizontalCenter: parent.horizontalCenter
            Row {
                spacing: 8
                width: parent.width-20
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                CustomSpinBox {
                    id: spinBox2
                    anchors.verticalCenter: parent.verticalCenter
                    validator: IntValidator {
                        bottom: 0
                        top: 250
                    }
                    onValueChanged: {
                        triggerbot.setChance(value)
                    }
                }
                Text {
                    text: "Chance to not shoot (%)"
                    anchors.verticalCenter: parent.verticalCenter
                    font.pointSize: 11
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    wrapMode: Text.Wrap
                    height: 50
                    width: parent.width-delaySpinBox.width-15
                    color: "#ffffff"
                }
            }
        }
    }
    Rectangle {
        id: rectangle1
        color: "#2c3e50"
        width: parent.width
        height: 55
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
        CustomButton {
            text: "Turn on"
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right
            anchors.rightMargin: 8

            onClicked: {
                if (text == "Turn on"){
                    text = "Turn off";
                    triggerbot.setEnabled(true);
                } else {
                    text = "Turn on";
                    triggerbot.setEnabled(false);
                }
            }
        }
    }
}
