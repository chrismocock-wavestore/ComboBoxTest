import QtQuick
import QtQuick.Controls
import ComboBoxTest

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
