#ifndef DICOMTAG_H
#define DICOMTAG_H

#include <string>

class DICOMTag
{
public:
    DICOMTag(const char *_group, const char *_elmt, const char *_vr, const char *_name);

    // DICOM's Part 6 Value Representation types
    enum VR { AE, // Application Entity
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
            };

    std::string group;
    std::string elmt;
    std::string vrStr;
    VR vr;
    std::string name;

};

#endif // DICOMTAG_H
