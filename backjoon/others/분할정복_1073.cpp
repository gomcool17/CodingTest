// https://www.acmicpc.net/problem/1074
// Z
#include <iostream>
#include <cmath>
using namespace std;

const int MN = 32769;
//long long arr[MN][MN];
int N,r,c;
long long cnt;
long long ans;
void divide(int y, int x, int size) {
    if(size == 2) {
        if(y <= r && r < y+size && x <= c && c < x+size) {
            if(x < c) ans++;
            if(y < r) ans++;
            if(y < r && x < c) ans++;
            ans += cnt;
            cout << ans << "\n";
        }
        cnt += 4;
        return;
    }
    divide(y, x, size/2);
    divide(y, x+size/2, size/2);
    divide(y+size/2, x, size/2);
    divide(y+size/2, x+size/2, size/2);
}

int main() {
    cin >> N>>r>>c;
    divide(0,0,pow(2,N));
}