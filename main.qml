import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Window 2.2

Window {
    visible: true
    title: "CPU Info"
    width: 600
    height: 800

    TabView {
        anchors.fill: parent
        Tab {
            title: "View All"
            anchors.fill: parent

            TableView {
                anchors.centerIn: parent
                model: cpuinfo.cpuinfoList
                TableViewColumn {
                }
            }
        }
        Repeater {
            model: cpuinfo.numProcessors
            Tab {
                title: "Proc " + index;
                anchors.fill: parent
                TableView {
                    anchors.centerIn: parent
                    model: cpuinfo.getCpuinfoMap(index)
                    TableViewColumn {
                        title: "key"
                        role: "key"
                        delegate: Text {
                            text: "key"
                        }
                    }
                    TableViewColumn {
                        title: "value"
                        role: "value"
                        delegate: Text {
                            text: "value"
                        }
                    }
                }
            }
        }

    }

}
