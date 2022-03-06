#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<string, double> m;

    string s;
    double cnt = 0;
    while (getline(cin, s))
    {
        cnt += 1;
        if (m.find(s) != m.end())
            m[s] += 1;
        else
            m[s] = 1;
    }

    cout << fixed;
    cout.precision(4);

    for (auto iter = m.begin(); iter != m.end(); iter++)
    {
        double re = (iter->second / cnt) * 100;
        cout << iter->first << " " << re << "\n";
    }
}
