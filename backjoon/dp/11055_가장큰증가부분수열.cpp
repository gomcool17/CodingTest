#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001];
int dp[1001];
int main() {
    int N; cin>>N;
    for(int i=0;i<N;i++) cin>>arr[i];
    int re=0;
    for(int i=0;i<N;i++) {
        dp[i] = arr[i];

        for(int j=0;j<i;j++) {
            if(arr[i] > arr[j]) dp[i] = max(dp[i], dp[j]+arr[i]);
        }
        re=max(re, dp[i]);
    }
    cout << re << "\n";
}