#include <bits/stdc++.h>

using namespace std;

#define INF 987654321

int N, M;
int board[50][50];
vector<pair<int, int>> house, chicken;
bool check[13];
int re = INF;

int distance(pair<int, int> a, pair<int, int> b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void dfs(int idx, int cnt)
{
    if (cnt == M)
    {
        int ans = 0;
        for (int i = 0; i < house.size(); i++)
        {
            int dist = INF;
            for (int j = 0; j < chicken.size(); j++)
            {
                if (check[j])
                    dist = min(dist, distance(house[i], chicken[j]));
            }
            ans += dist;
        }

        re = min(ans, re);
        return;
    }

    if (idx == chicken.size())
        return;

    check[idx] = true;
    dfs(idx + 1, cnt + 1);
    check[idx] = false;
    dfs(idx + 1, cnt);
}
int main()
{
    cin >> N >> M;
    int n = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 2)
            {
                chicken.push_back({i, j});
                n++;
            }
            if (board[i][j] == 1)
                house.push_back({i, j});
        }

   // M = n - M;
    dfs(0, 0);
    cout << re << "\n";
}