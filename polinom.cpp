#include "polinom.h"
#include "application.h"

TPolinom::TPolinom():
    a(1),b(1),c(1)
{
    printMode=EPrintModeClassic;
}

TPolinom::TPolinom(number _a,number _b,number _c):
    a(_a),b(_b),c(_c)
{
    printMode=EPrintModeClassic;
}

TPolinom& TPolinom::instance()
{
    static TPolinom self;
    return self;
}

int TPolinom::setCoefficients()
{
    std::cout<<"Enter the coefficients of the polinom(a*x^2+b*x+c):\n";
    std::cout<<"a= ";
    if (!(std::cin>>a))
    {
        return InvalidInput;
    }
    if (a==0)
    {
        return NullA;
    }
     std::cout<<"b= ";
     if (!(std::cin>>b))
     {
         return InvalidInput;
     }
     std::cout<<"c= ";
     if (!(std::cin>>c))
     {
         return InvalidInput;
     }
     return 0;
}

number TPolinom::value(number x)
{
    return a*x*x+b*x+c;
}

void TPolinom::roots()
{
    number D=b*b-4*a*c;
    if (D<0)
    {
        std::cout<<"There are no valid roots\n";
    }
    else if (D==0)
    {
        number x=(-b)/2/a;
        std::cout<<"Root: x1,2= "<<x<<"\n";
    }
    else
    {
        number x1=(-1*b-sqrt(D))/2/a;
        number x2=(-1*b+sqrt(D))/2/a;
        std::cout<<"Roots: x1= "<<x1<<", x2= "<<x2<<"\n";
    }

}

void TPolinom::setPrintMode(EPrintMode mode)
{
    printMode=mode;
}

std::ostream& operator<<(std::ostream& os,TPolinom& pol)
{
    if (pol.printMode==EPrintModeClassic)
    {
        os<<pol.a<<"x^2+"<<pol.b<<"x+"<<pol.c<<"\n";
        return os;
    }
    else
    {
        if (abs(pol.a)!=1)
        {
            os<<pol.a;
        }
        else
        {
            if (pol.b==-1)
            {
                os<<"-";
            }
        }
        os<<"x^2";
        if (pol.b!=0)
        {
            if (pol.b>0)
            {
                os<<"+";
            }
            if (abs(pol.b)!=1)
            {
                os<<pol.b;
            }
            else
            {
                if (pol.b==-1)
                {
                   os<<"-";
                }
            }
            os<<"x";

        }
        if (pol.c!=0)
        {
            if (pol.c>0)
            {
                os<<"+";
            }
            os<<pol.c;
        }
        std::cout<<"\n";

    }
    return os;
}
