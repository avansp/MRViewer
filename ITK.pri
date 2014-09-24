# --- ITK library
#     This is similar to what FindITK.cmake does, but perhaps simpler

# You probably need to change ITKROOT & ITKVER variables
ITKROOT = /Users/asui085/Developer/ITK/dist
ITKVER = 4.7

ITKPATH = $$ITKROOT/include/ITK-$$ITKVER
ITKCOMMONLIBS = -lITKCommon-$$ITKVER -litksys-$$ITKVER -litkvnl_algo-$$ITKVER -litkvnl-$$ITKVER
ITKUSEPNGIO = -lITKIOPNG-$$ITKVER -litkpng-$$ITKVER
ITKGDCMLIBS = -lITKIOGDCM-$$ITKVER -litkgdcmCommon-$$ITKVER -lITKVNLInstantiation-$$ITKVER -litkv3p_netlib-$$ITKVER \
    -litkgdcmMSFF-$$ITKVER -framework CoreFoundation \
    -litkgdcmDSED-$$ITKVER -litkgdcmDICT-$$ITKVER -litkgdcmuuid-$$ITKVER -litkgdcmIOD-$$ITKVER \
    -litkgdcmjpeg8-$$ITKVER -litkgdcmjpeg12-$$ITKVER -litkgdcmjpeg16-$$ITKVER -litkzlib-$$ITKVER -lITKEXPAT-$$ITKVER -litkopenjpeg-$$ITKVER
ITKLIBS = -L$$ITKROOT/lib $$ITKCOMMONLIBS -lITKIOImageBase-$$ITKVER $$ITKGDCMLIBS

INCLUDEPATH += $$ITKPATH
LIBS += $$ITKLIBS
