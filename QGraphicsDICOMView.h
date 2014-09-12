#ifndef QGRAPHICSDICOMVIEW_H
#define QGRAPHICSDICOMVIEW_H

#include <QGraphicsView>

class QGraphicsDICOMViewPrivate;

class QGraphicsDICOMView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit QGraphicsDICOMView(QWidget *parent = 0);
    ~QGraphicsDICOMView();

signals:

public slots:

private:
    QGraphicsDICOMViewPrivate * const d;
    friend class QGraphicsDICOMViewPrivate;
};

#endif // QGRAPHICSDICOMVIEW_H
