#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, D;
int root;
vector<int> g[51];
int cnt;

void sol(int n) {
    int c=0;
    if(n==D) return;
    for(auto num : g[n]) {
        if(num == D) continue;
        c++;
        sol(num);
    }

    if(c == 0) cnt++;
    return;
}
int main() {
    cin >> N;
    for(int i=0;i<N;i++){
        int n; cin >> n;
        if(n == -1) root = i;
        else {
            g[n].push_back(i);
        }
    } 
    cin>>D;
    
    sol(root);
    cout << cnt << "\n";
}