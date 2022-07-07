#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 500001
#define ll long long
#define seg vector<long long>

vector<pair<ll,ll>> value;
seg segment;
ll N;

bool cmp(pair<ll,ll> a, pair<ll,ll> b) {
    return a.first < b.first;
}

bool cmp2(pair<ll,ll> a, pair<ll,ll> b) {
    return a.second < b.second;
}

ll sum_segment_tree(ll node, ll start, ll end, ll left, ll right) {
    if(start > right || end < left) return 0;
    if(left <= start && end <= right) return segment[node];
    ll mid = (start + end) / 2;
    ll l = sum_segment_tree(node*2, start, mid, left, right);
    ll r = sum_segment_tree(node*2+1, mid+1, end, left, right);

    return l + r;
}

void update_segment_tree(ll node, ll start, ll end, ll index, ll diff) {
    if(index < start || index > end) return;
    segment[node] += diff;
    if(start==end) return;
    ll mid = (start+end)/2;
    update_segment_tree(node*2, start, mid, index, diff);
    update_segment_tree(node*2+1, mid+1, end, index, diff);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i=0;i<N;i++){
        ll a; cin>>a; //
        value.push_back({a,i});
    }
    ll treeh = (ll)ceil(log2(MAX));
    ll tree_size = (ll)1<<(treeh+1);
    segment.reserve(tree_size);
    sort(value.begin(), value.end(), cmp);
    for(int i=0;i<N;i++) {
        value[i].first = i;
    }
    sort(value.begin(), value.end(), cmp2);
    seg result;
    for(int i=0;i<N;i++) {
        ll now = value[i].first;
        ll front_p = sum_segment_tree(1, 0, N-1, 0, now-1);
        cout << (i+1 - front_p) << "\n";
        update_segment_tree(1,0, N-1, now, 1);
    }
}