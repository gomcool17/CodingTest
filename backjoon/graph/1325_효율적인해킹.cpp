#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> g[100001];
vector<int> ans;
int m;
int N,M; 
void find(int n) {
    queue<int> q;
    q.push(n);
    bool check[1000001];
    int cnt = 0;
    memset(check, false, N + 1);
    check[n] =true;
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(auto num : g[now]) {
            if(check[num]) continue;
            check[num] = true;
            q.push(num);
            cnt++;
        }
    }

    ans.push_back(cnt);
}
int main() {
    cin>>N>>M;

    for(int i=0;i<M;i++) {
        int a,b;cin>>a>>b;
        g[b].push_back(a);
    }

    for(int i=1;i<=N;i++) {
        find(i);
    }

    for(int i=0;i<N;i++) {
       if(m < ans[i]) m = ans[i];
    }
    
    for(int i=0;i<N;i++) {
        if(ans[i] == m) cout << i+1 << " ";
    }
}