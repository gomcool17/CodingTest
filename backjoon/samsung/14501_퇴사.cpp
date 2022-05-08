#include <bits/stdc++.h>

using namespace std;

#define MN 17

int dp[MN];

int main()
{
    int N;
    int T[MN], P[MN];
    cin >> N;
    int re = 0;
    for (int i = 1; i <= N;i++)
    {
        cin >> T[i] >> P[i];
    }

    for (int i = 1; i <= N;i++)
    {
        int day = T[i] + i;
        if(day <= N + 1)
        {
            //cout << "day : " << day << " " << dp[i] << " " << P[i] << "\n";
            dp[day] = max(dp[day], dp[i] + P[i]);
            re = max(dp[day], re);
        }

        dp[i + 1] = max(dp[i], dp[i + 1]);
    }

    cout << re << "\n";
}
