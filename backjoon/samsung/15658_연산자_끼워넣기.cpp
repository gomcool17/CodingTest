#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int large = -1000000000;
int small = 1000000000;
int op[4];
int N;
vector<int> v;

bool visit[12];

void sol(int cnt,int idx, int sum)
{
    if(cnt >= N)
    {
        large = max(large, sum);
        small = min(small, sum);
        return;
    }

    if(op[0] != 0)
    {
        op[0]--;
        sol(cnt + 1, idx + 1, sum + v[idx]);
        op[0]++;
    }

    if (op[1] != 0)
    {
        op[1]--;
        sol(cnt + 1, idx + 1, sum - v[idx]);
        op[1]++;
    }

    if (op[2] != 0)
    {
        op[2]--;
        sol(cnt + 1, idx + 1, sum * v[idx]);
        op[2]++;
    }

    if (op[3] != 0)
    {
        op[3]--;
        sol(cnt + 1, idx + 1, (int)(sum / v[idx]));
        op[3]++;
    }

    return;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N;i++)
    {
        int a;cin >>a;
        v.push_back(a);
    }
    cin >> op[0] >> op[1] >> op[2] >> op[3];

    sol(1, 1, v[0]);

    cout << large << "\n"
         << small << "\n";
}