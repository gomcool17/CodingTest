#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long dp[100001];
int arr[100001];
int main() {
    int N,K; cin>>N>>K;
    for(int i=0;i<N;i++) cin>>arr[i];
    for(int i=1;i<=K;i++) dp[i] = 100101;
    for(int i=0;i<N;i++) {
        for(int j=arr[i]; j<=K;j++) {
            dp[j] = min(dp[j], dp[j-arr[i]] + 1);
        }
    }
    if(dp[K] > 100001) cout << -1 << "\n";
    else cout << dp[K] << "\n";
}