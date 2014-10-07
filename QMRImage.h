#ifndef QMRIMAGE_H
#define QMRIMAGE_H

#include "itkImage.h"
#include "itkGDCMImageIO.h"
#include <QString>
#include <QImage>
#include "DICOMInfo.h"

/**
 * @brief The QMRImage class is the swiss-army knife class for handle DICOM MR images.
 *
 * Typical example to use:
 * \code
 * QMRImage *mri = new QMRImage(mri_File_name);
 * mri->Load();
 * QImage img = mri->GetFilteredQImage;
 * \endcode
 *
 */
class QMRImage
{
public:
    QMRImage(const char *_filename=0);
    QMRImage(const QString &_filename);

    ~QMRImage();

    // we only handle unsigned short with 2 dimension for cardiac MRI
    typedef itk::Image< unsigned short, 2 > ImageType;
    typedef itk::Image< float, 2 > RawImageType;

    /**
     * @brief Sets the source filename. It does not physically load the data.
     * @param _filename: a DICOM filename
     */
    void SetFileName(const char *_filename);

    /**
     * @brief Physically loads the data into the rawImage variable.
     */
    bool Load();

    /**
     * @brief Get the pointer to the raw image (the original image data).
     * @return Const pointer to the RawImageType
     */
    RawImageType::ConstPointer GetRawImage() { return this->rawImage.GetPointer(); }

    /**
     * @brief Get the image pointer after being filtered.
     * @return Const pointer to the RawImageType
     */
    RawImageType::ConstPointer GetFilteredImage();
    QImage GetFilteredQImage();

    QString GetSourceFileName() const { return this->sourceFilename; }
    unsigned int GetNumberOfRows() const { return this->rows; }
    unsigned int GetNumberOfColumns() const { return this->columns; }

    void Print(std::ostream &_of) const;

    QString GetDICOMTagAsString(const char *_group, const char *_elmt) const;
    void GetDICOMTagAsString(const char *_group, const char *_elmt, std::string &_value) const;

    float GetDICOMTagAsFloat(const char *_name);

    //!< Inline convenience get DICOM values
    inline float GetWindowCenter() { return this->GetDICOMTagAsFloat("Window Center"); }
    inline float GetWindowLevel() { return this->GetDICOMTagAsFloat("Window Level"); }

    DICOMInfo::DICOMVector const &GetDICOMInfoVector() const { return this->dicomInfo.info; }

protected:
    void SetupFilteredImage();

private:
    QString sourceFilename;
    unsigned int rows, columns;

    // rawImage should copy the image from DICOM image file
    // rescaled it to have values between 0 and 1
    RawImageType::Pointer rawImage;

    // filteredImage is the rawImage after being filtered (window level, etc.)
    RawImageType::Pointer filteredImage;

    // handler to the DICOM tags (keep it in case we need it)
    itk::GDCMImageIO::Pointer gdcmImageIO;

    // DICOM info vector
    DICOMInfo dicomInfo;

};

#endif // QMRIMAGE_H
