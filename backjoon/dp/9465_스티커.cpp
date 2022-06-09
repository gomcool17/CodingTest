#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int arr[2][100001];
int dp[2][100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int T; cin>>T;
    while(T--) {
        int N; cin>>N;
        for(int i=0;i<2;i++) 
            for(int j=0;j<N;j++) cin>>arr[i][j];

        dp[0][0] = arr[0][0];
        dp[1][0] = arr[1][0];
        dp[0][1] = dp[1][0] + arr[0][1];
        dp[1][1] = dp[0][0] + arr[1][1];

        for(int i=2;i<N;i++) {
            dp[0][i] = arr[0][i] + max(dp[1][i-1],dp[1][i-2]);
            dp[1][i] = arr[1][i] + max(dp[0][i-1], dp[0][i-2]);
        }
        cout << max(dp[0][N-1], dp[1][N-1]) << "\n";
        for(int i=0;i<2;i++) {
            memset(arr[i], 0, sizeof(arr[i]));
            memset(dp[i], 0, sizeof(dp[i]));
        }
    }   
}