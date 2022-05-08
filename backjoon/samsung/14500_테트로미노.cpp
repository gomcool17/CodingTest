#include <bits/stdc++.h>

using namespace std;

int N, M;
int board[500][500];
int check[500][500];
int re = 0;
struct DIR
{
    int y, x;
};

DIR dir[4] = {{0, 1}, {0,-1}, {1,0}, {-1,0}};

void dfs(int y, int x, int cnt, int sum)
{
    if (cnt >= 4)
    {
        re = max(re, sum);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int dy = y + dir[i].y;
        int dx = x + dir[i].x;
    
        if (dy >= 0 && dx >= 0 && y < N && x < M && !check[dy][dx])
        {
            check[dy][dx] = true;
            dfs(dy, dx, cnt + 1, sum + board[dy][dx]);
            check[dy][dx] = false;
        }
    }
}

void notDFS(int y, int x)
{
    // ㅗ
    if (x - 1 >= 0 && x + 1 < M && y - 1 >= 0)
    {
        re = max(board[y][x] + board[y][x - 1] + board[y][x + 1] + board[y - 1][x], re);
    }

    // ㅜ
    if (x - 1 >= 0 && x + 1 < M && y + 1 < N)
    {
        re = max(board[y][x] + board[y][x - 1] + board[y][x + 1] + board[y + 1][x], re);
    }

    // ㅏ
    if (y - 1 >= 0 && y + 1 < N && x + 1 < M)
        re = max(board[y - 1][x] + board[y + 1][x] + board[y][x + 1] + board[y][x], re);
    // ㅓ
    if (y - 1 >= 0 && y + 1 < N && x - 1 >= 0)
        re = max(board[y - 1][x] + board[y + 1][x] + board[y][x - 1] + board[y][x], re);

    return;
}
int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            check[i][j] = true;
            dfs(i, j, 1, board[i][j]);
            notDFS(i, j);
            check[i][j] = false;
        }
    }

    cout << re << "\n";
}