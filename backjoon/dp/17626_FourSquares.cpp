#include <iostream>
#include <algorithm>
using namespace std;
int dp[500001];
int main() {
    int N; cin>>N;
    dp[1] =1;
    for(int i=2;i<=N;i++) {
        dp[i] = dp[i-1] + 1;
        for(int j=2;j*j<=i;j++) {
            dp[i] = min(dp[i], dp[i-j*j] + 1);
        }
    }
    cout << dp[N] << "\n";
}