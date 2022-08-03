// https://www.acmicpc.net/problem/6603
// 로또
#include <iostream>
#include <vector>

using namespace std;

bool check[14];
void dfs(vector<int> num, int n, int cnt, int idx) {
    if(cnt == 6) {
        for(int i=0;i<n;i++) {
            if(check[i]) cout << num[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=idx+1;i<n;i++) {
        check[i] = true;
        dfs(num,n,cnt+1,i);
        check[i] = false;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while(1) {
        int n; cin >> n;
        if(n==0) break;
        vector<int> v;
        for(int i=0;i<n;i++) {
            int a; cin>>a;
            v.push_back(a);
        }
        for(int i=0;i<n;i++) {
            check[i] = true;
            dfs(v,n,1, i);
            check[i] = false;
        }
        cout<<"\n";
    }
}