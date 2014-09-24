#ifndef DICOMUTILS_H
#define DICOMUTILS_H

#include "DICOMTag.h"

#include <list>

namespace DICOMUtils
{

    typedef std::list<DICOMTag> DICOMTagList;
    bool ReadDICOMDictionary(const char *_dicFilename, DICOMTagList &_dcmTagList);

}

#endif // DICOMUTILS_H
