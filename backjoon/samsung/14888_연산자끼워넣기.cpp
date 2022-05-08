#include <bits/stdc++.h>

using namespace std;

int op[4]; // + - * /
int N;
vector<int> v;
int Rmax = -1000000000;
int Rmin = 1000000000;

void sol(int idx, int re)
{
    if (idx == N)
    {
        Rmax = max(re, Rmax);
        Rmin = min(re, Rmin);

        return;
    }

    if (op[0] != 0)
    {
        op[0]--;
        sol(idx + 1, re + v[idx]);
        op[0]++;
    }

    if (op[1] != 0)
    {
        op[1]--;
        sol(idx + 1, re - v[idx]);
        op[1]++;
    }

    if (op[2] != 0)
    {
        op[2]--;
        sol(idx + 1, re * v[idx]);
        op[2]++;
    }

    if (op[3] != 0)
    {
        op[3]--;
        sol(idx + 1, re / v[idx]);
        op[3]++;
    }

    return;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        v.push_back(n);
    }

    for (int i = 0; i < 4; i++)
    {
        cin >> op[i];
    }
    sol(1, v[0]);

    cout << Rmax << "\n";
    cout << Rmin << "\n";

    return 0;
}