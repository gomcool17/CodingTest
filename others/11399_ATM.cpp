#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int re = 0;
    vector<int> v;

    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        v.push_back(n);
    }

    sort(v.begin(), v.end());

    for (int i = 1; i < N ; i++)
    {
        v[i] += v[i - 1];
        re += v[i];
    }

    cout << re + v[0]<< "\n";
}