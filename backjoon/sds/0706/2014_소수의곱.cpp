#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define ll long long
const ll MAX = (ll)2 << 31;
priority_queue<ll, vector<ll>, greater<ll>> pq;
vector<ll> v;

int main() {
    int K,N; cin>>K>>N;
    for(int i=0;i<K;i++){
        int k; cin>>k;
        v.push_back(k);
        pq.push(k);
    }

    ll re=0;
    while(N--) {
        re = pq.top(); pq.pop();
        for(ll i=0;i<v.size();i++) {
            if(re*v[i] > MAX) break;;
            pq.push(re*v[i]);
            if(re % v[i] == 0)  break;
        }
    }
    cout << re << "\n";
}