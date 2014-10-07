#ifndef QDICOMHEADERWIDGET_H
#define QDICOMHEADERWIDGET_H

#include "DICOMInfo.h"
#include <QFrame>

// forward class declaration
class QComboBox;
class QTableWidget;
class QMRImage;

//! QDICOMHeaderWidget
/*!
 * \brief  The QDICOMHeaderWidget creates a frame which contains widgets to show DICOM headers.
 */
class QDICOMHeaderWidget : public QFrame
{
    Q_OBJECT
public:
    explicit QDICOMHeaderWidget(QWidget *parent = 0);
    ~QDICOMHeaderWidget();

signals:

public slots:
    //! Read and populate DICOM headers from QMRImage object.
    void ReadDICOMFromQMRImage(const QMRImage *_img);

    //! Populate DICOM headers into QTableWidget
    void FillTable(int _filterIndex);

private:
    QComboBox *filterWidget;                /*!< Filter the header view  */
    QTableWidget *dicomHeaderWidget;        /*!< Contains 3 columns of DICOM header list: (Group,Elmt) | Name | Value  */
    DICOMInfo::DICOMVector dicomInfo;       /*!< A pointer to the DICOM info vector */
};

#endif // QDICOMHEADERWIDGET_H
