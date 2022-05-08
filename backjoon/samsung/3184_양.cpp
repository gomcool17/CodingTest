#include <bits/stdc++.h>

using namespace std;

char maps[251][251];
bool check[251][251];
int R, C;
int v, o;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void bfs(int idx, int jdx)
{
    queue<pair<int, int>> q;
    int sheep = 0, wolf = 0;
    q.push({idx, jdx});
    bool flag = false;

    while (!q.empty())
    {
        int ny = q.front().first;
        int nx = q.front().second;
        q.pop();

        check[ny][nx] = true;
        if (maps[ny][nx] == 'v')
            wolf++;
        else if (maps[ny][nx] == 'o')
            sheep++;

        for (int i = 0; i < 4; i++)
        {
            int ndy = ny + dy[i];
            int ndx = nx + dx[i];

            if (check[ndy][ndx] || maps[ndy][ndx] == '#')
                continue;

            if (ndy == 0 || ndx == 0 || ndy == R - 1 || ndx == C - 1)
            {
                if (maps[ndy][ndx] == '.')
                    check[ndy][ndx] = true;

                continue;
            }
            else // 'v' 'o' '.'
            {
                q.push({ndy, ndx});
                check[ndy][ndx] = true;
            }
        }
    }
   
    if (wolf < sheep)
    {
        v -= wolf;
    }
    else
    {
        o -= sheep;
    }

    return;
}

int main()
{
    cin >> R >> C;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> maps[i][j];
            if (maps[i][j] == 'v')
            {
                v++;
            }
            else if (maps[i][j] == 'o')
            {
                o++;
            }
        }
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (check[i][j])
                continue;

            if (maps[i][j] == 'v')
            {
                bfs(i, j);
            }
        }
    }

    cout << o << " " << v;
}