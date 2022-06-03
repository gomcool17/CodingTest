#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
string dp[101][101];

string addNum(string n, string m) {
    string re="";
    int sum = 0;
    while(!n.empty() || !m.empty() || sum) {
        if(!n.empty()) {
            sum += n.back() - '0';
            n.pop_back();
        }

        if(!m.empty()) {
            sum += m.back() - '0';
            m.pop_back();
        }
        re.push_back((sum%10) + '0');
        sum /= 10;
       // re += s;
    }
    reverse(re.begin(), re.end());
    return re;
}
string combination(int n, int m) {
    if(n==m || m == 0) return "1";
    string &re = dp[n][m];
    if(re != "") return re;
    re = addNum(combination(n-1,m), combination(n-1,m-1));
    return re;
}
int main() {
    int n,m;cin>>n>>m;
    
    cout << combination(n,m);
}   