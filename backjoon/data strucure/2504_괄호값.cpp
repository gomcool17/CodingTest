#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>

using namespace std;

string s;
stack<string> st;

int sol() {

    for(int i=0;i<s.size();i++) {
        cout << i << "\n";
        stack<string> tmp = st;
        cout << "before : \n";
         while(!tmp.empty()) {
            cout << tmp.top() << " ";
            tmp.pop();
        }
        cout << "\n";
        if(!(s[i] == '(' || s[i] == ')' || s[i] == '[' || s[i] == ']')) return 0;
        if(s[i] == '(') st.push("(");
        else if(s[i] == '[') st.push("[");
        else if(s[i] == ')') {
            if(st.empty() || st.top() == "[") {
                return 0;
                break;
            }
            else if(s[i-1] == '(' && st.top() == "(") {
                st.pop();
                st.push("2");
            }
            else {
                int n = stoi(st.top()); st.pop();
                cout << n << "\n";
                if(st.empty()) return 0;
                while(!st.empty() && st.top() != "(") {
                    if(st.empty() || st.top() == "[" || st.top() == "]" || st.top() == ")") return 0;
                    n += stoi(st.top());
                    cout << n << "\n";
                    st.pop();
                }
                if(st.empty()) return 0;
                st.pop();
                n*=2;
                st.push(to_string(n));
            }
        }
        else if(s[i] == ']') {
             if(st.empty() || st.top() == "(") {
                return 0;
            }
            else if(s[i-1] == '[' && st.top() == "[") {
                st.pop();
                st.push("3");
            }
            else {
                int n = stoi(st.top()); st.pop();
                if(st.empty()) return 0;
                while(!st.empty() &&  st.top() != "[") {
                    if(st.top() == ")" || st.top() == "(" || st.top() == "]") return 0;
                    n += stoi(st.top());
                    st.pop();
                }
                if(st.empty()) return 0;
                st.pop();
                n*=3;
                st.push(to_string(n));
            }
        }
        cout << "after : \n";
        tmp = st;
        while(!tmp.empty()) {
            cout << tmp.top() << " ";
            tmp.pop();
        }
        cout << "\n";
    }
    int ans = 0;
    while(!st.empty()) {
        if(st.top() == "(" || st.top() == ")" || st.top() == "[" || st.top() == "]") return 0;
        ans += stoi(st.top());
        st.pop();
    }

    return ans;
   // cout <<re<< "\n";*/

}


int main() {
    cin>>s;
    cout << sol() << "\n";
}