#include "DICOMTag.h"

#include <string>
#include <algorithm>
#include <cctype>

DICOMTag::DICOMTag(const char *_group, const char *_elmt, const char *_vr, const char *_name):
    group(_group),
    elmt(_elmt),
    vrStr(_vr),
    name(_name)
{
    // transform _vr into uppercase
    std::transform(vrStr.begin(), vrStr.end(), vrStr.begin(), std::toupper);

    // assign VR value
    if( vrStr == "AE" ) vr=AE;
    else if( vrStr == "AS" ) vr = AS;
    else if( vrStr == "AT" ) vr = AT;
    else if( vrStr == "CS" ) vr = CS;
    else if( vrStr == "DA" ) vr = DA;
    else if( vrStr == "DS" ) vr = DS;
    else if( vrStr == "DT" ) vr = DT;
    else if( vrStr == "FL" ) vr = FL;
    else if( vrStr == "FD" ) vr = FD;
    else if( vrStr == "IS" ) vr = IS;
    else if( vrStr == "LO" ) vr = LO;
    else if( vrStr == "LT" ) vr = LT;
    else if( vrStr == "OB" ) vr = OB;
    else if( vrStr == "OF" ) vr = OF;
    else if( vrStr == "OW" ) vr = OW;
    else if( vrStr == "PN" ) vr = PN;
    else if( vrStr == "SH" ) vr = SH;
    else if( vrStr == "SL" ) vr = SL;
    else if( vrStr == "SQ" ) vr = SQ;
    else if( vrStr == "SS" ) vr = SS;
    else if( vrStr == "ST" ) vr = ST;
    else if( vrStr == "TM" ) vr = TM;
    else if( vrStr == "UI" ) vr = UI;
    else if( vrStr == "UL" ) vr = UL;
    else if( vrStr == "UN" ) vr = UN;
    else if( vrStr == "US" ) vr = US;
    else if( vrStr == "UT" ) vr = UT;
    else vr=UN;
}
