#include <bits/stdc++.h>

using namespace std;

#define SAFE 0
#define WALL 1
#define VIRUS 2

int N, M;
int board[8][8];
bool check[8][8];
vector<pair<int, int>> v;
int re = 0;

struct DIR
{
    int y, x;
};

DIR dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void bfs()
{
    queue<pair<int, int>> q;
    bool visit[8][8];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            visit[i][j] = check[i][j];

    for (int i = 0; i < v.size(); i++)
    {
        q.push({v[i].first, v[i].second});
    }

    while (!q.empty())
    {
        int ny = q.front().first;
        int nx = q.front().second;
       
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int y = ny + dir[i].y;
            int x = nx + dir[i].x;

            if (y >= 0 && x >= 0 && y < N && x < M && !visit[y][x] && !check[y][x])
            {
                visit[y][x] = true;
                q.push({y, x});
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (!visit[i][j])
                cnt++;
        }
    }

    re = max(cnt, re);

    return;
}

void dfs(int y, int x, int cnt)
{
    if (cnt > 3)
    {
        
        bfs();
        return;
    }
  
    if (x >= M){
        dfs(y + 1, 0, cnt);
        return;
    }

    if (y >= N)
        return;

   // cout << y << " " << x << "\n";
    if (board[y][x] == SAFE)
    {
        board[y][x] = WALL;
        check[y][x] = true;
        dfs(y, x + 1, cnt + 1); //벽 세우기
        check[y][x] = false;
        board[y][x] = SAFE;
    }

    dfs(y, x + 1, cnt); //벽 안세우기

    return;
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];

            if (board[i][j] == VIRUS)
                v.push_back({i, j});

            if (board[i][j] == VIRUS || board[i][j] == WALL)
                check[i][j] = true;
        }
    }
    
    dfs(0, 0, 1);
    cout << re << "\n";
}