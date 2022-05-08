#include <iostream>
using namespace std;

#define mod 1000000000
long long arr[101][10];

int main() {
    for(int i=1;i<=9;i++) arr[1][i] = 1;
    for(int i=2;i<=100;i++) {
        for(int j=0;j<=9;j++) {
            if(j==0) arr[i][j] = arr[i-1][j+1] % mod;
            else if(j==9) arr[i][j] = arr[i-1][j-1] % mod;
            else arr[i][j] = (arr[i-1][j-1] + arr[i-1][j+1]) % mod;
        }
    }

    int N;cin>>N;
    long long ans = 0;
    for(int i=0;i<=9;i++) ans += arr[N][i];
    cout << ans % mod << "\n";
}