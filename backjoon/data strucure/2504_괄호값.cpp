#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>

using namespace std;
int main() {
    string s; cin>>s;
    stack<char> st;
    queue<int> q;
    int cnts = 0, cntb = 0;
    //int re = 0;
    string re="";
    for(int i=s.size()-1;i>=0;i--) {
        if(s[i] == ')') {
            cnts++;
        }
        else if(s[i] == ']') {
            cntb++;
        }
        else if(s[i] == '(') {

        }
        else if(s[i] == '[') {
            if(s[i] == ']') s += "3";
            else if(s[i] == '[') s+="3*";
        }
    }

}