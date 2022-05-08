#include <bits/stdc++.h>

using namespace std;

int main()
{
    int arr[3] = {300, 60, 10};
    int ans[3];
    int T;
    cin >> T;

    for (int i = 0; i < 3; i++)
    {
        ans[i] = T / arr[i];
        T %= arr[i];
    }

    if (T != 0)
        cout << "-1";
    else
        cout << ans[0] << " " << ans[1] << " " << ans[2];
}