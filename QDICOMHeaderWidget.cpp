#include "QDICOMHeaderWidget.h"
#include "QMRImage.h"
#include "DICOMTagDefs.h"

#include <QComboBox>
#include <QTableWidget>
#include <QLabel>
#include <QGridLayout>
#include <QStringList>

#include <QDebug>

QDICOMHeaderWidget::QDICOMHeaderWidget(QWidget *parent) :
    QFrame(parent)
{
    // create widgets
    QLabel *filterLabel = new QLabel("Filter");
    this->filterWidget = new QComboBox();
    this->dicomHeaderWidget = new QTableWidget();
    this->dicomHeaderWidget->setColumnCount(3);

    // use grid layout
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(filterLabel,0,0);
    layout->addWidget(this->filterWidget,0,1,1,3);
    layout->addWidget(this->dicomHeaderWidget,1,0,1,4);

    this->setLayout(layout);

    // setup header columns in dicomHeaders
    QStringList headerLabels;
    headerLabels << "(Group, Elmt)" << "Name" << "Value";
    this->dicomHeaderWidget->setHorizontalHeaderLabels(headerLabels);

    // setup filter: match with DICOMInfoType enum values
    QStringList filterList;
    filterList << "Patient" << "MR Parameters" << "Study Information" << "3D Geometry" << "Image Information";
    this->filterWidget->insertItems(0, filterList);

    // setup DICOM header list
    this->dicomInfo = new DICOMInfo();

    // signaling changes in filter
    connect(this->filterWidget, SIGNAL(currentIndexChanged(int)), this, SLOT(FillTable(int)));
}

QDICOMHeaderWidget::~QDICOMHeaderWidget()
{
    if( this->dicomInfo ) delete this->dicomInfo;
}

void QDICOMHeaderWidget::ReadDICOMFromQMRImage(const QMRImage *_img)
{
    Q_ASSERT(_img);

    // PATIENT_INFO
    for( unsigned long i=0; i<this->dicomInfo->PatientInfo.size(); i++ )
    {
        _img->GetDICOMTagAsString(this->dicomInfo->PatientInfo[i].group.data(),
                                  this->dicomInfo->PatientInfo[i].elmt.data(),
                                  this->dicomInfo->PatientInfo[i].value);
    }


    // MR_INFO
    for( unsigned long i=0; i<this->dicomInfo->MRParamInfo.size(); i++ )
    {
        _img->GetDICOMTagAsString(this->dicomInfo->MRParamInfo[i].group.data(),
                                  this->dicomInfo->MRParamInfo[i].elmt.data(),
                                  this->dicomInfo->MRParamInfo[i].value);
    }


    // STUDY_INFO
    for( unsigned long i=0; i<this->dicomInfo->StudyInfo.size(); i++ )
    {
        _img->GetDICOMTagAsString(this->dicomInfo->StudyInfo[i].group.data(),
                                  this->dicomInfo->StudyInfo[i].elmt.data(),
                                  this->dicomInfo->StudyInfo[i].value);
    }


    // GEOMETRY_INFO
    for( unsigned long i=0; i<this->dicomInfo->GeometryInfo.size(); i++ )
    {
        _img->GetDICOMTagAsString(this->dicomInfo->GeometryInfo[i].group.data(),
                                  this->dicomInfo->GeometryInfo[i].elmt.data(),
                                  this->dicomInfo->GeometryInfo[i].value);
    }


    // IMAGE_INFO
    for( unsigned long i=0; i<this->dicomInfo->ImageInfo.size(); i++ )
    {
        _img->GetDICOMTagAsString(this->dicomInfo->ImageInfo[i].group.data(),
                                  this->dicomInfo->ImageInfo[i].elmt.data(),
                                  this->dicomInfo->ImageInfo[i].value);

    }

    FillTable(this->filterWidget->currentIndex());
}


void QDICOMHeaderWidget::FillTable(int _filterIndex)
{

    // select which info
    DICOMInfo::DICOMVector *dicomInfoPtr;
    switch(_filterIndex)
    {
    case 0:
        dicomInfoPtr = &(this->dicomInfo->PatientInfo);
        break;
    case 1:
        dicomInfoPtr = &(this->dicomInfo->MRParamInfo);
        break;
    case 2:
        dicomInfoPtr = &(this->dicomInfo->StudyInfo);
        break;
    case 3:
        dicomInfoPtr = &(this->dicomInfo->GeometryInfo);
        break;
    case 4:
        dicomInfoPtr = &(this->dicomInfo->ImageInfo);
        break;
    }

    // populate the table
    this->dicomHeaderWidget->setRowCount(dicomInfoPtr->size());
    for( int i=0; i<this->dicomHeaderWidget->rowCount(); i++ )
    {
        DICOMInfo::DICOMTagType d = dicomInfoPtr->at(i);
        this->dicomHeaderWidget->setItem(i,0,new QTableWidgetItem(
            QString("(") + d.group.data() + "," + d.elmt.data() +  ")"));
        this->dicomHeaderWidget->setItem(i,1,new QTableWidgetItem(d.name.data()));
        this->dicomHeaderWidget->setItem(i,2, new QTableWidgetItem(d.value.data()));
    }

    this->dicomHeaderWidget->resizeColumnsToContents();
}
