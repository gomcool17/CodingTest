//https://www.acmicpc.net/problem/1543
//문서검색
#include <iostream>
#include <string>

using namespace std;
int main() {
    string s, f;
    getline(cin,s);
    getline(cin,f);
    int cnt = 0;
    int n = 0;
    while(1) {
        if(s.find(f,n) != string::npos) {
            n = s.find(f,n) + f.length();
            cnt++;
            continue;
        }
        break;
    }
    cout << cnt << "\n";
}