#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    //! cin.eof() : 입력이 없을때까지
    string str;
    while (!cin.eof())
    {
        getline(cin, str);
        cout << str << "\n";
    }
}