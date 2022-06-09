#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[1001];
int dp[1001];
int re;
int main() {
    int N; cin>>N;
    for(int i=0;i<N;i++) cin>>arr[i];
   // dp[0] = 1;
    for(int i=0;i<N;i++) {
        dp[i] = 1;
       for(int j=0;j<i;j++) {
           if(arr[j] < arr[i]) {
               dp[i] = max(dp[i], dp[j]+1);
           }
       }
       re = max(re, dp[i]);
    }
    cout << re;

}