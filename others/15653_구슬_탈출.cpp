#include <bits/stdc++.h>

using namespace std;

#define NM 10
#define INF 987654321

int N, M;
char board[NM][NM];
int cnt[NM][NM];
bool check_red[NM][NM];
bool check_blue[NM][NM];
queue<pair<int, int>> rq;
queue<pair<int, int>> bq;

int re = 987654321;
int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};
int pre_ry = 0;
int pre_rx = 0;

void sol()
{

   
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'R')
            {
                rq.push({i, j});
                pre_ry = i;
                pre_rx = j;
            }
            if (board[i][j] == 'B')
                bq.push({i, j});
        }

    sol();

    if (re == INF)
        cout << "-1";
    else
        cout << re;
}