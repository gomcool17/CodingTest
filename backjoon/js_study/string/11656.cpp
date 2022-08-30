// https://www.acmicpc.net/problem/11656
// 접미사 배열
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string s; cin>>s;
    vector<string> v;
    for(int i=0;i<s.length();i++) {
        string ss = s.substr(i);
        v.push_back(ss);
    }
    sort(v.begin(), v.end());
    for(int i=0;i<v.size();i++) cout << v[i] << "\n";
}