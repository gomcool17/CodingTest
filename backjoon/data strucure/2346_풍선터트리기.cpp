#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {
    int N; cin>>N;
    deque<pair<int,int>> dq;
    vector<int> ans;
    for(int i=0;i<N;i++) {
        int n; cin>>n;
        dq.push_back({n,i+1});
    }
    int n = dq.front().first;
    ans.push_back(1);
    dq.pop_front();
    while(!dq.empty()) {
        if(n > 0) {
            for(int i=0;i<n-1;i++) {
                int f = dq.front().first;
                int s = dq.front().second;
                dq.pop_front();
                dq.push_back({f,s});
            }
            n = dq.front().first;
            ans.push_back(dq.front().second);
            dq.pop_front();
        }
        else {
            n = -n;
            for(int i=0;i<n-1;i++) {
                int f = dq.back().first;
                int s = dq.back().second;
                dq.pop_back();
                dq.push_front({f,s});
            }
            n = dq.back().first;
            ans.push_back(dq.back().second);
            dq.pop_back();
        }
    }

    for(int i=0;i<ans.size();i++) cout << ans[i] << " ";
}