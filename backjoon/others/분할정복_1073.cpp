// https://www.acmicpc.net/problem/1074
// Z
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

const int MN = 32769;
//long long arr[MN][MN];
int N,r,c;
long long cnt;
long long ans;
void divide(int y, int x, int size) {
    if(!(y <= r && r < y+size && x <= c && c < x+size)) {
        ans += size * size;
        return;
    }
    if(y==r && x == c) {
        cout << ans << "\n";
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