#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
#include <cstring>

using namespace std;
int cnt[10];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T; cin>>T;
    while(T--) {
        queue<pair<int,int>> q;
        int N,M; cin>>N>>M;
        int re = 0;
        bool f = false;
        memset(cnt, 0, sizeof(int) * 10);
        for(int i=0;i<N;i++) {
            int n; cin>>n;
            q.push({n,i});
            cnt[n]++;
        }
        for(int i=9;i>=1;i--) {
            while(cnt[i]) {
                if(f) break;
                int pre = q.front().first;
                int lo = q.front().second;
                q.pop();
                if(pre != i) {
                    q.push({pre,lo});
                } 
                else {
                    cnt[i]--;re++;
                    if(lo == M) {
                        cout << re << "\n";
                        break;
                    }
                }
            }
        }
    }
}