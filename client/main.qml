import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 2.0
import QtQuick.Controls.Material 2.2
import QtQuick.Layouts 1.3
import com.theqtcompany.nightmodeextension 1.0

ApplicationWindow {
    id: window
    title: "App with night mode support"
    NightModeExtension { id: nightMode }
    Material.theme: nightMode.enabled ? Material.Dark : Material.Light
    visible: true
    header: ToolBar {
        Label {
            anchors.centerIn: parent
            text: window.title
        }
    }
    ColumnLayout {
        anchors.centerIn: parent
        CheckBox {
            enabled: false
            checked: nightMode.enabled
            text: "Night mode enabled"
        }
        Button { text: "Button" }
    }
}
