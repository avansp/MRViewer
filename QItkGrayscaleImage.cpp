#include "QItkGrayscaleImage.h"
#include "itkImageRegionIterator.h"

QItkGrayscaleImage::QItkGrayscaleImage(unsigned int _nrows, unsigned int _ncols, ITKUnsignedCharImageType *_itkImage) :
    QImage(_ncols,_nrows,QImage::Format_RGB888)
{
    if( !_itkImage )
    {
        fill(0);
        return;
    }

    // check nrows, ncols
    const ITKUnsignedCharImageType::SizeType size = _itkImage->GetLargestPossibleRegion().GetSize();
    Q_ASSERT( size[0]==_nrows && size[1]==_ncols );

    // assign
    unsigned char *pbuffer = this->bits();
    typedef itk::ImageRegionConstIterator< ITKUnsignedCharImageType > ConstIteratorType;
    ConstIteratorType iter( _itkImage, _itkImage->GetLargestPossibleRegion() );
    for( iter.GoToBegin(); !iter.IsAtEnd(); ++iter )
    {
        *pbuffer++ = iter.Get();
        *pbuffer++ = iter.Get();
        *pbuffer++ = iter.Get();
    }
}

QImage QItkGrayscaleImage::Create(ITKUnsignedCharImageType *_itkImage)
{
    Q_ASSERT(_itkImage);

    // get sizes
    const ITKUnsignedCharImageType::SizeType imgSize = _itkImage->GetLargestPossibleRegion().GetSize();
    QItkGrayscaleImage qItkImage(imgSize[0], imgSize[1], _itkImage);
    return qItkImage;
}
