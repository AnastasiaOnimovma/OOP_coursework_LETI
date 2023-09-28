#include <iostream>
#include "application.h"
#include "number.h"
#include "polinom.h"



TApplication::TApplication()
{}

TApplication& TApplication::instance()
{
    static TApplication self;
    return self;
}

int TApplication::exec()
{
    char ch;
    while(true)
    {
        ch=menu();
        switch (ch)
        {
            case '0':
                return 0;
            case '1':
                {
                    int result = TPolinom::instance().setCoefficients();
                    if (result !=0)
                    {
                        TApplication::instance().process_errors(ErrorTypes(result));
                    }
                }
                break;
            case '2':
                {
                    number x;
                    std::cout<<"Enter the x value:\n";
                    std::cout<<"x= ";
                    if (!(std::cin>>x))
                    {
                         TApplication::instance().process_errors(InvalidInput);
                         break;
                    }
                    number result =TPolinom::instance().value(x);
                    std::cout<<"p("<<x<<")= "<<result<<"\n";
                }
                break;
            case '3':
                TPolinom::instance().roots();
                break;
            case '4':
                {
                    TPolinom::instance().setPrintMode(EPrintModeClassic);
                    std::cout<<TPolinom::instance();
                }
                break;
            case '5':
                {
                    TPolinom::instance().setPrintMode(EPrintModeCanonic);
                    std::cout<<TPolinom::instance();
                }
                break;
            default:
                    TApplication::instance().process_errors(InvalidInput);
                break;
        }
    }
}

char TApplication::menu()
{
    char ch[10];
    std::cout<<"Menu: press a key to choose\n";
    std::cout<<"1. Set coefficients\n";
    std::cout<<"2. Find value\n";
    std::cout<<"3. Find roots\n";
    std::cout<<"4. Print the polinom(classic)\n";
    std::cout<<"5. Print the polinom(canonical)\n";
    std::cout<<"0. Exit\n"<<"> ";
    std::cin>>ch;
    return ch[0];
}

void TApplication::process_errors(ErrorTypes error)
{
    if(error==InvalidInput)
    {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout<<"Invalid input\n";
    }
    if(error==NullA)
    {
        std::cout<<"a should be not null\n";
    }
}
