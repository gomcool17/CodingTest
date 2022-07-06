#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<int> st;
vector<string> s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N; cin>>N;

    while(N--) {
        string s; cin >> s;
        if(s == "push") {
            int n; cin>>n;
            st.push(n);
        }

        if(s=="pop") {
            if(st.empty()) {
                cout << -1 << "\n";
                continue;
            }
            cout << st.top() << "\n";
            st.pop();
        }

        if(s=="size") {
            cout << st.size() << "\n";
        }

        if(s=="top") {
             if(st.empty()) {
                cout << -1 << "\n";
                continue;
            }
            cout << st.top() << "\n";
        }

        if(s=="empty") {
            if(st.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
    }
}