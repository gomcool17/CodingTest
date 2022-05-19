#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define NM 10000001
bool check[NM];
long long tree[NM];
long long big = 0;
vector<long long> g[NM];

bool is_tree(long long root, long long nodes) {
    cout << "root : " << root << "\n";
    queue<long long> q;
    q.push(root);
    bool visited[NM];
    memset(visited, false, NM);
    visited[root] = true;
    int c = 1;
    while(!q.empty()) {
        long long now = q.front();
        q.pop();
        cout << now << "\n";
        for(auto num : g[now]) {
            if(visited[num]) return false;
            visited[num] = true;
            q.push(num);
            c++;
        }
    }

    if(c==nodes) return true;
    else return false;
}
int main() {
   // cout << "start~~~\n";
    long long count = 1;
    long long nodes = 0;
    
    while(1) {
        long long a, b; cin >> a>>b;
        if(a == 0 && b == 0) {
            count++;
            cout << "inininini\n";
            long long root=0;
            for(long long i=1;i<=big;i++) {
                cout << "i : " << i << "\n";
                if(check[i]) nodes++;
                if(tree[i] == 0 && check[i]){
                    root = i;
                }
            }
            //cout << root << " " << nodes << "\n";
            bool f = is_tree(root, nodes);
            cout << root << " " << nodes << "\n";
            if(f) {
                cout << "Case " << count << " is a tree.\n";
            }
            else cout << "Case " << count << " is not a tree.\n";
            memset(check, false, big);
            memset(tree, false, big);
            big = 0, nodes = 0;
            g->clear();
            continue;
        }
        if(a==-1 && b==-1) break;
        tree[b]=a;
        g[a].push_back(b);
        check[b] = true;
        check[a] = true;
        big= max(big, max(a,b));
    }
}