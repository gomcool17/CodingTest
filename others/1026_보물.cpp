#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> v1;
    vector<int> v2;

    for (int i = 0; i < N;i++)
    {
        int n;
        cin >> n;
        v1.push_back(n);
    }

    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        v2.push_back(n);
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end(), greater<>());

    int re = 0;
    
    for (int i = 0; i < N;i++)
    {
        re += v1[i] * v2[i];
    }

    cout << re << "\n";
}