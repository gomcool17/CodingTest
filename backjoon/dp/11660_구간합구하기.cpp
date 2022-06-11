#include <iostream>

using namespace std;

int arr[1025][1025];
long long dp[1025][1025];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N,M; cin>>N>>M;

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++) {
            int n;cin>>n;
            dp[i+1][j+1] = dp[i][j+1] + dp[i+1][j] + n - dp[i][j];
        } 
    for(int i=0;i<M;i++) {
        int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
        
        cout << dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1] << "\n";
    }
}