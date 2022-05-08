#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int F, S, G, U, D;
int floor[1000001];
bool check[1000001];

bool promising()
{
    queue<int> q;
    q.push(S);
    check[S] = true;
    while (!q.empty())
    {
        int s = q.front();
        // check[s] = true;
        q.pop();

        if (s == G)
            return true;

        if (s + U <= F && !check[s + U])
        {
            floor[s + U] = floor[s] + 1;
            check[s + U] = true;
            q.push(s + U);
        }

        if (s - D > 0 && !check[s - D])
        {
            floor[s - D] = floor[s] + 1;
            check[s - D] = true;
            q.push(s - D);
        }
    }

    return false;
}

int main()
{
    cin >> F >> S >> G >> U >> D;

    bool re = promising();

    if (re)
        cout << floor[G];
    else
        cout << "use the stairs\n";

    return 0;
}