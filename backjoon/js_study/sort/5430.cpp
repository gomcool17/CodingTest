// https://www.acmicpc.net/problem/5430
// 고스택
#include <iostream>
#include <deque>
#include <string>
#include <sstream>
using namespace std;
int T;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--) {
        string s; cin >> s;
        int n; cin>>n;
        string arr; cin >> arr;
        arr = arr.substr(1, arr.size()-2);
        istringstream iss(arr);
        string buff;
        deque<int> dq;
        while(getline(iss, buff, ',')) dq.push_back(stoi(buff));
        bool flag = true;
        bool error = false;
        for(int i=0;i<s.size();i++) {
            if(s[i] == 'D') {
                if(dq.empty()) {
                    cout << "error\n";
                    error = true;
                    break;
                }
                if(flag) dq.pop_front();
                else dq.pop_back();
            }
            else flag = !flag;
        }
        if(error) continue;
        string ans = "[";
        while(!dq.empty()) {
            if(flag) {
                ans += to_string(dq.front());
                dq.pop_front();
            }
            else {
                ans += to_string(dq.back());
                dq.pop_back();
            }
            ans += ",";
        }
        if(ans.size()>1) ans[ans.size()-1] = ']';
        else ans += "]";
        cout << ans << "\n";
    }
}