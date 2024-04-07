#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QLineEdit>
#include <QQmlContext>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    quick_view_(new QQuickView)
{
    ui->setupUi(this);

    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    quick_view_->setResizeMode(QQuickView::SizeRootObjectToView);
    connect(quick_view_, &QQuickView::statusChanged,
            this, &MainWindow::quickViewStatusChanged);
    connect(quick_view_, &QQuickWindow::sceneGraphError,
            this, &MainWindow::sceneGraphError);

    quick_view_->setSource(QUrl(QStringLiteral("qrc:/ComboBoxTestQml/MainWindow.qml")));

    QWidget *container = QWidget::createWindowContainer(quick_view_);
    container->setMinimumSize(quick_view_->size());
    container->setFocusPolicy(Qt::TabFocus);
    layout->addWidget(container);
    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::quickViewStatusChanged(QQuickView::Status status)
{
    if (status == QQuickView::Error) {
        QStringList errors;
        const auto viewErrors = quick_view_->errors();
        for (const QQmlError &error : viewErrors)
            errors.append(error.toString());
        statusBar()->showMessage(errors.join(QStringLiteral(", ")));
    }
}

void MainWindow::sceneGraphError(QQuickWindow::SceneGraphError, const QString &message)
{
    statusBar()->showMessage(message);
}
