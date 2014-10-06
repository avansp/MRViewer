#include "QGraphicsDICOMView.h"
#include "QMRImage.h"

#include <QGraphicsScene>
#include <QMessageBox>
#include <QGraphicsPixmapItem>

#include <QDebug>

// --------------------- QGraphicsDICOMViewPrivate
class QGraphicsDICOMViewPrivate
{
public:
    QGraphicsDICOMViewPrivate(QGraphicsDICOMView *_parent):
        q(_parent),
        scene(new QGraphicsScene(_parent)),
        mri(NULL),
        _mriPixmapItem(NULL)
    {
        q->setScene(scene);
    }

    ~QGraphicsDICOMViewPrivate()
    {
        if( mri ) delete mri;
    }

    QGraphicsDICOMView *q;
    QGraphicsScene *scene;
    QMRImage *mri;               // we keep this to manipulate window/level

    // book keeping
    QRectF largestViewArea;
    QGraphicsPixmapItem *_mriPixmapItem;
};


// --------------------- QGraphicsDICOMView

QGraphicsDICOMView::QGraphicsDICOMView(QWidget *parent) :
    QGraphicsView(parent),
    d(new QGraphicsDICOMViewPrivate(this)),
    viewMode(AutoFit)
{
    d->scene = new QGraphicsScene(parent);
    this->setScene(d->scene);

    // signaling
    connect(this,SIGNAL(DICOMImageChanged(const QMRImage *)),SLOT(OnDICOMImageChanged(const QMRImage *)));
}

QGraphicsDICOMView::~QGraphicsDICOMView()
{
    // delete the private part
    delete d;
}

void QGraphicsDICOMView::SetImage(const QString &_dicomFilename)
{
    // setup QMRImage
    if( d->mri ) delete d->mri;
    d->mri = new QMRImage(_dicomFilename);

    if( !d->mri->Load() )
    {
        QMessageBox::critical(this, "Loading Error",
                              QString("Unable to load") + _dicomFilename);
        return;
    }

    // this view only handles one image, so we should keep only one DICOM image
    if( d->_mriPixmapItem ) {
        d->_mriPixmapItem->setPixmap(QPixmap::fromImage(d->mri->GetFilteredQImage()));
    } else {
        d->_mriPixmapItem = d->scene->addPixmap(QPixmap::fromImage(d->mri->GetFilteredQImage()));
    }
    emit DICOMImageChanged(this->d->mri);
}

/**
 * @brief QGraphicsDICOMView::OnDICOMImageChanged does default actions upon new image changes
 */
void QGraphicsDICOMView::OnDICOMImageChanged(const QMRImage *)
{
    // set bookkeeping properties
    d->largestViewArea = d->_mriPixmapItem->boundingRect();

    // refresh
    RefreshView();
}

void QGraphicsDICOMView::SetViewMode(ViewMode _viewMode)
{
    if( this->viewMode == _viewMode ) return;
    this->viewMode = _viewMode;
    RefreshView();
}

void QGraphicsDICOMView::RefreshView()
{
    if( viewMode==AutoFit )
    {
        this->fitInView(d->largestViewArea, Qt::KeepAspectRatio);
    }
}

void QGraphicsDICOMView::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    RefreshView();
}

const QMRImage *QGraphicsDICOMView::GetQMRImage()
{
    return d->mri;
}
