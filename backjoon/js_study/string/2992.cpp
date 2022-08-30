// https://www.acmicpc.net/problem/2992
// 크면서 작은수
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string s;
int answer = 987654321;
bool check[7];
void sol(int idx, int cnt, string str)
{
    if(cnt == s.length()) {
        if(str > s) 
            answer = min(answer, stoi(str));
        return;
    }

    for(int i = 0;i<s.length();i++) {
        if(check[i]) continue;
        check[i] = true;
        sol(i+1, cnt+1, str + s[i]);
        check[i] = false;
    }

}
int main() {
    cin >> s;
    sol(0,0, "");
    if(answer == 987654321) cout << 0 << "\n";
    else cout << answer << "\n";
}