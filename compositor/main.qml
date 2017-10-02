import QtQuick 2.7
import QtWayland.Compositor 1.0
import QtQuick.Controls 2.0
import QtQuick.Controls.Material 2.2
import QtQuick.Window 2.0
import QtGraphicalEffects 1.0
import com.theqtcompany.nightmodeextension 1.0

WaylandCompositor {
    NightModeExtension { id: nightMode }
    ListModel { id: shellSurfaces }
    WaylandOutput {
        sizeFollowsWindow: true
        window: ApplicationWindow {
            id: win
            visible: true
            width: 1280
            height: 720
            Material.theme: nightMode.enabled ? Material.Dark : Material.Light
            Item {
                anchors.fill: parent
                SwipeView {
                    id: swipeView
                    anchors.fill: parent
                    Repeater {
                        model: shellSurfaces
                        Item {
                            ShellSurfaceItem {
                                anchors.centerIn: parent
                                shellSurface: modelData
                                onSurfaceDestroyed: shellSurfaces.remove(index)
                            }
                        }
                    }
                }
            }
            footer: ToolBar {
                id: toolBar
                Material.background: nightMode.enabled ? "black" : "white"
                Material.foreground: nightMode.enabled ? "white" : "black"
                ToolButton {
                    text: "←"
                    onClicked: swipeView.decrementCurrentIndex()
                }
                ToolButton {
                    text: "→"
                    anchors.right: parent.right
                    onClicked: swipeView.incrementCurrentIndex()
                }
                ToolButton {
                    text: "Toggle nightmode"
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    anchors.horizontalCenter: parent.horizontalCenter
                    onClicked: nightMode.enabled = !nightMode.enabled
                }
            }
        }
    }
    WlShell {
        onWlShellSurfaceCreated: {
            shellSurfaces.append({"shellSurface": shellSurface })
            var size = Qt.size(swipeView.width * Screen.devicePixelRatio, swipeView.height * Screen.devicePixelRatio);
            shellSurface.sendConfigure(size, WlShellSurface.NoneEdge);
        }
    }
}
