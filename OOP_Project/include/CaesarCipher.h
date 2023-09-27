#ifndef CAESARCIPHER_H
#define CAESARCIPHER_H
#include <string>
#include "EmailSystem.h"
using namespace std;
class CaesarCipher: public EmailSystem
{
    public:
        CaesarCipher();
        void InputData(string,int);
        void Encrypt();
        void Decrypt();
    private:
        string Name;
        char msg[20];
        int key;
};

#endif // CAESARCIPHER_H
