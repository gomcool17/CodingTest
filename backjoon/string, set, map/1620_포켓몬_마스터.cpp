#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    map<string, int> m;
    map<int, string> m2;

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        m.insert({s, i + 1});
        m2.insert({i + 1, s});
    }

    for (int i = 0; i < M; i++)
    {
        string s;
        cin >> s;
      
        if (isdigit(s[0]) == true)
        {
            int n = stoi(s);
            cout << m2[n] << "\n";
        }
        else
        {
            cout << m[s] << "\n";
        }
    }
}