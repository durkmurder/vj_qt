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
    MyImage imageObj;
    MyImage *image = &imageObj;

    int flag = readPgm((char *)"Face.pgm", image);
    if (flag == -1)
    {
        qDebug() << "Unable to open input image\n";

    }
    QImage labelImage(image->data, image->width, image->height, QImage::Format_Indexed8);
    ui->label->setPixmap(QPixmap::fromImage(labelImage));
    ui->label->setFixedSize(image->width, image->height);

}

void MainWindow::connectSignals()
{
    connect(ui->loadButton, SIGNAL(clicked()), this, SLOT(onLoad()));
}
