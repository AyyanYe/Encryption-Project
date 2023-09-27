#include "CaesarCipher.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
CaesarCipher::CaesarCipher()
{

}
void CaesarCipher::InputData(string s,int shift)
{
    while (shift <= 0)
    {
        shift = rand()%6;
    }
    key = shift;
    //To convert string into char array
    s.copy(msg,s.size()+1);
    msg[s.size()] = '\0';
    Encrypt();
}
void CaesarCipher::Encrypt()
{
    char temp;
    for(int i = 0; msg[i] != '\0'; ++i)
        {
         temp = msg[i];
         //encrypt for lowercase letter
         if (temp >= 'a' && temp <= 'z')
         {
            temp = temp + key;
            if (temp > 'z')
            {
               temp = temp - 'z' + 'a' - 1;
            }
            msg[i] = temp;
         }
         //encrypt for uppercase letter
         else if (temp >= 'A' && temp <= 'Z')
         {
            temp = temp + key;
            if (temp > 'Z')
            {
               temp = temp - 'Z' + 'A' - 1;
            }
            msg[i] = temp;
         }
      }
    cout << "Encrypted message: " << msg << endl;
    ofstream Encrypted;
    Encrypted.open("Suggestions.txt",ios::app);
    Encrypted << "*****************************************" << endl;
    Encrypted << endl << "Name: " << msg << endl;
}
void CaesarCipher::Decrypt()
{
    //To convert string into char array
    char temp;
    for(int i = 0; msg[i] != '\0'; ++i)
    {
         temp = msg[i];
         //decrypt for lowercase letter
         if(temp >= 'a' && temp <= 'z')
         {
            temp = temp - key;
            if(temp < 'a')
            {
               temp = temp + 'z' - 'a' + 1;
            }
            msg[i] = temp;
         }
         //decrypt for uppercase letter
         else if(temp >= 'A' && temp <= 'Z')
          {
            temp = temp - key;
            if(temp < 'A')
            {
               temp = temp + 'Z' - 'A' + 1;
            }
            msg[i] = temp;
         }
      }
      cout << msg;
      ofstream Decrypted;
      Decrypted.open("Suggestions_Decrypted.txt",ios::app);
      Decrypted << "********************" << endl;
      Decrypted << endl << endl << "(Caesar's Cipher was used to encrypt name with the key being " << key << ")" << endl;
      Decrypted << "Name: " << msg << endl;
}

