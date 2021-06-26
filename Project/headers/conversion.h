#ifndef CONVERSION_H_INCLUDED
#define CONVERSION_H_INCLUDED

#include <bits/stdc++.h>
#include <windows.h>
#define ENCRYPTION_KEY 15
using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);   //Decleration of handle which is used to colour text

template <typename T>
string itos(T i)        //function to convert any datatype like int,float,double,char to string
{
    stringstream s;
    s << i;
    return s.str();
}

string encrypt(string fname) //function to encrypt string using caesar cipher and encryption Key
{
    int key = ENCRYPTION_KEY;
    key = key % 26;
    int num_key = key % 10;

    for (int i = 0; i < fname.size(); i++)
    {

        if (fname[i] >= 'A' && fname[i] <= 'Z')
        {
            fname[i] = char(int(fname[i] + key - 65) % 26 + 65);
        }
        else if (fname[i] >= 'a' && fname[i] <= 'z')
        {
            fname[i] = char(int(fname[i] + key - 97) % 26 + 97);
        }
        else if (fname[i] >= '0' && fname[i] <= '9')
        {
            fname[i] = char(int(fname[i] + num_key - 48) % 10 + 48);
        }
    }

    return fname;
}
string decrypt(string fname)        //function to decrypt string using caesar cipher and encryption key
{
    int key = ENCRYPTION_KEY;
    key = key % 26;
    int num_key = key % 10;
    key = 26 - key;
    num_key = 10 - num_key;

    for (int i = 0; i < fname.size(); i++)
    {
        if (fname[i] >= 'A' && fname[i] <= 'Z')
        {
            fname[i] = char(int(fname[i] + key - 65) % 26 + 65);
        }
        //If the message to be decypted is in upper case.
        else if (fname[i] >= 'a' && fname[i] <= 'z')
        {
            fname[i] = char(int(fname[i] + key - 97) % 26 + 97);
        }
        //fs.seekp(fs.tellp());
        else if (fname[i] >= '0' && fname[i] <= '9')
        {
            fname[i] = char(int(fname[i] + num_key - 48) % 10 + 48);
        }
    }
    return fname;
}


#endif // CONVERSION_H_INCLUDED
