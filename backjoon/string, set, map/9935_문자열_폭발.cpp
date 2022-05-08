#include <iostream>
#include <string>
#include <vector>

using namespace std;

char result[1000001];

int main()
{
    string s, t;
    cin >> s >> t;
    int lo = 0;
    int boom_size = t.size();
    for (int i = 0; i < s.size(); i++)
    {
        bool flag = true;
        result[lo++] = s[i];
        int n = boom_size - 1;
        if (s[i] == t[n])
        {
            for (int j = lo - 1; j >= lo - boom_size; j--)
            {
                if (result[j] == t[n])
                {
                    n--;
                    flag = false;
                }
                else
                {
                    flag = true;
                    break;
                }
            }
        }
        if (!flag)
        {
            lo -= boom_size;
        }
    }

    if (lo == 0)
        cout << "FRULA\n";
    else
    {
        for (int i = 0; i < lo; i++)
            cout << result[i];
        cout << "\n";
    }
}