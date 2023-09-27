#ifndef DES_H
#define DES_H
#include <string>
#include <vector>
#include "EmailSystem.h"
using namespace std;

class DES: public EmailSystem
{
    public:
        DES();
        void InputData(string,string);
        string hex2bin(string);
        string bin2hex(string);
        string permute(string,int*,int);
        string shift_left(string,int);
        string xor_(string,string);
        void Decrypt();
        void Encrypt();
    private:
        string PlainText;
        string key;
        string orgkey;
        bool ShowData;
        vector<string> rkb; // rkb for RoundKeys in binary
        vector<string> rk; // rk for RoundKeys in hexadecimal
};

#endif // DES_H
