#include <vector>
#include <iostream>

using namespace std;

int ans[5000001];
int main() {
    vector<int> v;
    int N; cin>>N;
    for(int i=0;i<N;i++) {
        int n;cin>>n;
        v.push_back(n);
    }
    ans[1] = 0;
    for(int i=2;i<=N;i++) {
        if(v[i] > v[i-1]) ans[i] = ans[i-1];
        else ans[i] = i-1;
    }

    for(int i=1;i<=N;i++) cout << ans[i] << " ";

}