#include <iostream>
#include <vector>

using namespace std;

long long arr[1000001];

/*long long sol(long long L, long long R) {
    if(L==R) return arr[L];
    long long mid = (L+R)/2;
    long long re = max(sol(L,mid), sol(mid+1, R));

    long long sum = 0;
    long long left = -12345, right = -12345;
    for(int i=mid;i>=L;i--) {
        sum += arr[i];
        left = max(left, sum);
    }
    sum = 0;
    for(int i=mid+1;i<=R;i++) {
        sum += arr[i];
        right = max(right,sum);
    }
    return max(re,right+left);
}
int main() {
    int N; cin>>N;
    for(int i=1;i<=N;i++) cin>>arr[i];

    cout << sol(1,N) << "\n";
}*/

long long dp[1000001];
long long re =-1001;
int main() {
    int N; cin>>N;
    fill(dp,dp+1000001,-1001);
    for(int i=0;i<N;i++) cin>>arr[i];
    dp[0] = arr[0];
    re = max(re, dp[0]);
    for(int i=1;i<N;i++) {
        dp[i] = max(arr[i], dp[i-1]+arr[i]);
        re = max(dp[i], re);
    }
    cout << re << "\n";
}