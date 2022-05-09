#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> g[1000001];
bool check[1000001];
int parent[1000001];

void find_parent(int n) {
    queue<int> q;
    q.push(n);

    while(!q.empty()) {
        int now = q.front();
        q.pop();
        check[now] = true;
        for(auto num : g[now]) {
            if(check[num]) continue;
            parent[num] = now;
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

    find_parent(1);
    for(int i=2;i<=N;i++) cout << parent[i] << "\n";
}