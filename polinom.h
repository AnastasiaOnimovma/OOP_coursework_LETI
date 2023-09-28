#ifndef TPOLINOM_H
#define TPOLINOM_H

#include "number.h"
#include <iostream>

enum EPrintMode
{
    EPrintModeClassic,
    EPrintModeCanonic,
};

class TPolinom
{
public:
    TPolinom();
    TPolinom(number,number,number);
    static TPolinom& instance();
    void setPrintMode(EPrintMode);
    int setCoefficients();
    number value(number);
    void TPolinom::roots();
    friend std::ostream& operator<<(std::ostream&,TPolinom&);
private:
    EPrintMode printMode;
    number a,b,c;
};

#endif // TPOLINOM_H
