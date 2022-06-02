#include <iostream>

using namespace std;

int dp[31][31];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int T; cin>>T;
    for(int i=0;i<=30;i++) {
        for(int j=0;j<=i;j++) {
            if(j==0 || j==i) dp[i][j] = 1;
            else dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        }
    }

    while(T--) {
        int N,M; cin>>N>>M;
        cout << dp[M][N] << "\n";
    }
}