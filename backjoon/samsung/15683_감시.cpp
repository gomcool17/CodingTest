#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void what_N(int cnt, int cctv_N);

int N, M;
int map[8][8];
int c;
int check[8][8];
vector<pair<int, int>> v;
int re = 987654321;

// doo = true => cctv활성
// doo = false => cctv비활성
void right(int cnt, int x, bool doo)
{
    int y = v[cnt].first;

    if (doo)
    {
        for (int i = x; i < M; i++)
        {
            if (map[y][i] == 6)
                break;

            if (map[y][i] == 0)
                check[y][i]++;
        }
    }
    else
    {
        for (int i = x; i < M; i++)
        {
            if (map[y][i] == 6)
                break;

            if (map[y][i] == 0)
                check[y][i]--;
        }
    }
}

void left(int cnt, int x, bool doo)
{
    int y = v[cnt].first;

    if (doo)
    {
        for (int i = x; i >= 0; i--)
        {
            if (map[y][i] == 6)
                break;

            if (map[y][i] == 0)
                check[y][i]++;
        }
    }
    else
    {
        for (int i = x; i >= 0; i--)
        {
            if (map[y][i] == 6)
                break;

            if (map[y][i] == 0)
                check[y][i]--;
        }
    }
}

void up(int cnt, int y, bool doo)
{
    int x = v[cnt].second;

    if (doo)
    {
        for (int i = y; i >= 0; i--)
        {
            if (map[i][x] == 6)
                break;

            if (map[i][x] == 0)
                check[i][x]++;
        }
    }
    else
    {
        for (int i = y; i >= 0; i--)
        {
            if (map[i][x] == 6)
                break;

            if (map[i][x] == 0)
                check[i][x]--;
        }
    }
}

void down(int cnt, int y, bool doo)
{
    int x = v[cnt].second;

    if (doo)
    {
        for (int i = y; i < N; i++)
        {
            if (map[i][x] == 6)
                break;

            if (map[i][x] == 0)
                check[i][x]++;
        }
    }
    else
    {
        for (int i = y; i < N; i++)
        {
            if (map[i][x] == 6)
                break;

            if (map[i][x] == 0)
                check[i][x]--;
        }
    }
}

void sol(int cnt)
{

    if (cnt >= c)
    {
        int r = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (check[i][j] == 0)
                    r++;
            }
        }

        re = min(r, re);
       
        return;
    }

    what_N(cnt, map[v[cnt].first][v[cnt].second]);

    return;
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
            if (map[i][j] != 0)
            {
                check[i][j] = 1;
                if (map[i][j] != 6)
                {
                    v.push_back({i, j});
                    c++;
                }
            }
        }
    }

    sol(0);
    cout << re << "\n";
}

void what_N(int cnt, int cctv_N)
{
    if (cctv_N == 1)
    {
        //오른쪽
        right(cnt, v[cnt].second, true);
        sol(cnt + 1);
        right(cnt, v[cnt].second, false);

        //왼쪽
        left(cnt, v[cnt].second, true);
        sol(cnt + 1);
        left(cnt, v[cnt].second, false);

        //위
        up(cnt, v[cnt].first, true);
        sol(cnt + 1);
        up(cnt, v[cnt].first, false);

        //아래
        down(cnt, v[cnt].first, true);
        sol(cnt + 1);
        down(cnt, v[cnt].first, false);
    }
    else if (cctv_N == 2)
    {
        right(cnt, v[cnt].second, true);
        left(cnt, v[cnt].second, true);
        sol(cnt + 1);
        right(cnt, v[cnt].second, false);
        left(cnt, v[cnt].second, false);

        up(cnt, v[cnt].first, true);
        down(cnt, v[cnt].first, true);
        sol(cnt + 1);
        up(cnt, v[cnt].first, false);
        down(cnt, v[cnt].first, false);
    }
    else if (cctv_N == 3)
    {
        up(cnt, v[cnt].first, true);
        right(cnt, v[cnt].second, true);
        sol(cnt + 1);
        up(cnt, v[cnt].first, false);
        right(cnt, v[cnt].second, false);

        right(cnt, v[cnt].second, true);
        down(cnt, v[cnt].first, true);
        sol(cnt + 1);
        right(cnt, v[cnt].second, false);
        down(cnt, v[cnt].first, false);

        down(cnt, v[cnt].first, true);
        left(cnt, v[cnt].second, true);
        sol(cnt + 1);
        down(cnt, v[cnt].first, false);
        left(cnt, v[cnt].second, false);

        left(cnt, v[cnt].second, true);
        up(cnt, v[cnt].first, true);
        sol(cnt + 1);
        left(cnt, v[cnt].second, false);
        up(cnt, v[cnt].first, false);
    }
    else if (cctv_N == 4)
    {
        right(cnt, v[cnt].second, true);
        left(cnt, v[cnt].second, true);
        up(cnt, v[cnt].first, true);
        sol(cnt + 1);
        right(cnt, v[cnt].second, false);
        left(cnt, v[cnt].second, false);
        up(cnt, v[cnt].first, false);

        up(cnt, v[cnt].first, true);
        down(cnt, v[cnt].first, true);
        right(cnt, v[cnt].second, true);
        sol(cnt + 1);
        up(cnt, v[cnt].first, false);
        down(cnt, v[cnt].first, false);
        right(cnt, v[cnt].second, false);

        right(cnt, v[cnt].second, true);
        left(cnt, v[cnt].second, true);
        down(cnt, v[cnt].first, true);
        sol(cnt + 1);
        right(cnt, v[cnt].second, false);
        left(cnt, v[cnt].second, false);
        down(cnt, v[cnt].first, false);

        up(cnt, v[cnt].first, true);
        down(cnt, v[cnt].first, true);
        left(cnt, v[cnt].second, true);
        sol(cnt + 1);
        up(cnt, v[cnt].first, false);
        down(cnt, v[cnt].first, false);
        left(cnt, v[cnt].second, false);
    }
    else
    {
        right(cnt, v[cnt].second, true);
        left(cnt, v[cnt].second, true);
        up(cnt, v[cnt].first, true);
        down(cnt, v[cnt].first, true);
        sol(cnt + 1);
        right(cnt, v[cnt].second, false);
        left(cnt, v[cnt].second, false);
        up(cnt, v[cnt].first, false);
        down(cnt, v[cnt].first, false);
    }
}