#include <iostream>
#include <ctype.h>
#include <stdlib.h>
#include <fstream>
#include "CaesarCipher.h"
#include "RSA.h"
#include "DES.h"
#include "EmailSystem.h"
using namespace std;

int main()
{
    cout << "This program is used to conduct a survey about our new product." << endl;
    cout << "Before moving to the actual part of the program, it is essential to know a couple of things: " << endl;
    cout << "-> Information collected in this survey will not be used anywhere." << endl;
    cout << "-> The suggestions should not exceed 200 words" << endl;
    int cand;
    cout << "Enter the number of the candidates in the survey: ";
    cin >> cand;
    ofstream Encrypted;
    Encrypted.open("Suggestions.txt", ios::in);
    Encrypted << "\t\t\tEncrypted File\n\n";
    ofstream Decrypted;
    Decrypted.open("Suggestions_Decrypted.txt", ios::in);
    Decrypted << "\t\t\tDecrypted file\n\n";
    CaesarCipher CC[cand];
    RSA rsa[cand];
    DES des[cand];
    for (int loop = 0; loop < cand; loop++)
    {
        char choice;
        cout << "Are you an employee of the company? (Y/N)  ";
        cin >> choice;
        while (choice != 'Y' && choice != 'N')
        {
            cout << "Enter Y or N only please: ";
            cin >> choice;
        }
        cin.ignore();
        if (choice == 'N')
            EmailSystem::Employee = false;
        string name, message, macaddress;
        int shift = 0;
        cout << "Enter the name of the sender: ";
        getline(cin, name);
        // If junior then use CC.Encrypt(name);
        if (EmailSystem::Employee)
        {
            cout << "Enter any random number between 1-10: ";
            cin >> shift;
            while (shift <= 0)
            {
                cout << "Enter a valid key: ";
            }
        }
        CC[loop].InputData(name, shift);
        cin.ignore();
        long int p1 = 0, p2 = 0;
        cout << "Enter the message: ";
        getline(cin, message);
        if (EmailSystem::Employee)
        {
            do
            {
                cout << "Enter the first prime number: ";
                cin >> p1;
            } while (RSA::prime(p1));
            do
            {
                cout << "Enter the second prime number: ";
                cin >> p2;
            } while (RSA::prime(p2));
        }
        /*If junior member then use RSA::prime(rand()%100) to pass 2 prime numbers to the program.*/
        rsa[loop].InputData(message, p1, p2);
        // DES Starts here
        string key = "Def", bigmac;
        if (EmailSystem::Employee)
        {
            bool decide = true;
            do
            {
                cout << "Enter a 16-digit key: ";
                cin >> key;
                for (int i = 0; i < 16; ++i)
                {
                    if (!isxdigit(key[i]))
                        decide = false;
                }
            } while (key.size() != 16 || decide == false);
        }
        bool decide = true;
        do
        {
            cout << "Enter your MAC Address without the colons(:): ";
            cin >> bigmac;
            for (int i = 0; i < 12; ++i)
            {
                if (!isxdigit(bigmac[i]))
                    decide = false;
            }
        } while (bigmac.size() != 12 || decide == false);
        bigmac.append("000");
        bigmac += to_string(loop);
        cout << bigmac;
        des[loop].InputData(bigmac, key);
        EmailSystem::Employee = true;
    }
    int code;
    cout << "\nAll the encrypted data is stored in a file named 'Suggestions.txt'" << endl;
    cout << "To decrypt the data and view it. You need to enter the Operation Manager code: ";
    cin >> code;
    bool go_on = true;
    do
        if (code == 911)
        {
            go_on = false;
            for (int i = 0; i < cand; i++)
            {
                cout << "Name: ";
                CC[i].Decrypt();
                cout << endl
                     << "Message: ";
                rsa[i].Decrypt();
                cout << endl
                     << "MAC Address: ";
                des[i].Decrypt();
                cout << endl
                     << endl;
            }
        }
    while (go_on);
    cout << "A file name 'Suggestions_Decrypted.txt' is created if you want to print all the suggestions. ";
    cout << "The file also contains all the keys used in each encryption for security purposes. " << endl;
    cout << "Have a nice day!";

    return 0;
}
