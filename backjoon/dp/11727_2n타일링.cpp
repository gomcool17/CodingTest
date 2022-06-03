#include <iostream>
#include <algorithm>
using namespace std;

long long dp[1001];

int main() {
    int N; cin>>N;
    dp[1] = 1;
    for(int i=2;i<=1000;i++) {
       if(i%2==0) dp[i] = (dp[i-1]*2+1) % 10007;
       else dp[i] = (dp[i-1]*2-1) % 10007;
    }
    cout << dp[N];
}