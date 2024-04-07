import QtQuick
import QtQuick.Controls
import ComboBoxTestQml

Item {
    Model {
        id: model
    }

    Column {
        ComboBox {
            id: statCombo
            model: model
            textRole: "display"
        }
    }
}
