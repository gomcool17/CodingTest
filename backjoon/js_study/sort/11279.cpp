#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N; cin>>N;
    priority_queue<int> pq;

    while(N--) {
        int n; cin>>n;
        if(n==0) {
            if(pq.empty()) {
                cout << "0\n"; continue;
            }
            
            cout << pq.top() << "\n";
            pq.pop();
        }
        else pq.push(n);
    }
}