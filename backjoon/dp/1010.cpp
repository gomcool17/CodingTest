// 다리놓기
#include <iostream>
using namespace std;

long long dp[31][31];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T; cin>>T;
    dp[0][0] = 1;
    for(int i=1;i<=30;i++) {
        dp[i][0] = 1;
        for(int j=1;j<=30;j++) {
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        }
    }
    while(T--) {
        int N,M; cin>>N>>M;
        cout << dp[M][N] << "\n";
    }
}