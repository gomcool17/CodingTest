#include <iostream>
#include <vector>

using namespace std;

vector<int> g[100001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N; cin>>N;

    for(int i=0;i<N-1;i++) {
        int a,b; cin>>a>>b;
        g[a].push_back(b); g[b].push_back(a);
    }

    int q; cin>>q;

    for(int i=0;i<q;i++) {
        int t,k; cin>>t>>k;
        if(t==1) {
            int cnt=0;
            for(auto num : g[k]) cnt++;
            if(cnt == 1) cout << "no\n";
            else cout << "yes\n";
        }
        else {
            cout<<"yes\n";
        }
    }

}