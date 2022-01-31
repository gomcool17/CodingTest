#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<string> v;

    for (int i = 0; i < s.length(); i++)
    {
        string sub = s.substr(i);
        v.push_back(sub);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < s.length(); i++)
        cout << v[i] << "\n";
}