#include "QGraphicsImageView.h"

#include <QGraphicsScene>

// --------------------- QGraphicsImageViewPrivate
class QGraphicsImageViewPrivate
{
public:
    QGraphicsImageViewPrivate(QGraphicsImageView *_parent):
        q(_parent),
        scene(new QGraphicsScene(_parent))
    {
        q->setScene(scene);
    }

    QGraphicsImageView *q;
    QGraphicsScene *scene;
    QRectF largestViewArea;
};


// --------------------- QGraphicsImageView

QGraphicsImageView::QGraphicsImageView(QWidget *parent) :
    QGraphicsView(parent),
    d(new QGraphicsImageViewPrivate(this))
{
}

QGraphicsImageView::~QGraphicsImageView()
{
    // delete the private part
    delete d;
}

void QGraphicsImageView::SetImage(const QImage &_image)
{
    d->scene->addPixmap(QPixmap::fromImage(_image));
    d->largestViewArea = QRectF(QPointF(0,0),_image.size());
    this->fitInView(d->largestViewArea);
}
