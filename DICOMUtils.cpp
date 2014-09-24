#include "DICOMUtils.h"

#include <QFile>
#include <QTextStream>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

#include <QDebug>

bool DICOMUtils::ReadDICOMDictionary(const char *_dicFilename, DICOMTagList &_dcmTagList)
{
    QFile dicFile(_dicFilename);
    if( !dicFile.open(QIODevice::ReadOnly | QIODevice::Text) ) return false;

    QRegularExpression re("{\\s*0x([0-9ABCDEFabcdef]+),\\s*0x([0-9ABCDEFabcdef]+),\\s*'(\\w\\w)',\\s*\"(.+)\"");
    QRegularExpressionMatch lineMatch;

    _dcmTagList.clear();

    QTextStream in(&dicFile);
    while( !in.atEnd() )
    {
        QString line = in.readLine();

        // every line is { 0xnum,0xnum, VR, desc } --> group="num", elmt="num", VR, name=desc
        lineMatch = re.match(line);

        _dcmTagList.push_back(DICOMTag(lineMatch.captured(1).toUtf8().constData(),
                                       lineMatch.captured(2).toUtf8().constData(),
                                       lineMatch.captured(3).toUtf8().constData(),
                                       lineMatch.captured(4).toUtf8().constData()));
        //qDebug() << "(group,elmt) = (" << lineMatch.captured(1) << "," << lineMatch.captured(2) << "), VR = " << lineMatch.captured(3) << ", name=" << lineMatch.captured(4);
    }

    dicFile.close();
    return true;
}
