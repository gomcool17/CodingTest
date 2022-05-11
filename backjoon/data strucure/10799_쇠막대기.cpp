#include <stack>
#include <deque>
#include <iostream>

using namespace std;

int main() {
    string s; cin>>s;
    stack<char> st;
    int re = 0;
    for(int i=0;i<s.size();i++) {
        if(s[i] == '(') st.push('(');
        else {
            st.pop();
            if(s[i-1] == '(') re += st.size();
            else re += 1;
        }
    }
    cout << re << "\n";
}