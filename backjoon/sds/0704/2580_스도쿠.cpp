#include <iostream>
#include <cstdlib>
using namespace std;

#define MAX 9

int board[MAX][MAX];

bool promising(int idx, int jdx, int num) {
    for(int i=0;i<MAX;i++) { //가로
        if(jdx == i) continue;
        if(board[idx][jdx] == board[idx][i]) return false;
    }

    for(int i=0;i<MAX;i++) { // 세로
        if(idx == i) continue;
        if(board[idx][jdx] == board[i][jdx]) return false;
    }

    int y = idx / 3 * 3;
    int x = jdx / 3 * 3;

    for(int i=y;i<y+3;i++) {
        for(int j=x;j<x+3;j++) {
            if(i==idx && j == jdx) continue;
            if(board[i][j] == board[idx][jdx]) return false;
        }
    }

    return true;
}
void sdoku(int idx, int jdx) {
    if(jdx >= 9) {
        sdoku(idx + 1, 0);
        return;
    }
    if(idx >= 9) {
       for(int i=0;i<MAX;i++) {
            for(int j=0;j<MAX;j++) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        exit(0);
    }

    if(board[idx][jdx] != 0) sdoku(idx, jdx+1);
    else {
        for(int i=1;i<=MAX;i++) {
             board[idx][jdx] = i;
             if(promising(idx, jdx, i)) sdoku(idx, jdx+1);
             board[idx][jdx] = 0;
        }
    }
}
int main() {
    for(int i=0;i<MAX;i++) {
        for(int j=0;j<MAX;j++) cin >> board[i][j];
    }

    sdoku(0,0);
}