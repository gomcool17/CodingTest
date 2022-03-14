#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int arr[3];
bool visit[1001][1001];
int s;
queue<pair<int, int>> q;

bool sol()
{
    while (!q.empty())
    {
        int a = q.front().first;
        int b = q.front().second;
        int c = s - a - b;
        q.pop();

        if (a == b && b == c)
        {
            //cout << a << " " << b << " " << c << "\n";
            return true;
        }

        int A = min(min(a, b), c);
        int C = max(max(a, b), c);
        int B = s - A - C;

        if (visit[A][B] || visit[B][A])
            continue;

      //  cout << A << " " << B << " " << C << "\n";

        if (A != B)
        {
            int X = min(A, B);
            int Y = max(A, B);

            q.push({X + X, Y - X});
        }

        if (A != C)
        {
            int X = min(A, C);
            int Y = max(A, C);

            q.push({X + X, Y - X});
        }

        if (B != C)
        {
            int X = min(C, B);
            int Y = max(C, B);

            q.push({X + X, Y - X});
        }

        visit[A][B] = true;
    }

    return false;
}

int main()
{
    cin >> arr[0] >> arr[1] >> arr[2];
    s = arr[0] + arr[1] + arr[2];

    q.push({arr[0], arr[1]});
    q.push({arr[0], arr[2]});
    q.push({arr[1], arr[2]});

    if (sol())
        cout << 1;
    else
        cout << 0;

    return 0;
}