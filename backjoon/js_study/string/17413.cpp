// https://www.acmicpc.net/problem/17413
// 단어뒤집기2
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    bool tag = false;
    string tmp = "";
    vector<string> ans;
    string a;
    for(int i=0;i<s.length();i++) {
        if(s[i] == '<') {
            reverse(tmp.begin(), tmp.end());
            ans.push_back(tmp);
            a += tmp;
            tmp = "";
            tag = true;
        }
        else if(s[i] == ' ' && !tag) {
            reverse(tmp.begin(), tmp.end());
            ans.push_back(tmp);
            a += tmp + " ";
            tmp = "";
            continue;
        }
        else if(s[i] == '>') {
            ans.push_back(tmp);
            a += tmp + ">";
            tmp = "";
            tag = false;
            continue;
        }
        tmp += s[i];
        if(i == s.length() - 1) {
            reverse(tmp.begin(), tmp.end());
            ans.push_back(tmp);
            a += tmp;
        }
    }
    cout << a << "\n";
}