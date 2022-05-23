#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

vector<pair<int,int>> g[10002];
int N;
int arr[10002];

void sol(int now, int pre) {

   for(auto num : g[now]) {
       int p = num.first;
       int cost = num.second;

       if(p == pre) continue;

       arr[p] = arr[now] + cost;
       sol(p, now);
   }

}
int main() {
    cin >> N;
    for(int i=0;i<N-1;i++) {
        int a,b,w; cin>>a>>b>>w;
        g[a].push_back({b,w});
        g[b].push_back({a,w});
    }
    
    sol(1,0);
    int m=0;
    for(int i=1;i<=N;i++) {
        if(arr[m] < arr[i]) m = i;
    }
    memset(arr, 0, sizeof(arr));
    sol(m,0);
    int ans = 0;

    for(int i=1;i<=N;i++) ans = max(ans, arr[i]);
    cout << ans;
    
}

/* 다른 버전

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

vector<pair<int,int>> g[10001];
int N;
int arr[10001];
bool visited[10001];

void sol(int parent, int w) {

    queue<pair<int,int>> q;
    q.push({parent, w});
    visited[parent] =true;
    while(!q.empty()) {
        int p = q.front().first;
        int ww = q.front().second;
        q.pop();
        for(auto num : g[p]) {
            if(visited[num.first]) continue;
            visited[num.first] = true;
            arr[num.first] = arr[p] + num.second;
            q.push({num.first, num.second});
        }
    }

}
int main() {
    cin >> N;
    for(int i=0;i<N-1;i++) {
        int a,b,w; cin>>a>>b>>w;
        g[a].push_back({b,w});
        g[b].push_back({a,w});
    }
    
    sol(1,0);
    int m=0;
    for(int i=1;i<=N;i++) {
        if(arr[m] < arr[i]) m = i;
    }
    memset(arr, 0, sizeof(int) * N+1);
    memset(visited,false,N+1);

    sol(m,0);
    int ans = 0;

    for(int i=1;i<=N;i++) ans = max(ans, arr[i]);
    cout << ans << "\n";
    
}


*/