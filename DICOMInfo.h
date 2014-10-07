#ifndef DICOMINFO_H
#define DICOMINFO_H

#include <string>
#include <vector>

/**
 * @brief The DICOMInfo structure stores a list of selected DICOM tags.
 *
 * During construction, an object of this class will initialize the info vector with the initial empty value for each tag.
 */
struct DICOMInfo
{
    DICOMInfo();

    typedef enum {
        AE, // Application Entity
        AS, // Age String
        AT, // Attribute Tag
        CS, // Code String
        DA, // Date
        DS, // Decimal String
        DT, // Date Time
        FL, // Floating Point Single
        FD, // Floating Point Double
        IS, // Integer String
        LO, // Long String
        LT, // Long Text
        OB, // Other Byte String
        OF, // Other Float String
        OW, // Other Word String
        PN, // Person Name
        SH, // Short String
        SL, // Signed Long
        SQ, // Sequence Items
        SS, // Signed Short
        ST, // Short Text
        TM, // Time
        UI, // Unique Identifier (UID)
        UL, // Unsigned Long
        UN, // Unknown
        US, // Unsigned Short
        UT // Unlimited Text
    } VRType;

    typedef enum {
        PatientInfo = 0,
        MRParamInfo,
        StudyInfo,
        GeometryInfo,
        ImageInfo,
        OtherInfo
    } GroupType;

    //!< The structure of each DICOM tag contains (group,elmt), name in VRType with a string value.
    struct DICOMTagType
    {
        std::string group;
        std::string elmt;
        VRType vr;
        std::string name;
        std::string value;
        GroupType groupInfo;

        DICOMTagType(const char *_group, const char *_elmt, VRType _vr, const char *_name, const char *_value="", GroupType _groupInfo=OtherInfo) :
            group(_group), elmt(_elmt), vr(_vr), name(_name), value(_value), groupInfo(_groupInfo) {}
    };

    typedef std::vector<DICOMTagType> DICOMVector;  //!< DICOM info vector type
    DICOMVector info;
};

#endif // DICOMINFO_H
