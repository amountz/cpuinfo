import QtQuick 2.4
import QtQuick.Window 2.2

Window {
    visible: true
    title: "CPU Info"
    width: 600
    height: 800

    ListView {
        anchors.fill: parent
        model: cpuinfo.cpuinfoList
        delegate: Text {
            text: model.modelData
        }
    }

}
