#include <iostream>
#include <queue>

using namespace std;
priority_queue<int> max_q;
priority_queue<int, vector<int>, greater<int>> min_q;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N; cin>>N;
    while(N--) {
        int n; cin>>n;
        if(max_q.size() == min_q.size()) {
            max_q.push(n);
        }
        else min_q.push(n);

        if(!min_q.empty() && max_q.top() > min_q.top()) {
            int n = max_q.top(), n2 = min_q.top();
            max_q.pop(), min_q.pop();
            max_q.push(n2), min_q.push(n);
        }
        cout << max_q.top() << "\n";
    }

}