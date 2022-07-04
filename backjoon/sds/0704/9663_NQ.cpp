#include <iostream>

using namespace std;

int col[15];
int N;
int re;
bool promising(int idx) {
    for(int i=0;i<idx;i++) {
        if(col[idx] == col[i]) return false;
        else if(abs(col[idx] - col[i]) == abs(idx-i)) return false;
    }
    return true;
}

void Queen(int idx) {
   // cout << idx << "\n";
    if(idx >= N) {
        re++;
        return;
    }
    for(int i=0;i<N;i++) {
        col[idx] = i;
        if(promising(idx)) Queen(idx+1);
    }
}
int main() {
    cin >> N;
    Queen(0);
    cout << re << "\n";
}