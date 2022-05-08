#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

vector<int> v;
int N;
bool visit[8];
int m = 0;

void sol(int idx, int sum, int cnt, int minus)
{
    if (cnt >= N)
    {
        m = max(sum, m);
        return;
    }
    for (int i = 0; i < N; i++)
    {
        if (visit[i])
            continue;

        int s = abs(minus - v[i]);
        visit[i] = true;
        sol(i, sum + s, cnt + 1, v[i]);
        visit[i] = false;
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    // sort(v.begin(), v.end());

    for (int i = 0; i < N; i++)
    {
        visit[i] = true;
        sol(i, 0, 1, v[i]);
        visit[i] = false;
    }

    cout << m;
}