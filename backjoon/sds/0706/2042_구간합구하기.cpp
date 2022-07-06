#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define ll long long
ll N,M,K;
ll arr[1000002];
vector<ll> segment;

ll make_segment_tree(ll node, ll start, ll end) {
    if(start==end) return segment[node] = arr[start];
    ll mid = (start + end) / 2;
    ll left = make_segment_tree(node*2,start, mid);
    ll right = make_segment_tree(node*2+1, mid+1, end);
    segment[node] = left + right;
    return segment[node];
}

void update_segment_tree(ll node, ll start, ll end, ll index, ll diff) {
    if(index < start || index > end) return;
    segment[node] += diff;
    if(start==end) return;
    ll mid = (start+end)/2;
    update_segment_tree(node*2, start, mid, index, diff);
    update_segment_tree(node*2+1, mid+1, end, index, diff);
}

ll sum_segment_tree(ll node, ll start, ll end, ll left, ll right) {
    if(start > right || end < left) return 0;
    if(left <= start && end <= right) return segment[node];
    ll mid = (start + end) / 2;
    ll l = sum_segment_tree(node*2, start, mid, left, right);
    ll r = sum_segment_tree(node*2+1, mid+1, end, left, right);

    return l + r;
}
int main() {
    cin>>N>>M>>K;
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    int tree_h = (int)ceil(log2(N));
    int tree_size = (1<<(tree_h+1));
    segment.reserve(tree_size);
    make_segment_tree(1,0,N-1);
    M += K;
    while (M--)
    {
        ll a,b,c; cin>>a>>b>>c;
        if(a==1) {
            ll diff = c-arr[b-1];
            arr[b-1] = c;
            update_segment_tree(1,0,N-1,b-1,diff);
        }
        else {
            cout << sum_segment_tree(1,0,N-1,b-1,c-1) << "\n";
        }
    }
}