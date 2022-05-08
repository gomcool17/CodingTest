#include <iostream>

using namespace std;

int dp[100];
int main()
{
    int T; cin>>T;
    dp[0] = 0, dp[1] = 1;
    for(int i=2;i<=40;i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    while(T--) {
        int N; cin>>N;
        if(N == 0) cout << 1 << " " << 0 << "\n";
        else if(N == 1) cout << 0 << " " << 1 << "\n";
        else cout << dp[N-1] << " " << dp[N] << "\n";
    }   
}