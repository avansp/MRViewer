#ifndef QITKGRAYSCALEIMAGE_H
#define QITKGRAYSCALEIMAGE_H

#include "itkImage.h"
#include <QImage>

/**
 * @brief An extended QImage for images read by itk::Image< unsigned short, 2 > object.
 *        Note that the pixel type must be unsigned short and the dimension is 2.
 *        QImage::Format_RGB888 will be created directly during construction.
 */
class QItkGrayscaleImage : public QImage
{
public:
    typedef itk::Image< unsigned char, 2 > ITKUnsignedCharImageType;

    QItkGrayscaleImage(unsigned int _nrows, unsigned int _ncols, ITKUnsignedCharImageType *_itkImage = NULL);

    static QImage Create(ITKUnsignedCharImageType *_itkImage);
};

#endif // QITKGRAYSCALEIMAGE_H
