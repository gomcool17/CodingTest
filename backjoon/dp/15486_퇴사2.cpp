#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MN 1500001
long long T[MN], P[MN];
long long dp[MN];

int main() {
    int N; cin>>N;
    for(int i=0;i<N;i++) {
       cin>>T[i] >> P[i];
    }

    for(int i=0;i<N;i++) {
        int t = i + T[i];
        if(t <= N) {
            dp[t] = max(dp[t], dp[i] + P[i]);
        }

        dp[i+1] = max(dp[i], dp[i+1]);
    }
    cout << dp[N] << "\n";
}