#include "DICOMInfo.h"

DICOMInfo::DICOMInfo()
{
    this->info.push_back(DICOMTagType("0010", "0010", PN, "Patient Name", "", PatientInfo));
    this->info.push_back(DICOMTagType("0010", "0010", PN, "Patient Name", "", PatientInfo));
    this->info.push_back(DICOMTagType("0010", "0020", LO, "Patient ID", "", PatientInfo ));
    this->info.push_back(DICOMTagType("0010", "0030", DA, "Patient Birth Date", "", PatientInfo));
    this->info.push_back(DICOMTagType("0010", "0040", CS, "Patient Sex", "", PatientInfo));
    this->info.push_back(DICOMTagType("0010", "1010", AS, "Patient Age", "", PatientInfo ));
    this->info.push_back(DICOMTagType("0010", "1020", DS, "Patient Size", "", PatientInfo ));
    this->info.push_back(DICOMTagType("0010", "1030", DS, "Patient Weight", "", PatientInfo ));
    this->info.push_back(DICOMTagType("0010", "2160", SH, "Ethnic Group", "", PatientInfo ));
    this->info.push_back(DICOMTagType("0010", "21A0", CS, "Smoking Status", "", PatientInfo ));

    this->info.push_back(DICOMTagType("0018", "0023", CS, "MR Acquisition Type", "", MRParamInfo ));
    this->info.push_back(DICOMTagType("0018", "0024", SH, "Sequence Name", "", MRParamInfo ));
    this->info.push_back(DICOMTagType("0018", "0050", DS, "Slice Thickness", "", MRParamInfo ));
    this->info.push_back(DICOMTagType("0018", "0080", DS, "Repetition Time", "", MRParamInfo ));
    this->info.push_back(DICOMTagType("0018", "0081", DS, "Echo Time", "", MRParamInfo ));
    this->info.push_back(DICOMTagType("0018", "0082", DS, "Inversion Time", "", MRParamInfo ));
    this->info.push_back(DICOMTagType("0018", "0083", DS, "Number of Averages", "", MRParamInfo ));
    this->info.push_back(DICOMTagType("0018", "0084", DS, "Imaging Frequency", "", MRParamInfo ));
    this->info.push_back(DICOMTagType("0018", "0085", SH, "Imaged Nucleus", "", MRParamInfo ));
    this->info.push_back(DICOMTagType("0018", "0087", DS, "Magnetic Field Strength", "", MRParamInfo ));
    this->info.push_back(DICOMTagType("0018", "0088", DS, "Spacing Between Slices", "", MRParamInfo ));
    this->info.push_back(DICOMTagType("0018", "0089", IS, "Number of Phase Encoding Steps", "", MRParamInfo ));
    this->info.push_back(DICOMTagType("0018", "1060", DS, "Trigger Time", "", MRParamInfo ));
    this->info.push_back(DICOMTagType("0018", "1081", IS, "Low R-R Value", "", MRParamInfo ));
    this->info.push_back(DICOMTagType("0018", "1082", IS, "High R-R Value", "", MRParamInfo ));
    this->info.push_back(DICOMTagType("0018", "1088", IS, "Heart Rate", "" , MRParamInfo));
    this->info.push_back(DICOMTagType("0018", "1090", IS, "Cardiac Number of Images", "", MRParamInfo ));
    this->info.push_back(DICOMTagType("0018", "1094", IS, "Trigger Window", "", MRParamInfo ));
    this->info.push_back(DICOMTagType("0018", "1310", US, "Acquisition Matrix", "", MRParamInfo ));
    this->info.push_back(DICOMTagType("0018", "1312", CS, "Phase Encoding Direction", "", MRParamInfo ));
    this->info.push_back(DICOMTagType("0018", "1314", DS, "Flip Angle", "", MRParamInfo ));

    this->info.push_back(DICOMTagType("0020", "000D", UI, "Study Instance UID", "", StudyInfo));
    this->info.push_back(DICOMTagType("0020", "000E", UI, "Series Instance UID", "", StudyInfo));
    this->info.push_back(DICOMTagType("0020", "0010", SH, "Study ID", "", StudyInfo));
    this->info.push_back(DICOMTagType("0020", "0011", IS, "Series Number", "", StudyInfo));
    this->info.push_back(DICOMTagType("0020", "0012", IS, "Acquisition Number", "", StudyInfo));
    this->info.push_back(DICOMTagType("0020", "0013", IS, "Image Number", "", StudyInfo));
    this->info.push_back(DICOMTagType("0020", "0015", IS, "Phase Number", "", StudyInfo));
    this->info.push_back(DICOMTagType("0020", "0016", IS, "Interval Number", "", StudyInfo));
    this->info.push_back(DICOMTagType("0020", "0018", IS, "Angle Number", "", StudyInfo));

    this->info.push_back(DICOMTagType("0020", "0032", DS, "Image Position Patient", "", GeometryInfo));
    this->info.push_back(DICOMTagType("0020", "0037", DS, "Image Orientation Patient", "", GeometryInfo));
    this->info.push_back(DICOMTagType("0020", "0052", UI, "Frame of Reference UID", "", GeometryInfo));
    this->info.push_back(DICOMTagType("0020", "1041", DS, "Slice Location", "", GeometryInfo));

    this->info.push_back(DICOMTagType("0028", "0002", US, "Samples per Pixel", "", ImageInfo));
    this->info.push_back(DICOMTagType("0028", "0004", CS, "Photometric Interpretation", "", ImageInfo));
    this->info.push_back(DICOMTagType("0028", "0008", IS, "Number of Frames", "", ImageInfo));
    this->info.push_back(DICOMTagType("0028", "0010", US, "Rows", "", ImageInfo));
    this->info.push_back(DICOMTagType("0028", "0011", US, "Columns", "", ImageInfo));
    this->info.push_back(DICOMTagType("0028", "0030", DS, "Pixel Spacing", "", ImageInfo));
    this->info.push_back(DICOMTagType("0028", "0031", DS, "Zoom Factor", "", ImageInfo));
    this->info.push_back(DICOMTagType("0028", "0032", DS, "Zoom Center", "", ImageInfo));
    this->info.push_back(DICOMTagType("0028", "0034", IS, "Pixel Aspect Ratio", "", ImageInfo));
    this->info.push_back(DICOMTagType("0028", "0100", US, "Bits Allocated", "", ImageInfo));
    this->info.push_back(DICOMTagType("0028", "0101", US, "Bits Stored", "", ImageInfo));
    this->info.push_back(DICOMTagType("0028", "0102", US, "High Bit", "", ImageInfo));
    this->info.push_back(DICOMTagType("0028", "0103", US, "Pixel Representation", "", ImageInfo));
    this->info.push_back(DICOMTagType("0028", "0106", US, "Smallest Image Pixel Value", "", ImageInfo));
    this->info.push_back(DICOMTagType("0028", "0107", US, "Largest Image Pixel Value", "", ImageInfo));
    this->info.push_back(DICOMTagType("0028", "0108", US, "Smallest Pixel Value in Series", "", ImageInfo));
    this->info.push_back(DICOMTagType("0028", "0109", US, "Largest Pixel Value in Series", "", ImageInfo));
    this->info.push_back(DICOMTagType("0028", "0120", US, "Pixel Padding Value", "", ImageInfo));
    this->info.push_back(DICOMTagType("0028", "1050", DS, "Window Center", "", ImageInfo));
    this->info.push_back(DICOMTagType("0028", "1051", DS, "Window Width", "", ImageInfo));
    this->info.push_back(DICOMTagType("0028", "1052", DS, "Rescale Intercept", "", ImageInfo));
    this->info.push_back(DICOMTagType("0028", "1053", DS, "Rescale Slope", "", ImageInfo));
    this->info.push_back(DICOMTagType("0028", "1054", LO, "Rescale Type", "" , ImageInfo));
}

