#include <bits/stdc++.h>

using namespace std;

int N;
int S[21][21];
bool check[21];
int re = 987654321;

void sol(int idx, int cnt)
{
    if (cnt == N / 2)
    {
        int link = 0, start = 0;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (check[i] && check[j])
                {
                    link += S[i][j] + S[j][i];
                }
                else if (!check[i] && !check[j]){
                    start += S[i][j] + S[j][i];
                }
            }
        }

        re = min(re, abs(link - start));
        return;
    }
    for (int i = idx; i <= N; i++)
    {
        check[i] = true;
        sol(i + 1, cnt + 1);
        check[i] = false;
    }
}
int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> S[i][j];
        }
    }

    for (int i = 1; i <= N; i++)
    {
        check[i] = true;
        sol(i + 1, 1);
        check[i] = false;
    }

    cout << re / 2 << "\n";
}