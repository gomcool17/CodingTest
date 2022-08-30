// https://www.acmicpc.net/problem/1493
// 박스 채우기
#include <iostream>
#include <cmath>
using namespace std;

int box[21];
int ans;
bool flag = true;
void sol(int l, int w, int h) {
    if(l==0||w==0||h==0) return;
    flag = false;
    int cubeLen;
    for(int i=19;i>=0;i--) {
        if(box[i] == 0) continue;

        cubeLen = 1<<i; // 2^i
        if(cubeLen <= l && cubeLen <= w && cubeLen <= h) {
            //cout << "in\n";
            box[i]--;
            ans++;
            flag = true;
            break;
        }
    }
    if(!flag) return;
  
    sol(l-cubeLen, w, cubeLen);
    sol(cubeLen, w-cubeLen, cubeLen);
    sol(l,w,h-cubeLen);
}
int main() {
    int l,w,h; cin>>l>>w>>h;
    int N; cin >> N;
    for(int i=0;i<N;i++) {
        int n; cin>>n;
        cin >> box[n];
    }
    sol(l,w,h);
    if(flag) cout << ans << "\n";
    else cout << "-1\n";
}