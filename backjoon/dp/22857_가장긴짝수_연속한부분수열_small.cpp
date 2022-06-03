#include <iostream>
#include <algorithm>
using namespace std;

int arr[50001];
int main() {
    int N,K; cin>>N>>K;
    int re=0;
    for(int i=1;i<=N;i++) cin>>arr[i];
    int p1 = 1, p2 = 1;
    int cnt=0;
    while(p1 <=N && p2<=N) {
        if(arr[p1]%2==0) p1++;
        if(cnt < K) {
            if(arr[p2] % 2 == 1) {
                cnt++; 
                p2++;
            }
            else p2++;
        }
        else {
            re = max(re, p2-p1 - K);
            cout << p1 << " " << p2 << " " << re << "\n";
            cnt=0;
            p1++;
        }
    }
    cout << re << "\n";
}