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
    void process_errors(ErrorTypes);
private:
    char menu();
};

#endif // TAPPLICATION_H
