// https://www.acmicpc.net/problem/3830
#include <iostream>
#include <vector>

using namespace std;

#define MN 100001
#define ll int

pair<ll, ll> parent[MN];
int N, M;

void init()
{
    for (int i = 1; i <= N; i++)
        parent[i].first = i, parent[i].second = 0;
}

ll find(int a)
{
    if (parent[a].first == a)
        return a;
    return parent[a].first = find(parent[a].first);
}

void unite(int a, int b, int w)
{
    a = find(a);
    b = find(b);
    parent[b].first = a;
    parent[b].second = w;
}

ll we(int a, int b, int w)
{
    cout <<"we : " <<  a << " " << b << " " << w << "\n";
    w += parent[a].second;
   // cout << "p : " << p <<"\n";
    if (parent[a].first == b)
        return w;
    if(a == parent[a].first) return -1;
    return we(parent[a].first, b, w);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (1)
    {
        cin >> N >> M;
        if (!N && !M)
            break;
        init();

        for (int j = 0; j < M; j++)
        {
            char ch;
            cin >> ch;

            if (ch == '!')
            {
                int a, b, c;
                cin >> a >> b >> c;
                unite(a, b, c);
            }
            else
            {
                int a, b;
                cin >> a >> b;
                int re = we(b, a, 0);
                int re2 = we(a,b,0);
                if (re == -1 && re2 == -1)
                    cout << "UNKNOWN\n";
                else {
                    if(re == -1) cout << re2 << "\n";
                    else cout << re << "\n";
                }
            }

            for (int i = 1; i <= N; i++)
            {
                cout << parent[i].first << " ";
            }
            cout << "\n";
        }
    }
}