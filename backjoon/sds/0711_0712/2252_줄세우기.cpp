#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define MN 32001
int N,M;
vector<int> g[MN];
vector<int> dgree(MN, 0);
int main() {
    cin >> N >> M;
    for(int i=0;i<M;i++) {
        int a,b; cin >> a >> b;
        g[a].push_back(b);
        dgree[b]++;
    }
    queue<int> q;
    for(int i=1;i<=N;i++) {
        if(!dgree[i]) q.push(i);
    }
    vector<int> answer;
    while(!q.empty()) {
        int now = q.front();
        answer.push_back(now);
        q.pop();

        for(auto num : g[now]) {
            dgree[num]--;
            if(dgree[num] == 0 ) 
                q.push(num);
        }
    }

    for(int i=0;i<answer.size();i++)  cout << answer[i] << " ";
    cout << "\n";
}