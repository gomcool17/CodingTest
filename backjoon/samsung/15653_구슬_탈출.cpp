#include <bits/stdc++.h>

using namespace std;

#define NM 10
#define INF 987654321

int N, M;
char board[NM][NM];
bool visit[NM][NM][NM][NM];

int re = 987654321;
int dir[2] = {1, -1};

int rx, ry, bx, by = 0;

struct INFO
{
    int ry, rx;
    int by, bx;
    int cnt;
};

void sol()
{
    queue<INFO> q;
    q.push({ry, rx, by, bx, 0});

    while (!q.empty())
    {
        ry = q.front().ry;
        rx = q.front().rx;
        by = q.front().by;
        bx = q.front().bx;
        int cnt = q.front().cnt;
        for (int d = 0; d < 2; d++)
        {
            int nry = ry;
            int nrx = rx;
            while (board[ry][nrx] != 'O' && board[ry][nrx] != '#')
            {
                //오른쪽 && 아래
                nrx += dir[d];
            }

            int nby = by;
            int nbx = bx;

            while (board[ry][nrx] != 'O' && board[ry][nrx] != '#')
            {
                nbx += dir[d];
            }

            if(board[ry][nrx] == 'O' && board[by][nbx] != 'O')
            {
                re = min(cnt, re);
            }
            if (ry == by && nrx == nbx)
            {
                if (rx > bx)
                    nbx--;
                else
                    nrx--;
            }

        }
    }
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'R')
                ry = i, rx = j;

            if (board[i][j] == 'B')
                by = i, bx = j;
        }

    sol();

    if (re == INF)
        cout << "-1";
    else
        cout << re;
}