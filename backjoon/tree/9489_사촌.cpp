#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while(1) {
        int N, K; cin>>N>>K;
        if(N==0 && K==0) break;
        int arr[100001] = {-1}, p[10001]= {-1};
        int cnt = -1, idx = 0;
        for(int i=1;i<=N;i++) {
            cin>>arr[i];
            if(arr[i] == K) idx = i;
            if(arr[i] != arr[i-1]+1) cnt++;
            p[i] = cnt;
        }

        int re = 0;
        for(int i=1;i<=N;i++) {
            if(p[idx] != p[i] && p[p[idx]] == p[p[i]]) re++;
        }
        cout << re << "\n";
    }
}   