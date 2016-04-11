import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
import QtQuick.Window 2.2

ApplicationWindow {
    visible: true
    title: "CPU Info"
    width: 600
    height: 800

    readonly property int summaryFontSize: 14
    readonly property color summaryFontColor: "darkblue"


    toolBar: ToolBar {
        id: infoBar
        width: parent.width
        anchors.fill: parent

        RowLayout {
            anchors.fill: parent
            Text {
                font.pixelSize: summaryFontSize
                color: summaryFontColor
                text: "Model name: " + cpuinfo.cpuModelName
            }
            Text {
                font.pixelSize: summaryFontSize
                color: summaryFontColor
                text: "Cpu cores:  " + cpuinfo.numCores
            }
            Text {
                font.pixelSize: summaryFontSize
                color: summaryFontColor
                text: "Processors: " + cpuinfo.numProcessors
            }
        }
    }

    TabView {
        anchors.fill: parent
        Tab {
            title: "View All"
            anchors.fill: parent

            TableView {
                x: 2
                y: 2
                model: cpuinfo.cpuinfoList
                TableViewColumn {
                    delegate: Text {
                        text: model.modelData
                        elide: Text.ElideMiddle
                    }
                }
            }
        }
        Repeater {
            model: cpuinfo.numProcessors
            Tab {
                title: "Proc " + index;
                anchors.fill: parent
                Item {
                    anchors.fill: parent
                    Rectangle {
                        color: "white"
                        anchors.fill: parent
                        ListView {
                            id: keylist
                            x: 10
                            y: 10
                            width: 100
                            height: parent.height
                            model: cpuinfo.processorKeyList
                            delegate: Text {
                                width: parent.width
                                text: model.modelData
                                elide: Text.ElideMiddle
                            }
                        }
                    }
                    Item {
                        anchors.fill: parent
                        ListView {
                            x: 150
                            y: keylist.y
                            width: parent.width - keylist.width
                            height: parent.height
                            model: cpuinfo.processorValueList
                            delegate: Text {
                                width: parent.width
                                text: model.modelData
                                elide: Text.ElideMiddle

                            }
                        }
                    }
                }
            }
        }
    }
}
