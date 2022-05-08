#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int GCD(int a, int b)
{
    return b ? GCD(b, a % b) : a;
}

int LCM(int a, int b)
{
    return (a * b) / GCD(a, b);
}
int main()
{
    string s, t;
    cin >> s >> t;

    int n = LCM(s.length(), t.length());

    int i = 0;
    while (s.length() <= n)
    {
        s += s[i];
        i++;
        if (i >= s.length())
            i = 0;
    }
    i = 0;
    while (t.length() <= n)
    {
        t += t[i];
        i++;
        if (i >= t.length())
            i = 0;
    }

    if (t == s)
        cout << 1;
    else
        cout << 0;
}