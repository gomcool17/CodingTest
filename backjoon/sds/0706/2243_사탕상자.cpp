#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define MAX 1000001
#define ll long long
#define seg vector<long long>

ll N;
seg segment;
void update_segment_tree(ll node, ll start, ll end, ll idx, ll diff) {
    if(idx < start || idx > end) return;
    segment[node] +=diff;
    if(start == end) return;

    ll mid = (start + end) / 2;
    update_segment_tree(node*2, start, mid, idx, diff);
    update_segment_tree(node*2+1, mid+1, end, idx, diff);
}

ll sum_segment_tree(ll node, ll start, ll end, ll left, ll right) {
    if(right < start || left > end ) return 0;
    if(left <= start &&  end <= right) return segment[node];
    ll mid = (start + end) / 2;
    return sum_segment_tree(node*2, start, mid, left, right) + sum_segment_tree(node*2+1, mid+1, end, left, right);
}

ll find_candy(ll start, ll end, ll cnady) {
    if(start >= end) return start;

    ll mid = (start + end) / 2;
    ll left = sum_segment_tree(1, 1, MAX-1, start, mid);
    ll right = sum_segment_tree(1,1,MAX-1, mid+1, end);
    if(left >= cnady)  return find_candy(start, mid, cnady);
    else  return find_candy(mid+1, end, cnady-left);
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N;
    int tree_h = (int)ceil(log2(MAX));
    int tree_size = 1 << (tree_h+1);
    segment.reserve(tree_size);
    while(N--) {
        ll a,b; cin>>a>>b;
        if(a==1) {
            ll candy = find_candy(1, MAX-1,b);
            cout << candy << "\n";
            update_segment_tree(1,1,MAX-1,candy,-1);
    
        }
        else {
            ll c; cin>>c;
            update_segment_tree(1, 1, MAX-1, b, c);
        }
    }
}