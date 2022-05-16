#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int,int>> v;

bool cmp(pair<int,int> a, pair<int,int> b) {
    return a.first > b.first;
}   

bool sol() {
    stack<pair<int,int>> st;
    for(int i=0;i<v.size();i++) {
        if(st.empty()) {
            st.push({v[i].first, v[i].second}); continue;
        }
        
    }
}
int main() {
    cin >> N;
    for(int i=0;i<N;i++) {
        int d,r; cin>>d>>r;
        v.push_back({r,d});
    }
    sort(v.begin(), v.end(), cmp);
    for(int i=0;i<v.size();i++) cout << v[i].first << " " << v[i].second << "\n";
   
}