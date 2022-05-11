#include <iostream>
#include <queue>
#include <vector>
using namespace std;

queue<int> q;
int main() {
    int n,k;cin>>n>>k;
    vector<int> ans;
    for(int i=0;i<n;i++) q.push(i+1);

    int cnt=0;
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        cnt++;
        if(cnt == k) {
            cnt = 0;
            ans.push_back(now);
        }
        else {
            q.push(now);
        }
    }
    cout << "<";
    for(int i=0;i<ans.size();i++) {
        cout << ans[i];
        if(i != ans.size()-1) cout <<", ";
    }
    cout << ">";
}