#ifndef TAPPLICATION_H
#define TAPPLICATION_H

enum ErrorTypes
{
    InvalidInput=10,
    NullA,
};

class TApplication
{
public:
    TApplication();
    static TApplication& instance();
    int exec();
    char menu();
    void process_errors(ErrorTypes);
};

#endif // TAPPLICATION_H
