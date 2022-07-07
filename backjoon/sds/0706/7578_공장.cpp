#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define ll long long 
#define MAX 1000000
#define seg vector<long long>

seg segment;
ll B[MAX+1], re[MAX+1], A[MAX+1];

ll sum_segment_tree(ll node, ll start, ll end, ll left, ll right) {
    if(start > right || end < left) return 0;
    if(left <= start && end <= right) return segment[node];
    ll mid = (start + end) / 2;

    return sum_segment_tree(node*2, start, mid, left, right) + sum_segment_tree(node*2+1, mid+1, end, left, right);
}

void update_segment_tree(ll node, ll start, ll end, ll idx, ll diff) {
    if(start > idx || end < idx) return;
    segment[node]++;
    if(start == end) return;
    ll mid = (start + end) / 2;
    update_segment_tree(node*2, start, mid, idx, diff);
    update_segment_tree(node*2+1, mid+1, end, idx, diff);
}

int main() {
    ll tree_h = (ll)ceil(log2(MAX));
    ll tree_size = 1<<(tree_h+1);
    segment.reserve(tree_size);
    ll N; cin>>N;
    for(int i=0;i<N;i++) {
        cin >> A[i];
    }
    for(int i=0;i<N;i++) {
        int n; cin>>n;
        B[n] = i;
    }

    for(int i=0;i<N;i++) {
        ll AN = A[i];
        ll Blo = B[AN];
        re[Blo] = sum_segment_tree(1, 0,  N-1, Blo, N);
        update_segment_tree(1, 0, N-1, Blo, 1);
    }
    ll sum = 0;
    for(int i=0;i<N;i++) sum += re[i];
    cout << sum << "\n";
}