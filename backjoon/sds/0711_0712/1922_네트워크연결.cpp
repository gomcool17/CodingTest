#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge {
    int u,v,w;
};
int N,M;
vector<int> p(1001, 0);
vector<int> rnk(100001,1);
edge arr[100001];

bool cmp(edge a, edge b) {
    return a.w < b.w;
}

int find(int x) {
    if(x == p[x]) return x;
    return p[x] = find(p[x]);
}
void unite(int a, int b) {
    a = find(a), b = find(b);
    if(a==b) return;

    if(rnk[a] < rnk[b]) swap(a,b);
    p[b] = a;
    if(rnk[a] == rnk[b]) rnk[a]++;

}
int main() {
    cin >> N >> M;
    for(int i=1;i<=N;i++) p[i] = i;
    for(int i=0;i<M;i++) cin >> arr[i].u >> arr[i].v >> arr[i].w;

    sort(arr, arr+M, cmp);
    int cnt = 0, sum = 0;
    for(int i=0;i<M;i++) {
        if(cnt == N-1)  break;
        int u = arr[i].u;
        int v = arr[i].v;
        if(find(u) != find(v)) {
            unite(u,v);
            sum+=arr[i].w;
            cnt++;
        }
    }
    for(int i=1;i<=N;i++) cout << rnk[i] << " ";
    cout << "\n";
    cout << sum << "\n";
}