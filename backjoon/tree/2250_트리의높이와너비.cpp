#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MN = 10001;
int N;
int arr[MN];
pair<int,int> g[MN];
int level[MN];
int inorder[MN];
pair<int,int> dis[MN];
int cnt=1;

int m_depth;
int find_root() {
    for(int i=1;i<=N;i++) {
        if(arr[i]==1) return i;
    }
    return 0;
}

void find_level(int now,int depth) {
    if(now == -1) return;
    level[now] = depth;
    m_depth = max(m_depth, depth);
    find_level(g[now].first, depth+1);
    find_level(g[now].second, depth+1);
}

void find_inorder(int now) {
    if(g[now].first != -1) find_inorder(g[now].first);
    inorder[now] = cnt;
    cnt++;
    if(g[now].second != -1) find_inorder(g[now].second);
}

void find_dis() {
    for(int i=1;i<=m_depth;i++) dis[i].first = 987654321;
    for(int i=1;i<=N;i++) {
        int le = level[i], in = inorder[i];
        dis[le].first = min(dis[le].first, in);
        dis[le].second = max(dis[le].second, in);
    }
}
int main() {
    cin >> N;
    for(int i=0;i<N;i++) {
        int root,left,right; cin>>root>>left>>right;
        g[root].first = left;
        g[root].second = right;
        arr[root]++;
        if(left != -1) arr[left]++;
        if(right != -1) arr[right]++;
    }

    int r = find_root();
    find_level(r,1);
    find_inorder(r);
    find_dis();
    pair<int,int> re;
   
    re.second = -1;
    for(int i=1;i<=m_depth;i++) {
        if(re.second < dis[i].second - dis[i].first) {
            re.first = i, re.second = dis[i].second - dis[i].first;
        }
    }
    cout << re.first << " " << re.second + 1 << "\n";
}