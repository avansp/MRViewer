#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>

#include "QMRImage.h"

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
    // get the image filename
    QString filename = QFileDialog::getOpenFileName(this, "Open DICOM Image",
                                                    "",
                                                    "DICOM (*.dcm);;All files (*.*)");
    if( filename.isNull() || filename.isEmpty() ) return;

    // show image
    ui->imgViewer->SetImage(filename);

    // show dicom headers
    const QMRImage *qmri = ui->imgViewer->GetQMRImage();
    if( qmri ) qmri->GetDICOMHeaders();
}

void MainWindow::on_actionAutoFitImage_triggered()
{
    ui->imgViewer->SetViewMode(QGraphicsDICOMView::AutoFit);
}

#include "DICOMUtils.h"
void MainWindow::on_actionDICOMTest_triggered()
{
    // dicom.dic from the resource
    DICOMUtils::DICOMTagList dcmTags;
    if( !DICOMUtils::ReadDICOMDictionary(":/files/dicom.dic", dcmTags) )
        qDebug() << "ERROR READING DICOM DICTIONARY";
}
