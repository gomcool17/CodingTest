#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1000001
bool check[MAX];

bool cmp(pair<int,int> a, pair<int,int> b) {
    return a.first -a.second > b.first - b.second;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int cnt = 0;
    for(int i=2;i*i<MAX;i++) {
        if(check[i]) continue;
        for(int j=i*i;j<MAX;j+=i) {
            check[j] = true;
        }
    }

    while(1) {
        int n; cin >> n;
        if(n==0) break;
        vector<pair<int,int>> v;
        for(int i=3;i<=n;i+=2) {
            if(!check[i] && !check[n-i]) {
                cout << n << " = " <<  i << " + " << n-i << "\n";
                v.push_back({1,1});
                break;
            }
        }
        if(!v.size()) cout << "Goldbach's conjecture is wrong.\n";
    }
}