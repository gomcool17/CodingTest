#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
vector<int> g[11];
vector<int> v;
int N; 
void sol(int start, int end, int cnt) {
    int root = (start+end) / 2;
    g[cnt].push_back(v[root]);
    if(start == end) return;
    sol(start,root-1,cnt+1);
    sol(root+1, end,cnt + 1);

}
int main() {
    cin>>N;
    int n = pow(2,N) - 1;  
    v.push_back(0);
    for(int i=0;i<n;i++) 
    {
        int a; cin>>a;
        v.push_back(a);
    }
    sol(1, n, 1);
    for(int i=1;i<=N;i++) {
        for(auto num : g[i]) cout << num << " ";
        cout << "\n";
    }
}

/*
4
8 1 9 6 10 4 11 3 12 5 13 2 14 7 15
*/