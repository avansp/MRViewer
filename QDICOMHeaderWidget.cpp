#include "QDICOMHeaderWidget.h"
#include "QMRImage.h"

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
    filterList << "All" << "Patient" << "MR Parameters" << "Study Information" << "3D Geometry" << "Image Information" << "Other";
    this->filterWidget->insertItems(0, filterList);

    // signaling changes in filter
    connect(this->filterWidget, SIGNAL(currentIndexChanged(int)), this, SLOT(FillTable(int)));
}

QDICOMHeaderWidget::~QDICOMHeaderWidget()
{
}

void QDICOMHeaderWidget::ReadDICOMFromQMRImage(const QMRImage *_img)
{
    Q_ASSERT(_img);

    this->dicomInfo = _img->GetDICOMInfoVector();
    FillTable(this->filterWidget->currentIndex());
}


void QDICOMHeaderWidget::FillTable(int _filterIndex)
{
    if( _filterIndex==0 ) // ALL
    {
        this->dicomHeaderWidget->setRowCount(dicomInfo.size());
        for( int i=0; i<this->dicomHeaderWidget->rowCount(); i++ )
        {
            DICOMInfo::DICOMTagType d = dicomInfo[i];
            this->dicomHeaderWidget->setItem(i,0,new QTableWidgetItem(
                QString("(") + d.group.data() + "," + d.elmt.data() +  ")"));
            this->dicomHeaderWidget->setItem(i,1,new QTableWidgetItem(d.name.data()));
            this->dicomHeaderWidget->setItem(i,2, new QTableWidgetItem(d.value.data()));
        }
    } else {

        this->dicomHeaderWidget->setRowCount(0);
        int nrows = 0;

        // search group Info
        for( unsigned long i=0; i<dicomInfo.size(); i++ )
        {
            DICOMInfo::DICOMTagType d = dicomInfo[i];
            if( d.groupInfo != _filterIndex-1 ) continue;

            // insert one row
            this->dicomHeaderWidget->setRowCount(++nrows);

            this->dicomHeaderWidget->setItem(nrows-1,0,new QTableWidgetItem(
                QString("(") + d.group.data() + "," + d.elmt.data() +  ")"));
            this->dicomHeaderWidget->setItem(nrows-1,1,new QTableWidgetItem(d.name.data()));
            this->dicomHeaderWidget->setItem(nrows-1,2, new QTableWidgetItem(d.value.data()));
        }
    }

    // fit
    this->dicomHeaderWidget->resizeColumnsToContents();
}
