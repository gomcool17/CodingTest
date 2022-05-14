#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;
bool check[201];
bool visited[10];
vector<pair<int,int>> v;
string s;
vector<string> ans;

void dfs(int idx) {
    if(idx >= v.size()) {
        string re = "";
        for(int i=0;i<s.size();i++) {
            if(check[i]) continue;
            re += s[i];
        }
        ans.push_back(re);
        return;
    }

    check[v[idx].first] = true;
    check[v[idx].second] = true;
    dfs(idx + 1);
    check[v[idx].first] = false;
    check[v[idx].second] = false;
    dfs(idx + 1);
}
int main() {
    cin >> s;
    stack<int> st;

    for(int i=0;i<s.size();i++) {
        if(s[i] == '(') st.push(i);
        else if(s[i] == ')') {
            v.push_back({st.top(),i});
            st.pop();
        }
    }
    dfs(0);
    ans.erase(ans.begin() + ans.size() - 1);
    sort(ans.begin(), ans.end());
    string now = "";
    for(int i=0;i<ans.size();i++) {
        if(ans[i] == now) continue;
        else {
            cout << ans[i] << "\n";
            now = ans[i];
        }
    }
    
}