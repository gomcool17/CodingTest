#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

bool check[10];

int promising(int n)
{
    int cnt = 0;
    if (n == 0)
    {
        if (check[0])
            return 0;
        else
            return 1;
    }

    while (n)
    {
        if (check[n % 10])
            return 0;
        else
            n /= 10;
        cnt++;
    }

    return cnt;
}

int main()
{
    int N;
    cin >> N;
    int T;
    cin >> T;
    int a = abs(100 - N);
    int re = 987654321;

    for (int i = 0; i < T; i++)
    {
        int b;
        cin >> b;
        check[b] = true;
    }

    for (int i = 0; i <= 1000000; i++)
    {
        int cnt = promising(i);
        if (cnt == 0)
        {
            continue;
        }
        else
        {
            int sh = abs(i - N) + cnt;
            re = min(sh, re);
        }
    }

    cout << min(re,a);
}