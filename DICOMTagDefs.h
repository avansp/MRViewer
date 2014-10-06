#ifndef DICOMTAGDEFS_H
#define DICOMTAGDEFS_H

#include <string>
#include <vector>

struct DICOMInfo {

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

    struct DICOMTagType
    {
        std::string group;
        std::string elmt;
        VRType vr;
        std::string name;
        std::string value;

        DICOMTagType(const char *_group, const char *_elmt, VRType _vr, const char *_name, const char *_value="") :
            group(_group), elmt(_elmt), vr(_vr), name(_name), value(_value) {}
    };

    typedef std::vector<DICOMTagType> DICOMVector;

    DICOMVector PatientInfo;
    DICOMVector MRParamInfo;
    DICOMVector StudyInfo;
    DICOMVector GeometryInfo;
    DICOMVector ImageInfo;

    DICOMInfo()
    {
        PatientInfo.push_back(DICOMTagType("0010", "0010", PN, "Patient Name", ""));
        PatientInfo.push_back(DICOMTagType("0010", "0010", PN, "Patient Name", ""));
        PatientInfo.push_back(DICOMTagType("0010", "0020", LO, "Patient ID", "" ));
        PatientInfo.push_back(DICOMTagType("0010", "0030", DA, "Patient Birth Date", ""));
        PatientInfo.push_back(DICOMTagType("0010", "0040", CS, "Patient Sex", ""));
        PatientInfo.push_back(DICOMTagType("0010", "1010", AS, "Patient Age", "" ));
        PatientInfo.push_back(DICOMTagType("0010", "1020", DS, "Patient Size", "" ));
        PatientInfo.push_back(DICOMTagType("0010", "1030", DS, "Patient Weight", "" ));
        PatientInfo.push_back(DICOMTagType("0010", "2160", SH, "Ethnic Group", "" ));
        PatientInfo.push_back(DICOMTagType("0010", "21A0", CS, "Smoking Status", "" ));

        MRParamInfo.push_back(DICOMTagType("0018", "0023", CS, "MR Acquisition Type", "" ));
        MRParamInfo.push_back(DICOMTagType("0018", "0024", SH, "Sequence Name", "" ));
        MRParamInfo.push_back(DICOMTagType("0018", "0050", DS, "Slice Thickness", "" ));
        MRParamInfo.push_back(DICOMTagType("0018", "0080", DS, "Repetition Time", "" ));
        MRParamInfo.push_back(DICOMTagType("0018", "0081", DS, "Echo Time", "" ));
        MRParamInfo.push_back(DICOMTagType("0018", "0082", DS, "Inversion Time", "" ));
        MRParamInfo.push_back(DICOMTagType("0018", "0083", DS, "Number of Averages", "" ));
        MRParamInfo.push_back(DICOMTagType("0018", "0084", DS, "Imaging Frequency", "" ));
        MRParamInfo.push_back(DICOMTagType("0018", "0085", SH, "Imaged Nucleus", "" ));
        MRParamInfo.push_back(DICOMTagType("0018", "0087", DS, "Magnetic Field Strength", "" ));
        MRParamInfo.push_back(DICOMTagType("0018", "0088", DS, "Spacing Between Slices", "" ));
        MRParamInfo.push_back(DICOMTagType("0018", "0089", IS, "Number of Phase Encoding Steps", "" ));
        MRParamInfo.push_back(DICOMTagType("0018", "1060", DS, "Trigger Time", "" ));
        MRParamInfo.push_back(DICOMTagType("0018", "1081", IS, "Low R-R Value", "" ));
        MRParamInfo.push_back(DICOMTagType("0018", "1082", IS, "High R-R Value", "" ));
        MRParamInfo.push_back(DICOMTagType("0018", "1088", IS, "Heart Rate", "" ));
        MRParamInfo.push_back(DICOMTagType("0018", "1090", IS, "Cardiac Number of Images", "" ));
        MRParamInfo.push_back(DICOMTagType("0018", "1094", IS, "Trigger Window", "" ));
        MRParamInfo.push_back(DICOMTagType("0018", "1310", US, "Acquisition Matrix", "" ));
        MRParamInfo.push_back(DICOMTagType("0018", "1312", CS, "Phase Encoding Direction", "" ));
        MRParamInfo.push_back(DICOMTagType("0018", "1314", DS, "Flip Angle", "" ));

        StudyInfo.push_back(DICOMTagType("0020", "000D", UI, "Study Instance UID", ""));
        StudyInfo.push_back(DICOMTagType("0020", "000E", UI, "Series Instance UID", ""));
        StudyInfo.push_back(DICOMTagType("0020", "0010", SH, "Study ID", ""));
        StudyInfo.push_back(DICOMTagType("0020", "0011", IS, "Series Number", ""));
        StudyInfo.push_back(DICOMTagType("0020", "0012", IS, "Acquisition Number", ""));
        StudyInfo.push_back(DICOMTagType("0020", "0013", IS, "Image Number", ""));
        StudyInfo.push_back(DICOMTagType("0020", "0015", IS, "Phase Number", ""));
        StudyInfo.push_back(DICOMTagType("0020", "0016", IS, "Interval Number", ""));
        StudyInfo.push_back(DICOMTagType("0020", "0018", IS, "Angle Number", ""));

        GeometryInfo.push_back(DICOMTagType("0020", "0032", DS, "Image Position Patient", ""));
        GeometryInfo.push_back(DICOMTagType("0020", "0037", DS, "Image Orientation Patient", ""));
        GeometryInfo.push_back(DICOMTagType("0020", "0052", UI, "Frame of Reference UID", ""));
        GeometryInfo.push_back(DICOMTagType("0020", "1041", DS, "Slice Location", ""));

        ImageInfo.push_back(DICOMTagType("0028", "0002", US, "Samples per Pixel", ""));
        ImageInfo.push_back(DICOMTagType("0028", "0004", CS, "Photometric Interpretation", ""));
        ImageInfo.push_back(DICOMTagType("0028", "0008", IS, "Number of Frames", ""));
        ImageInfo.push_back(DICOMTagType("0028", "0010", US, "Rows", ""));
        ImageInfo.push_back(DICOMTagType("0028", "0011", US, "Columns", ""));
        ImageInfo.push_back(DICOMTagType("0028", "0030", DS, "Pixel Spacing", ""));
        ImageInfo.push_back(DICOMTagType("0028", "0031", DS, "Zoom Factor", ""));
        ImageInfo.push_back(DICOMTagType("0028", "0032", DS, "Zoom Center", ""));
        ImageInfo.push_back(DICOMTagType("0028", "0034", IS, "Pixel Aspect Ratio", ""));
        ImageInfo.push_back(DICOMTagType("0028", "0100", US, "Bits Allocated", ""));
        ImageInfo.push_back(DICOMTagType("0028", "0101", US, "Bits Stored", ""));
        ImageInfo.push_back(DICOMTagType("0028", "0102", US, "High Bit", ""));
        ImageInfo.push_back(DICOMTagType("0028", "0103", US, "Pixel Representation", ""));
        ImageInfo.push_back(DICOMTagType("0028", "0106", US, "Smallest Image Pixel Value", ""));
        ImageInfo.push_back(DICOMTagType("0028", "0107", US, "Largest Image Pixel Value", ""));
        ImageInfo.push_back(DICOMTagType("0028", "0108", US, "Smallest Pixel Value in Series", ""));
        ImageInfo.push_back(DICOMTagType("0028", "0109", US, "Largest Pixel Value in Series", ""));
        ImageInfo.push_back(DICOMTagType("0028", "0120", US, "Pixel Padding Value", ""));
        ImageInfo.push_back(DICOMTagType("0028", "1050", DS, "Window Center", ""));
        ImageInfo.push_back(DICOMTagType("0028", "1051", DS, "Window Width", ""));
        ImageInfo.push_back(DICOMTagType("0028", "1052", DS, "Rescale Intercept", ""));
        ImageInfo.push_back(DICOMTagType("0028", "1053", DS, "Rescale Slope", ""));
        ImageInfo.push_back(DICOMTagType("0028", "1054", LO, "Rescale Type", "" ));
    }

    bool isempty() {
        return PatientInfo.size()<1 || MRParamInfo.size()<1 || StudyInfo.size()<1 || GeometryInfo.size()<1 || ImageInfo.size()<1;
    }

};

#endif // DICOMTAGDEFS_H
