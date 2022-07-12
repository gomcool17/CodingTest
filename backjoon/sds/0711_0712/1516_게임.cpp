#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int dgree[501];
int result[501];
int times[501];
vector<int> g[501];
int main() {
    cin >> N;
    for(int i=1;i<=N;i++) {
        int t; cin >> t;
        times[i] = t;
        while(1) {
            int n; cin >> n;
            if(n == -1) break;
            g[n].push_back(i);
            dgree[i]++;
        }
    }
    priority_queue<int> q; //오래걸리는 건물이 늦게 나오게

    for(int i=1;i<=N;i++) {
        if(!dgree[i]) q.push(i); 
        result[i] = times[i];
    }

    while(!q.empty()) {
        int now = q.top(); q.pop();
        for(auto num : g[now]) {
            dgree[num]--;
            result[num] = max(result[now] + times[num], result[num]);
            if(!dgree[num]) {
                q.push(num);
            }
        }
    }

    for(int i=1;i<=N;i++) cout << result[i] << "\n";

}