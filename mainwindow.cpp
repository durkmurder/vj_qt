#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "image.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connectSignals();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onLoad()
{
    Image *myImage = new Image;
    if(myImage->readPgm("Face.pgm") == 0)
    {
        QImage labelImage(myImage->data(), myImage->width(), myImage->height(), QImage::Format_MonoLSB);
        ui->label->setPixmap(QPixmap::fromImage(labelImage));
        qDebug() << myImage->writePgm("face1.pgm");
    }

}

void MainWindow::connectSignals()
{
    connect(ui->loadButton, SIGNAL(clicked()), this, SLOT(onLoad()));
}
