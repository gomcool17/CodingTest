#include <iostream>
using namespace std;

bool check[1001];

int main() {
    int N,K; cin>>N>>K;
    int cnt = 0;
    for(int i=2;i<=N; i++) {
        if(check[i]) continue;
        cnt++;
        if(cnt == K){
            cout << i << "\n";
            return 0;
        }
        for(int j=i*i; j<=N; j+=i) {
            if(!check[j]) {
                check[j] = true;
                cnt++;
                if(cnt == K){
                    cout << j << "\n";
                    return 0;
                }
            }
        }
    }
}