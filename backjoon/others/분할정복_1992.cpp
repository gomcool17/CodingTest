// https://www.acmicpc.net/problem/1992
// 쿼드트리
#include <iostream>
using namespace std;

const int MN = 65;

int N;
int arr[MN][MN];

string divide(int y, int x, int size) {
    bool only0 = true;
    bool only1 = true;
    for(int i=y;i<y+size;i++) {
        for(int j=x;j<x+size;j++) {
            if(arr[i][j] == 1) only0 = false;
            if(arr[i][j] == 0) only1 = false;
        }
    }
    string answer = "";
    if(!only0 && !only1) {
        answer += "(";
        answer += divide(y, x, size/2);
        answer += divide(y, x+size/2, size/2);
        answer += divide(y+size/2, x, size/2);
        answer += divide(y+size/2, x+size/2, size/2);
        answer += ")";
    }
    else {
        if(only0) answer += "0";
        else answer += "1";
    }
   // answer += "";
    return answer;
} 
int main() {
    cin >> N;
    for(int i=0;i<N;i++) 
        for(int j=0;j<N;j++) {
            char c; cin >> c;
            arr[i][j] = c-'0';
        }

    cout << divide(0,0,N);
}