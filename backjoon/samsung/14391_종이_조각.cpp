#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int map[5][5];
bool visit[5][5];
int N, M;
int re = 0;
bool flag;

void pluss()
{
    int sum = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (visit[i][j]) //가로로 더하기
            {
                int s = map[i][j];
                for (int k = j + 1; k < M; k++)
                {
                    if (visit[i][k])
                    {
                        s = s * 10 + map[i][k];
                        j++;
                    }
                    else
                        break;
                }
                sum += s;
            }
        }
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visit[j][i])
            {
                int s = map[j][i];
                for (int k = j + 1; k < N; k++)
                {
                    if (!visit[k][i])
                    {
                        s = s * 10 + map[k][i];
                        j++;
                    }
                    else
                        break;
                }
                sum += s;
            }
        }
    }

    re = max(re, sum);
    return;
}

void sol(int y, int x)
{
    if (x >= M)
    {
        sol(y + 1, 0);
        return;
    }

    if (y >= N)
    {
        pluss();
        return;
    }

    visit[y][x] = true;
    sol(y, x + 1);
    visit[y][x] = false;
    sol(y, x + 1);
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char c;
            cin >> c;
            map[i][j] = (int)(c - '0');
        }
    }

    sol(0, 0);
    cout << re << "\n";
}

// Robert Scheman Piano Quartet No.1 No2