#ifndef MODEL_H
#define MODEL_H

#include <QStringListModel>
#include <QtQmlIntegration>

class Model : public QStringListModel {
    Q_OBJECT
    Q_DISABLE_COPY_MOVE(Model)
    QML_ELEMENT

public:
    Model();

};

#endif // MODEL_H
