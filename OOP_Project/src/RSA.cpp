#include "RSA.h"
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <fstream>
using namespace std;

RSA::RSA()
{

}
void RSA::InputData(string a,long int p1,long int p2)
{
    while (p1 <= 1 || p2 <= 1)
    {
        while (p1 >= p2)
        {
            do
            {
                srand(time(0));
                p1 = rand() % 50;
            }while (prime(p1));
            do
            {
                srand(time(0));
                p2 = rand() % 100;
            }while (prime(p2));
        }
            cout << p1 << " " << p2;
    }
    fprime = p1;
    sprime = p2;
    ms = a;
    PublicKey = fprime * sprime;
    coprime = (fprime - 1) * (sprime - 1);
    CalculatingEncryptionKey();
    Encrypt();
}
bool RSA::prime(long int n)
{
    int j = sqrt(n); //
    for (int i = 2; i <= j; ++i)
    {
        if (n % i == 0)
            return true;
    }
    return false;
}
void RSA::CalculatingEncryptionKey() //choosing the first best combination of
{
    int s = 0;
    for (int i = 2; i < coprime; i++)
    {
        if (coprime % i == 0)
            continue;
        if (!prime(i) && i != fprime && i != sprime)
        {
            EncryptionKey[s] = i;
            int temp = CalculatingDecryptionKey(EncryptionKey[s]);
            if (temp > 0)
            {
                DecryptionKey[s] = temp;
                s++;
            }
            if (s == 99) //This is basically to limit the calculation for the possible values of Public Key and Private Key
                break;
        }
    }
}
long int RSA::CalculatingDecryptionKey(int in)
{
    long int s = 1;
    while(1)
    {
        s = s + coprime;
        if (s % in == 0)
            return ( s / in );
    }
}
void RSA::Encrypt()
{
    //This is to convert string into char array
    KeyUsed = EncryptionKey[0];
    for (int i = 0; ms[i] != '\0';i++)
    {
        msg[i] = ms[i];
    }
    long int len = ms.size();
    long int t,temp;
    for(int i = 0; i != len; ++i)
        {
         temp = msg[i];
         t = 1;
         temp = temp - 96;
         for (int j = 0; j < KeyUsed; ++j)
            {
                t = t * temp;
                t = t % PublicKey;
            }
            temp = t;
            msg[i] = temp;
            encrypted[i] = temp + 96;
      }
    cout << endl << "Encrypted message: " << encrypted << endl;
    ofstream Encrypted;
    Encrypted.open("Suggestions.txt",ios::app);
    Encrypted << "Message recorded: " << encrypted << endl;
    encrypted[len] = -1;
}
void RSA::Decrypt()
{
    KeyUsed = DecryptionKey[0];
    long int temp;
    long int t;
    for(int i = 0; encrypted[i] != -1 ; ++i)
        {
         temp = msg[i];
         t = 1;
         for (int j = 0; j < KeyUsed; ++j)
            {
                t = t * temp;
                t = t % PublicKey;
            }
            temp = t;
            decrypted[i] = temp + 96;
         }
         cout << decrypted << "\b\b";
         ofstream Decrypted;
         Decrypted.open("Suggestions_Decrypted.txt",ios::app);
         Decrypted << "(RSA was used to encrypt this message with " << EncryptionKey[0] << " being the encryption key";
         Decrypted << " and " << DecryptionKey[0] << " being the decryption key)" << endl;
         Decrypted << "Message: " << decrypted << "\b\b" << endl;
}
