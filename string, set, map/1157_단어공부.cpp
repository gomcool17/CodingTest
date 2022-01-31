#include <iostream>
#include <string>

using namespace std;

int count[26];

int main()
{
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            count[s[i] - 'a']++;
        }
        else
            count[s[i] - 'A']++;
    }

    int max = -1;
    int lo = 28;
    for (int i = 0; i < 26; i++)
    {
        if (max < count[i] && count[i] != 0)
        {
            lo = i;
            max = count[i];
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (max == count[i] && lo != i)
        {
            max = -1;
            break;
        }
    }

    if (max == -1)
        cout << "?";
    else
    {
        char re = lo + 'A';
        cout << re;
    }
}