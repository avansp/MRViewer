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

    // --- signaling & slotting

    // QGraphicsDICOMView::DICOMImageChange --> QDICOMHeaderWidget::ReadDICOMFromQMRImage
    connect(ui->imgViewer,SIGNAL(DICOMImageChanged(const QMRImage*)),ui->dicomList,SLOT(ReadDICOMFromQMRImage(const QMRImage *)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_DICOM_file_triggered()
{
    // This slot is called by user to open a DICOM image file.
    // We should open and show it to the imgViewer widget.

    // get the image filename
    QString filename = QFileDialog::getOpenFileName(this, "Open DICOM Image",
                                                    "",
                                                    "DICOM (*.dcm);;All files (*.*)");
    if( filename.isNull() || filename.isEmpty() ) return;

    // show image
    ui->imgViewer->SetImage(filename);
}

void MainWindow::on_actionAutoFitImage_triggered()
{
    // Resize the image to fit the imgViewer widget.
    ui->imgViewer->SetViewMode(QGraphicsDICOMView::AutoFit);
}





// -- THIS BLOCK ONLY FOR TESTING. SHOULD BE REMOVED WHEN THE TEST IS CORRECT
#include "DICOMTagDefs.h"
void MainWindow::on_actionDICOMTest_triggered()
{
    /*
    for( int i=0; i<DICOMInfo::NumImageTags; i++ )
    {
        qDebug() << "(" << DICOMInfo::Image[i].group.data() << "," << DICOMInfo::Image[i].elmt.data() << ") - " << DICOMInfo::Image[i].name.data();
    }
    */

    // Test open DICOM and get some parameters

}
// -- END OF THE TESTING BLOCK
// PLEASE ADD NEW METHOD NOT BELOW THIS TESTING BLOCK
