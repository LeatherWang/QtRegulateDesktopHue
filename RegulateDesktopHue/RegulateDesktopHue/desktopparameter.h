#ifndef DESKTOPPARAMETER
#define DESKTOPPARAMETER

#include <QApplication>
#include <QDesktopWidget>
#include "windows.h"
#include "wingdi.h"

class DesktopDetector {
private:
    int g_nScreenCount;
    int g_nActScreenC[2];

public:
    DesktopDetector(uchar n):g_nScreenCount(n){}
    void GetScreenInfo()
    {
       QDesktopWidget* desktopWidget = QApplication::desktop();
       QRect screenRect =desktopWidget->screenGeometry();

       g_nActScreenC[0] = screenRect.width();
       g_nActScreenC[1] = screenRect.height();
       g_nScreenCount = desktopWidget->screenCount();
    }
    int GetScreenCount()
    {
        return g_nScreenCount;
    }
    int GetScreenRadioX()
    {
        return g_nActScreenC[0];
    }
    int GetScreenRadioY()
    {
        return g_nActScreenC[1];
    }
    #define Q_WS_WIN
    int SetGamma(int bright)//0~100
    {
      #ifdef Q_WS_WIN
        void * lpGamma = NULL;
        int iArrayValue;
        WORD gMap[3][256] = {0};
        lpGamma = &gMap;
        HDC hdc = ::GetDC(NULL);
        if (NULL == hdc)
            return -1;
        for (int i = 0; i < 256; i++)
        {
            iArrayValue = i * (bright + 128);
            if (iArrayValue > 65535)
                iArrayValue = 65535;
                gMap[0][i] =
                gMap[1][i] =
                gMap[2][i] = (WORD)iArrayValue;
        }
        if (FALSE == SetDeviceGammaRamp(hdc, lpGamma))
            return -2;
        return 0;
      #endif
    }
};



#endif // DESKTOPPARAMETER

