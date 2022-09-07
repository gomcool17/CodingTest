// https://www.acmicpc.net/problem/2357
// 최솟값과 최댓값
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long
#define INF 1000000001
vector<ll> min_segment, max_segment;

int N,M;
int arr[100001];

ll make_min_segment_tree(ll node, ll start, ll end) {
    if(start == end) return min_segment[node] = arr[start];
    ll mid = (start + end) / 2;
    ll left =make_min_segment_tree(node*2, start, mid);
    ll right = make_min_segment_tree(node*2+1,mid+1, end);
    min_segment[node] = min(left, right);

    return min_segment[node];
}

ll make_max_segment_tree(ll node, ll start, ll end) {
    if(start == end) return max_segment[node] = arr[start];
    ll mid = (start + end) / 2;
    ll left = make_max_segment_tree(node*2, start, mid);
    ll right = make_max_segment_tree(node*2+1,mid+1, end);
    max_segment[node] = max(left, right);

    return max_segment[node];
}

ll min_segment_tree(ll node, ll start, ll end, ll left, ll right) {
    if(end < left || start > right) return INF;
    if(left <= start && end <= right) return min_segment[node];
    ll mid = (start+end)/2;
    ll l = min_segment_tree(node*2, start, mid, left, right);
    ll r = min_segment_tree(node*2+1, mid+1, end, left, right);
   // cout << l << " " << r << "\n";
    return min(l,r);
}

ll max_segment_tree(ll node, ll start, ll end, ll left, ll right) {
    if(end < left || start > right) return 0;
    if(left <= start && end <= right) return max_segment[node];
    ll mid = (start+end)/2;
    ll l = max_segment_tree(node*2, start, mid, left, right);
    ll r = max_segment_tree(node*2+1, mid+1, end, left, right);
   // cout << l << " " << r << "\n";
    return max(l,r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i=1;i<=N;i++) cin >> arr[i];
    
    
    int tree_h = (int)ceil(log2(N));
    int tree_size = (1<<(tree_h+1));
    min_segment.reserve(tree_size);
    max_segment.reserve(tree_size);
   
    make_min_segment_tree(1,1,N);
    make_max_segment_tree(1,1,N);
    for(int i=0;i<M;i++) {
        int a,b; cin >> a>>b;
        cout << min_segment_tree(1, 1, N, a, b) << " ";
        cout << max_segment_tree(1, 1, N, a, b) << "\n";
    }
}