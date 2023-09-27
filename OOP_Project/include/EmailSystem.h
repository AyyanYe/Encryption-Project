#ifndef EMAILSYSTEM_H
#define EMAILSYSTEM_H
#include <string>
using namespace std;
class EmailSystem
{
    public:
        virtual void Encrypt() = 0;
        virtual void Decrypt() = 0;
        static bool Employee;
};

#endif // EMAILSYSTEM_H
