#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

vector<int> g[10001];
int dp[20][10001], h[10001];
int parent[100001];

int T,N;
int A,B;

int find_root() {
    for(int i=1;i<=N;i++) {
        for(auto num : g[i]) {
            parent[num] = i;
        }
    }
    for(int i=1;i<=N;i++) {
        if(parent[i] == 0) return i;
    }
    return 0;
}

void get_tree(int now, int pre) {
    for(auto next : g[now]) {
        if(next == pre) continue;
        h[next] = h[now] + 1;
        dp[0][next] = now;
        get_tree(next, now);
    }
}

int LCA(int a, int b) {
    if(h[a] < h[b]) swap(a,b);
    int gap = h[a] - h[b];
    for(int i=0;i<20;i++) {
        if(gap & (1<<i)) a = dp[i][a];
    }
    if(a==b) return a;
    for(int i=19;i>=0;i--) {
        if(dp[i][a] != dp[i][b]) {
            a = dp[i][a], b=dp[i][b];
        }
    }
    return dp[0][a];
}
int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    cin>>T;
    while(T--) {
        cin >> N;
        for(int i=0;i<N-1;i++) {
            int a,b;cin>>a>>b;
            g[a].push_back(b);
        }
        int root = find_root();
        get_tree(root, 0);
        for(int i=1;i<20;i++) {
            for(int j=1;j<=N;j++) {
                dp[i][j] = dp[i-1][dp[i-1][j]];
            }
        }
        int A,B; cin>>A>>B;
        cout << LCA(A,B) << "\n";
        for(int i=0;i<10001;i++) g[i].clear();
        for(int i=0;i<20;i++) memset(dp[i], 0, sizeof(int) * 10001);
        memset(h, 0, sizeof(int) * 10001);
        memset(parent, 0, sizeof(int) * 10001);
    }
}