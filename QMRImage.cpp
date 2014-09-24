#include "QMRImage.h"

#include "itkImageFileReader.h"
#include "itkRescaleIntensityImageFilter.h"
#include "itkMultiplyImageFilter.h"
#include "itkCastImageFilter.h"

#include "QItkGrayscaleImage.h"

#include <QDebug>

QMRImage::QMRImage(const char *_filename):
    sourceFilename(_filename)
{
    gdcmImageIO = itk::GDCMImageIO::New();
}

QMRImage::QMRImage(const QString &_filename):
    sourceFilename(_filename)
{
    gdcmImageIO = itk::GDCMImageIO::New();
}


bool QMRImage::Load()
{
    if( sourceFilename.isNull() || sourceFilename.isEmpty() ) return false;

    typedef itk::ImageFileReader< QMRImage::ImageType > ReaderType;
    ReaderType::Pointer reader = ReaderType::New();
    reader->SetFileName(sourceFilename.toUtf8().data());
    reader->SetImageIO(gdcmImageIO);

    // load
    try {
        reader->Update();
    } catch (itk::ExceptionObject & e) {
        qCritical() << "Exception in file reader";
        std::cerr << e << std::endl;
        return false;
    }

    // perform rescaling to get the rawImage
    typedef itk::RescaleIntensityImageFilter< QMRImage::ImageType, QMRImage::RawImageType > RescaleFilterType;
    RescaleFilterType::Pointer rescaler = RescaleFilterType::New();
    rescaler->SetOutputMinimum(0.0);
    rescaler->SetOutputMaximum(1.0);
    rescaler->SetInput(reader->GetOutput());

    this->rawImage = rescaler->GetOutput();
    this->rawImage->Update();

    // save rows & columns for faster access
    const RawImageType::SizeType imgSize = rawImage->GetLargestPossibleRegion().GetSize();
    this->rows = imgSize[0];
    this->columns = imgSize[1];

    SetupFilteredImage();

    return true;
}

void QMRImage::Print(std::ostream &_of) const
{
    if( rawImage.IsNull() ) return;

    _of << "Source file: " << sourceFilename.toUtf8().data() << std::endl;
    _of << "Image size: ";
    rawImage->GetLargestPossibleRegion().Print(_of);
}

void QMRImage::SetupFilteredImage()
{
    // for now, this is just the same as rawImage
    this->filteredImage = this->rawImage;
}

QMRImage::RawImageType::ConstPointer QMRImage::GetFilteredImage()
{
    this->filteredImage->Update();
    return this->filteredImage.GetPointer();
}

QImage QMRImage::GetFilteredQImage()
{
    // QImage grayscale uses RGB888 (three times unsigned chars: 0..255)
    // we need to rescale (multiply) by 255
    typedef itk::MultiplyImageFilter< QMRImage::RawImageType, QMRImage::RawImageType, QMRImage::RawImageType > MultiplyFilterType;
    MultiplyFilterType::Pointer multiplier = MultiplyFilterType::New();
    multiplier->SetConstant(255.0);
    multiplier->SetInput( filteredImage );

    // and then cast it to unsigned char
    typedef itk::Image< unsigned char, 2 > UCharImageType;
    typedef itk::CastImageFilter< QMRImage::RawImageType, UCharImageType > CastImageType;
    CastImageType::Pointer caster = CastImageType::New();
    caster->SetInput(multiplier->GetOutput());

    // update the pipeline
    UCharImageType::Pointer ptrImage = caster->GetOutput();
    ptrImage->Update();

    return QItkGrayscaleImage::Create(ptrImage);

}

void QMRImage::GetDICOMHeaders() const
{
    if( this->gdcmImageIO.IsNull() ) return;

    // try to print headers first
    std::string tagValue;
    qDebug() << "(0010,0020) -"  << (this->gdcmImageIO->GetValueFromTag("0010|0020",tagValue) ? tagValue.data() : "NA");
}
