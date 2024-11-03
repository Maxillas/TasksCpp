import QtQuick
import QtQuick.Layouts
import "../Components"

Rectangle {
  id: root

  ColumnLayout {
    Rectangle {
      id: spacer
      width: root.width
      height: 13
      color: transparentColor
    }

    Rectangle {
      id: upperBlock
      height: openBtn.height
      width: root.width
      color: transparentColor
      Row {
        anchors.right: parent.right
        spacing: 15
        ButtonStandart {
          id: openBtn
          mainText: "open playlist"
          backgroundColor: transparentColor
        }
        ButtonStandart {
          id: newBtn
          mainText: "new playlist"
          backgroundColor: transparentColor
        }
      }
    }
    ListView {
      id: playList
      Layout.preferredHeight: root.height - upperBlock.height - bottom.height
      Layout.preferredWidth: root.width

    }
    Rectangle {
      id: bottom
      height: openBtn.height
      width: root.width
      color: transparentColor
      Row {
        anchors.left: parent.left
        spacing: 15
        ButtonStandart {
          id: addBtn
          mainText: "add track"
          backgroundColor: transparentColor
          enabled: false
        }
        ButtonStandart {
          id: copyBtn
          mainText: "copy track"
          backgroundColor: transparentColor
          enabled: false
        }
        ButtonStandart {
          id: deleteBtn
          mainText: "delete track"
          backgroundColor: transparentColor
          enabled: false
        }
      }

    }
  }
}
