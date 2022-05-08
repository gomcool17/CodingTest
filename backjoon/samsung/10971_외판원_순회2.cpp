#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define NM 11

bool visit[NM];
int map[NM][NM];
int N;
int re = 987654321;
int start;

void sol(int v, int cnt, int sum)
{
    if (cnt == N)
    {
        if (map[v][start] > 0)
        {
            re = min(re, sum + map[v][start]);
        }
        return;
    }
    for (int i = 0; i < N; i++)
    {
        if (visit[i] || start == i)
            continue;
        if (map[v][i] == 0) //못가
            continue;

        visit[i] = true;
        sol(i, cnt + 1, sum + map[v][i]);
        visit[i] = false;
    }
}
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        start = i;
        visit[i] = true;
        sol(i, 1, 0);
        visit[i] = false;
    }
    cout << re;
}