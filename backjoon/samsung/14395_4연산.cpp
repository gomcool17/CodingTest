#include <bits/stdc++.h>

using namespace std;
string result="";
long long S, t;
set<long long> se;

bool cmp(string A, string B)
{
    return A.length() > B.length();
}
void bfs()
{
    queue<pair<long long, string>> q;
    string s = "";

    bool flag = false;
    q.push({S, s});

    while (!q.empty())
    {
        long long now = q.front().first;
        string ns = q.front().second;
        q.pop();

    
        if (now == t)
        {  
            result += ns;
            return;
        }

        long long n = now * now;
        if (n <= t)
        {
            if (se.find(n) != se.end())
                continue;
            q.push({n, ns + "*"});
        }

        n = now + now;
        if (n <= t)
        {
            if (se.find(n) != se.end())
                continue;
            q.push({n, ns + "+"});
        }

        n = now / now;
        if (n <= t && !flag)
        {
            if (se.find(n) != se.end())
                continue;

            q.push({n, ns + "/"});
            flag = true;
        }

        se.insert(now);
    }
}
int main()
{
    cin >> S >> t;
    bfs();

    if (result.size() == 0)
        cout << "-1";
    else if (S == t)
        cout << 0;
    else
    {
        // sort(result.begin(), result.end());
        cout << result;
    }

    return 0;
}