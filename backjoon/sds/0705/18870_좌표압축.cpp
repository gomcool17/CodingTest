#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int,int>> v;

bool comp(pair<int,int> a, pair<int,int> b)
{
    return a.first < b.first;
}

int main() {
    cin >> N;
    for(int i=0;i<N;i++) {
        int n; cin>>n;
        v.push_back({n,i});
    }

    sort(v.begin(), v.end());
    vector<pair<int,int>> ans;
    int cnt = 0;
    for(int i=v.size()-1;i>=0;i--) {
        int n1 = upper_bound(v.begin(), v.end(), pair(v[i].first, 0), comp) -v.begin();
        int n2 = lower_bound(v.begin(), v.end(), pair(v[i].first, 0), comp) - v.begin();
        for(int j=n1-1; j>=n2;j--) {
            ans.push_back({v[j].second, cnt});
        }
        i=n2;
        cnt++;
    }
    cnt--;
    sort(ans.begin(), ans.end());
    for(int i=0;i<ans.size();i++) {
       cout << cnt - ans[i].second << " ";
    }
}