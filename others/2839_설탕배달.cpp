#include <bits/stdc++.h>

using namespace std;

#define INF 987654321
int N;

bool sol(int n)
{
    int re = N - (n * 5);
    if (re % 3 == 0)
        return true;
    else
        return false;
}

int main()
{
    cin >> N;
    int re = INF;

    if (N % 5 == 0)
        re = N / 5;
    else if (N % 5 % 3 == 0)
    {
        re = N / 5 + N % 5 / 3;
    }
    else
    {
        int n = N / 5;

        while (n > -1)
        {
            if (sol(n))
            {
                int num = N - (n * 5);
                int le;
                le = num / 3 + n;
                re = min(re, le);
            }
            n--;
        }
    }

    if (re == INF)
        cout << -1 << "\n";
    else
        cout << re << "\n";
}