#include <bits/stdc++.h>

using namespace std;

#define R 2
#define L 6
#define S 1
#define N 0

int board[6][8];
int record[5][8];
int K;
bool check[6];
vector<pair<int, int>> v;

void rotate(int dir, int n)
{
    if (dir == 1)
    {
        int n8 = board[n][7];
        for (int i = 7; i > 0; i--)
        {
            board[n][i] = board[n][i - 1];
        }
        board[n][0] = n8;
    }
    else
    {
        int n0 = board[n][0];
        for (int i = 0; i < 7; i++)
        {
            board[n][i] = board[n][i + 1];
        }
        board[n][7] = n0;
    }

    return;
}

void sol(int idx)
{
    int n = v[idx].first;
    int dir = v[idx].second;

    rotate(dir, n); //ÀÏ´Ü ÇØ´ç Åé´Ï È¸Àü

    check[n] = true;
    int i = n + 1;
    int d = -dir;

    while (i <= 4) // ÇØ´ç Åé´ÏÀÇ ¿À¸¥ÂÊ Åé´Ïµé Å½»ö
    {
        if (record[i - 1][R] != board[i][L])
        {
            rotate(d, i);
        }
        else
            break;

        i++;
        d = -d;
    }

    i = n - 1;
    d = -dir;

    while (i > 0) // ¿ÞÂÊ Åé´Ïµé Å½»ö
    {
        if (record[i + 1][L] != board[i][R])
        {
            rotate(d, i);
        }
        else
            break;

        i--;
        d = -d;
    }

    return;
}

int main()
{
    int re = 0;

    for (int i = 1; i <= 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            char c;
            cin >> c;
            board[i][j] = c - '0';
        }
    }

    cin >> K;
    for (int i = 0; i < K; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    for (int i = 0; i < 8; i++)
    {
        board[0][i] = -1;
        board[5][i] = -1;
    }

    for (int i = 0; i < K; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            record[j][R] = board[j][R];
            record[j][L] = board[j][L];
        }
        sol(i);
    }

    if (board[1][0] == S)
        re += 1;
    if (board[2][0] == S)
        re += 2;
    if (board[3][0] == S)
        re += 4;
    if (board[4][0] == S)
        re += 8;

    cout << re << "\n";
}