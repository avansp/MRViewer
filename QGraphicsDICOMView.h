#ifndef QGRAPHICSDICOMVIEW_H
#define QGRAPHICSDICOMVIEW_H

#include <QGraphicsView>

class QGraphicsDICOMViewPrivate;
class QMRImage;

/**
 * @brief A QGraphicsView class which shows a DICOM image to the scene.
 *        Note that this class only handles MONOCHROME 8-bit (unsigned short) type of images.
 */
class QGraphicsDICOMView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit QGraphicsDICOMView(QWidget *parent = 0);
    ~QGraphicsDICOMView();

    void SetImage(const QString &_dicomFilename);

    enum ViewMode { AutoFit, NoFit };
    inline ViewMode GetViewMode() const { return this->viewMode; }
    void SetViewMode(ViewMode _viewMode);

    const QMRImage *GetQMRImage();

signals:
    void DICOMImageChanged(const QMRImage *);

protected slots:
    void OnDICOMImageChanged(const QMRImage *);

protected:
    void RefreshView();
    void resizeEvent(QResizeEvent *event);

private:
    QGraphicsDICOMViewPrivate * const d;
    friend class QGraphicsDICOMViewPrivate;

    ViewMode viewMode;
};

#endif // QGRAPHICSDICOMVIEW_H
