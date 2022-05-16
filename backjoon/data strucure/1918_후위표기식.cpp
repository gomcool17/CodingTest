#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string s; cin >> s;
    stack<char> st;

    for(int i=0;i<s.size();i++) {
       // cout << "\n=========" << i << "=========\n";
        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '(' || s[i] == ')') {
            if(st.empty()) {
                //cout << "empty : " << s[i] << "\n";
                st.push(s[i]); continue;
            }
            if(s[i] == '(') st.push(s[i]);
            else if(s[i] == ')') {
                while(1) {
                    if(st.top() == '(') {
                        st.pop(); break;
                    }
                    cout << st.top();
                    st.pop();
                }
            }
            else {
                if(s[i] == '*' || s[i] == '/' || st.top() == '(') {
                    if(st.top() == '(') {
                        st.push(s[i]);
                        continue;
                    }
                    if(st.top() == '+' || st.top() == '-') {
                        st.push(s[i]); continue;
                    }
                    cout << st.top();
                    st.pop();
                    st.push(s[i]);
                }
                else {
                    while(!st.empty()) {    
                        if(st.top() == '(') break;            
                        cout << st.top();
                        st.pop();
                    }
                    st.push(s[i]);
                }
            }
        }
        else {
            cout << s[i];
        }
    }

    while(!st.empty()) {                
        cout << st.top();
        st.pop();
    }
}