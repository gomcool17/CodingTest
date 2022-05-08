#include <bits/stdc++.h>

using namespace std;

#define MN 21

int arr[MN][MN];
vector<int> student[401];
vector<int> s[401];

int N;
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first == b.first)
        return a.second < b.second;
    else
        return a.first < b.first;
}
int s1(int n)
{
    int favorite[5] = {0, 0, 0, 0, 0};
    int fm = 0;
    int fy, fx;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (arr[i][j] == 0)
            {
               // cout << i << " " << j << " ";
                int e = 0, f = 0;
                for (int d = 0; d < 4; d++)
                {
                    int y = i + dy[d];
                    int x = j + dx[d];
                    if (y >= 0 && x >= 0 && y < N && x < N)
                    {
                        if (arr[y][x] == student[n][1] || arr[y][x] == student[n][2] || arr[y][x] == student[n][3] || arr[y][x] == student[n][4])
                            f++;
                        else if (arr[y][x] == 0)
                            e++;
                    }
                }
                favorite[f]++;
               // cout << f << "\n";
                if (fm <= f)
                {
                    fm = f;
                    fy = i;
                    fx = j;
                }
            }
        }
    }

    if (favorite[fm] == 1) //최애 많은자리 1개
    {
        arr[fy][fx] = student[n][0];
        return -1;
    }
    else
    { // 1 조건 다 안되면
        return fm;
    }
}

int s2(int n, int fm)
{
    int empty[5] = {0, 0, 0, 0};
    int ey = 0, ex = 0;
    int em = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (arr[i][j] == 0)
            {
                int e = 0, f = 0;
                for (int d = 0; d < 4; d++)
                {
                    int y = i + dy[d];
                    int x = j + dx[d];
                    if (y >= 0 && x >= 0 && y < N && x < N)
                    {
                        if (arr[y][x] == student[n][1] || arr[y][x] == student[n][2] || arr[y][x] == student[n][3] || arr[y][x] == student[n][4])
                            f++;
                        else if (arr[y][x] == 0)
                            e++;
                    }
                }

                if (f == fm)
                {
                    // cout << i << " " << j << " " << e << "\n";
                    empty[e]++;
                    if (em <= e)
                    {
                        em = e;
                        ey = i;
                        ex = j;
                    }
                }
            }
        }
    }

    if (empty[em] == 1) // 빈자리 많은자리 1개
    {
        arr[ey][ex] = student[n][0];
        return -1;
    }
    else
    {
        return em;
    }
}

void s3(int n, int em, int fm)
{
    // cout << "s3 : " << student[n][0] << " " << em << " " << fm << "\n";
    vector<pair<int, int>> p;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (arr[i][j] == 0)
            {
                bool flag = false;
                int ey, ex;
                int e = 0;
                int f = 0;
                for (int d = 0; d < 4; d++)
                {
                    int y = i + dy[d];
                    int x = j + dx[d];

                    if (y >= 0 && x >= 0 && y < N && x < N)
                    {
                        if (arr[y][x] == student[n][1] || arr[y][x] == student[n][2] || arr[y][x] == student[n][3] || arr[y][x] == student[n][4])
                            f++;
                        if (arr[y][x] == 0)
                        {
                            if (!flag)
                            {
                                ey = y, ex = x;
                                flag = true;
                            }
                            e++;
                        }
                    }
                }

                if (f == fm && e == em)
                {
                    p.push_back({i, j});
                    // arr[ey][ex] = student[n][0];
                    // return;
                }
            }
        }
    }

    sort(p.begin(), p.end(), cmp);

    arr[p[0].first][p[0].second] = student[n][0];
}

void sol()
{
    for (int i = 0; i < N * N; i++)
    {
        int n = student[i][0];
        int re1 = s1(i);
        int re2;
        if (re1 != -1)
        {
            re2 = s2(i, re1);
            if (re2 != -1)
            {
                s3(i, re2, re1); // em  fm
            }
        }
    }

    return;
}

int ans()
{
    int sum = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int n = arr[i][j];
            // cout << n << " " << s[n][0] << " " << s[n][1] << " " << s[n][2] << " " << s[n][3] << "\n";
            int cnt = 0;
            for (int d = 0; d < 4; d++)
            {
                int y = i + dy[d];
                int x = j + dx[d];

                if (y >= 0 && x >= 0 && y < N && x < N)
                {
                    if (arr[y][x] == s[n][0] || arr[y][x] == s[n][1] || arr[y][x] == s[n][2] || arr[y][x] == s[n][3])
                        cnt++;
                }
            }

            if (cnt == 1)
                sum += 1;
            else if (cnt == 2)
                sum += 10;
            else if (cnt == 3)
                sum += 100;
            else if (cnt == 4)
                sum += 1000;
        }
    }

    return sum;
}
int main()
{
    cin >> N;
    for (int i = 0; i < N * N; i++)
    {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        student[i].push_back(a);
        student[i].push_back(b);
        student[i].push_back(c);
        student[i].push_back(d);
        student[i].push_back(e);
        s[a].push_back(b);
        s[a].push_back(c);
        s[a].push_back(d);
        s[a].push_back(e);
    }

    sol();

    cout << ans() << "\n";
}