#ifndef RSA_H
#define RSA_H
#include <string>
#include "EmailSystem.h"
using namespace std;

class RSA: public EmailSystem
{
    public:
        RSA();
        void InputData(string, long int, long int);
        void Decrypt();
        static bool prime(long int);
    protected:
        void CalculatingEncryptionKey();
        long int CalculatingDecryptionKey(int);
        void Encrypt();
        void PublicKeyGenerator(long int,long int);
    private:
        string ms;
        long int fprime;
        long int sprime;
        long int coprime;
        long int PublicKey;
        long int EncryptionKey[100];
        long int DecryptionKey[100];
        int KeyUsed;
        long int msg[100];
        char encrypted[100];
        char decrypted[100];
};

#endif // RSA_H
