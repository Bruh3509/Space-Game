#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new MyGraphicsScene();
    scene->setSceneRect(0,0,782,538);
    ui->graphicsView->setScene(scene);
    //QObject::connect(scene, SIGNAL(sceneRectChanged(QRectF)), ui->graphicsView, SLOT(updateSceneRect(QRectF)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

