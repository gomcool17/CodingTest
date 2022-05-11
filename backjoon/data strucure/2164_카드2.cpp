#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N;cin>>N;
    queue<int> q;
    for(int i=1;i<=N;i++) q.push(i);

    int n;
    while(q.size() != 1) {
        q.pop();
        //if(q.size() == 1) break;
        n = q.front();
        q.push(n);
        q.pop();
    }
    cout << q.front() << "\n";
}