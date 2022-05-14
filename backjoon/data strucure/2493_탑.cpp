#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    stack<pair<int,int>> st;
    int N; cin>>N;
    for(int i=0;i<N;i++) {
        int n;cin>>n;
        
        while(!st.empty()) {
            if(st.top().first > n) {
                cout << st.top().second << " ";
                break;
            }
            st.pop();
        }

        if(st.empty()) cout << 0 << " ";
        st.push({n, i+1});
    }
}