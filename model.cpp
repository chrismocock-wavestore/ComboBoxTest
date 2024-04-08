#include "model.h"

Model::Model() : QStringListModel() {
    setStringList({ "Item A", "Item B", "Item C" });
}
