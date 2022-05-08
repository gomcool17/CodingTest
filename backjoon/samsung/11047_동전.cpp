#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v;
    int N, K;
    int re = 0;
    cin >> N >> K;
    for (int i = 0; i < N;i++)
    {
        int n1;
        cin >> n1;
        v.push_back(n1);
    }

    for (int i = N - 1; i >= 0;i--)
    {
        re += K / v[i];
        K %= v[i];
    }

    cout << re << "\n";
}