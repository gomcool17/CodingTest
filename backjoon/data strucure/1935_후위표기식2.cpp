#include <iostream>
#include <stack>
#include <queue>

using namespace std;

long long num[27];
int main() {
    int N;
    string s; 
    cin >> N >> s;
    stack<long double> st;
    for(int i=0;i<N;i++) cin >> num[i];
    for(int i=0;i<s.size();i++) {
        if(s[i] >= 'A' && s[i] <='Z') st.push(num[s[i]-'A']);
        else {
            long double b = st.top(); st.pop();
            long double a = st.top(); st.pop();
            if(s[i] == '+') st.push((double)a+b);
            else if(s[i] == '-') st.push((double)a-b);
            else if(s[i] == '*') st.push((double)a*b);
            else st.push((double)a/b);
        }
    }
    long double ans =st.top();
    cout << fixed;
    cout.precision(2);
    cout << ans << "\n";
}