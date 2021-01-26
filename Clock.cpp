#include "Clock.h"
#include <Windows.h>
using namespace df;

Clock::Clock(){
    SYSTEMTIME current;
    GetSystemTime(&current);
    previousTime = ( current.wMinute * 60 * 1000000)
                    + ( current.wSecond * 1000000)
                    + ( current.wMilliseconds * 1000) ;
}

long int Clock::delta(){
    SYSTEMTIME after_ms;
    GetSystemTime(&after_ms);
    long int after = ( after_ms.wMinute * 60 * 1000000)
                + ( after_ms.wSecond * 1000000)
                + ( after_ms.wMilliseconds * 1000) ;
    long int elapsedTime = after - previousTime;
    previousTime = after;
    return elapsedTime;
     
}

long int Clock::split() const{
    SYSTEMTIME splitAfter;
    GetSystemTime(&splitAfter);
    long int splitAfter_ms = ( splitAfter.wMinute * 60 * 1000000)
                                + ( splitAfter.wSecond * 1000000)
                                + ( splitAfter.wMilliseconds * 1000);
    long int splitElapsed = splitAfter_ms - previousTime;
    return splitElapsed;
}
