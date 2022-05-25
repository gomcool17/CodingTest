#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int nodes = 200001;
int N, root;
vector<pair<int,int>> g[nodes];
vector<pair<int,int>> parent[nodes];
bool check[nodes];
int child[nodes];
pair<int,int> gi;
int m=0;

void check_child(int root) {
    queue<int> q;
    q.push(root);
    check[root] = true;

    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(auto next : g[now]) {
            if(check[next.first]) continue;
            check[next.first] = true;
            child[now]++;
            parent[now].push_back(next);
            q.push(next.first);
        }
    }
}

void find_G(int now,int w) {
    if(parent[now].size() >= 2) {
        gi.first = now, gi.second = w;
        return;
    }

    if(parent[now].size() == 0) {
        gi.first = now, gi.second = w;
        return;
    }
    for(auto next : parent[now]) {
        find_G(next.first, w+next.second);
    }
}

void find_leaf(int now, int w) {
    if(parent[now].size() == 0) {
        m = max(m, w);
        return;
    }
    for(auto next : parent[now]) {
        find_leaf(next.first, w+next.second);
    }
}

int main() {
    cin >> N >> root;
    for(int i=0;i<N-1;i++) {
        int a,b,w; cin>>a>>b>>w;
        g[a].push_back({b,w});
        g[b].push_back({a,w});
    }
    check_child(root);
    find_G(root,0);
    find_leaf(gi.first,0);
    cout << gi.second << " " << m << "\n";
}