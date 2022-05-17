#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> g[100001];
int ans[1000001];
bool check[1000001];
void sol(int n) {
    queue<int> q;
    q.push(n);

    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(auto num : g[now]) {
            if(check[num]) continue;
            check[num] = true;
            ans[num] = now;
            q.push(num);
        }
    }
}
int main() {
    int N; cin>>N;
    for(int i=0;i<N-1;i++) {
        int a,b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    check[1] = true;
    sol(1);
    for(int i=2;i<=N;i++) cout << ans[i] << "\n";
}