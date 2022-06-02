#include <iostream>
#include <algorithm>
using namespace std;
#define INF 987654321

bool sol(int n, int N) {
    int num = n * 5;
    N -= num;
    if(N%3==0) return true;
    else return false;
}
int main() {
    int N; cin >> N;
    int re=INF;

    if(N % 5 == 0) {
        re = N/5;
    }
    else if(N%5%3 == 0) {
        re = N / 5;
        re += N%5/3;
    }
    else {
        int n = N/5;
    
        while(n > -1) {
            
            if(sol(n,N)) {
                int num = (N - (n*5)) / 3 + n;
                re  = min(num,re);
            }
            n--;
        }
    }

    cout << (re == INF ? -1 : re) << "\n";
}