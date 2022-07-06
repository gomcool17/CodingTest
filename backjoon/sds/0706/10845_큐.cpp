#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

int main() {
    int N; cin>>N;

    while(N--) {
        string s; cin>>s;
        if(s=="push") {
            int n; cin>>n;
            q.push(n);
        }
        else if(s=="pop") {
            if(q.empty()) {
                cout << -1 << "\n"; continue;
            }
            cout << q.front() << "\n";
            q.pop();
        }
        else if(s=="empty") {
            if(q.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if(s=="size") {
            cout << q.size() << "\n";
        }
        else if(s=="front") {
            if(q.empty()) cout << -1 << "\n";
            else cout << q.front() << "\n";
        }
        else { //bac
            if(q.empty()) cout << -1 << "\n";
            else cout <<q.back() << "\n";
        }
    }
}