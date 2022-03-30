#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    int arr[] = {500, 100, 50, 10, 5, 1};
    cin >> N;
    N = 1000 - N;
    int re = 0;
    for (int i = 0; i < 6; i++)
    {
        re += N / arr[i];
        N %= arr[i];
    }
    cout << re << "\n";
}