#include "model.h"

Model::Model() : QStringListModel() {
    setStringList({ "A", "B", "C" });
}
