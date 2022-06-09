#include <iostream>
#include <algorithm>

using namespace std;

int arr[101][101];
long long dp[111][111];
int main() {
    int N; cin>>N;
    for(int i=0;i<N;i++) 
        for(int j=0;j<N;j++) cin >> arr[i][j];

    dp[0][0] = 1;

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(dp[i][j] == 0 || i == N-1 && j == N-1) continue;
            else {
                    dp[i][j+arr[i][j]] += dp[i][j];
                    dp[i+arr[i][j]][j] += dp[i][j];
            }
        }
    }
    cout << dp[N-1][N-1] << "\n";
}