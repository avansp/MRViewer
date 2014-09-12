#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_DICOM_file_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open DICOM Image",
                                                    "",
                                                    "DICOM (*.dcm);;All files (*.*)");
    if( filename.isNull() || filename.isEmpty() ) return;

}
