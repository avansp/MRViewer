#include "QGraphicsDICOMView.h"

#include <QGraphicsScene>

// --------------------- QGraphicsDICOMViewPrivate
class QGraphicsDICOMViewPrivate
{
public:
    QGraphicsDICOMViewPrivate(QGraphicsDICOMView *_parent):
        q(_parent),
        scene(new QGraphicsScene(_parent))
    {
        q->setScene(scene);
    }

    QGraphicsDICOMView *q;
    QGraphicsScene *scene;
    QRectF largestViewArea;
};


// --------------------- QGraphicsDICOMView

QGraphicsDICOMView::QGraphicsDICOMView(QWidget *parent) :
    QGraphicsView(parent),
    d(new QGraphicsDICOMViewPrivate(this))
{
}

QGraphicsDICOMView::~QGraphicsDICOMView()
{
    // delete the private part
    delete d;
}
