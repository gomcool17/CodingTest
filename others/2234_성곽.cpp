#include <bits/stdc++.h>

using namespace std;
int N, M;
int board[50][50];
int all, mwitdh, wbreak;

int dir[4] = {1, 2, 4, 8}; //  ¼­ ºÏ µ¿ ³²
int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};

bool visits[50][50];

int sol(int idx, int jdx)
{
    queue<pair<int, int>> q;
    q.push({idx, jdx});

    int cnt = 1;

    while (!q.empty())
    {
        int ny = q.front().first;
        int nx = q.front().second;
        q.pop();
        visits[ny][nx] = true;

        for (int i = 0; i < 4; i++)
        {
            int y = ny + dy[i];
            int x = nx + dx[i];
            int n = board[ny][nx] & dir[i];
            if (n == 0)
            {
                if (y >= 0 && x >= 0 && y < M && x < N && !visits[y][x])
                {
                    cnt++;
                    visits[y][x] = true;
                    q.push({y, x});
                }
            }
        }
    }

    return cnt;
}

int main()
{
    cin >> N >> M;
    vector<int> l;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visits[i][j])
            {
                all++;
                int n = sol(i, j);
                mwitdh = max(mwitdh, n);
                l.push_back(n);
            }
        }
    }

    cout << all << "\n";
    cout << mwitdh << "\n";

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 1; k <= 8; k *= 2)
            {
                if (board[i][j] & k == k)
                {
                    fill(&visits[0][0], &visits[49][50], false);
                    board[i][j] -= k;
                    wbreak = max(wbreak, sol(i, j));
                    board[i][j] += k;
                }
            }
        }
    }

    cout << wbreak << "\n";
}