#ifndef QGRAPHICSIMAGEVIEW_H
#define QGRAPHICSIMAGEVIEW_H

#include <QGraphicsView>

class QGraphicsImageViewPrivate;

class QGraphicsImageView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit QGraphicsImageView(QWidget *parent = 0);
    ~QGraphicsImageView();

signals:

public slots:
    void SetImage(const QImage &_image);

private:
    QGraphicsImageViewPrivate * const d;
    friend class QGraphicsImageViewPrivate;

};

#endif // QGRAPHICSIMAGEVIEW_H
