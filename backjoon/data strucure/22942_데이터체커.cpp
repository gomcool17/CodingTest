#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int N;
struct INFO
{
    int num,lo;
    string info;
};
vector<INFO> v;

bool cmp(INFO a, INFO b) {
    return a.num < b.num;
}

bool sol() {
    stack<INFO> st;
    for(int i=0;i<v.size();i++) {
        if(v[i].info == "start") st.push(v[i]);
        else {
            if(st.top().lo == v[i].lo) st.pop();
            else {
                return false;
            }
        }
    }   

    return true;
}
int main() {
    cin >> N;
    for(int i=0;i<N;i++) {
        int d,r; cin>>d>>r;
        v.push_back({d-r,i,"start"});
        v.push_back({d+r,i,"end"});
    }
    sort(v.begin(), v.end(), cmp);
    cout << ((sol()) ? "YES\n" : "NO\n");
}