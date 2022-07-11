#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MN = 100001;

int depth[MN], dp[20][MN];
vector<int> g[MN];
int N;

void get_tree(int now, int pre) {
    for(auto next : g[now]) {
        if(next == pre) continue;
        depth[next] = depth[now] + 1;
        dp[0][next] = now;
        get_tree(next, now);
    }
}

int LCA(int a, int b) {
    if(depth[a] < depth[b]) swap(a,b);

    int gap = depth[a]-depth[b];
    for(int i=0;i<20;i++) {
        if(gap & (1<<i)) {
            a = dp[i][a];
        }
    }   

    if(a==b) return a;
    for(int i=19;i>=0;i--) {
        if(dp[i][a] != dp[i][b]) {
            a = dp[i][a];
            b = dp[i][b];
        }
    }
    return dp[0][a];
}
int main() {
    ios:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i=0;i<N-1;i++) {
        int a,b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    get_tree(1,0);

    for(int i=1;i< 20;i++) {
        for(int j=1;j<=N;j++) {
            dp[i][j] = dp[i-1][dp[i-1][j]];
        }
    }
   
    int M; cin>>M;

    while(M--) {
        int a, b; cin>>a>>b;
        cout << LCA(a,b) << "\n";
    }
}