#include <iostream>
#include <vector>

using namespace std;

int N,M;
int P[1000001];

int FIND(int a) {
    if(P[a] == a) return a;
    else return P[a] = FIND(P[a]);
}
void UNION(int a, int b) {
    a = FIND(a);
    b = FIND(b);
    P[a] = b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=0;i<=N;i++) P[i] = i;
  
    while(M--) {
        int a,b,c; cin>>a>>b>>c;
        if(a==0) {
            UNION(b,c);
        }
        else  {
            if(FIND(b) == FIND(c)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}