#include <iostream>
using namespace std;

long long arr[1000001] = {0,1,2,};
int main() {
    int N; cin>>N;
    if(N == 0 || N==1 || N == 2) cout << arr[N]<<"\n";
    else {
        for(int i=3;i<=N;i++) {
            arr[i] = (arr[i-1] + arr[i-2]) % 15746;
        }
        cout << arr[N] << "\n";
    }

}