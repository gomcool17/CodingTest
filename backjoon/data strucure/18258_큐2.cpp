#include <iostream>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N; cin >> N;
    string t;
   // getline(cin,t);
    cin.ignore();
    queue<int> q;
    for(int i=0;i<N;i++) {
        string s; getline(cin, s);
        istringstream iss(s);
        string ss[2]; iss >> ss[0] >> ss[1];
        if(ss[0] == "push") {
            int n = stoi(ss[1]);
            q.push(n);
        }
        else if(ss[0] == "pop") {
            if(q.empty()) cout << "-1\n";
            else {
                int n = q.front();
                cout << n << "\n";
                q.pop();
            }
        }
        else if(ss[0] == "size") {
            cout << q.size() << "\n";
        }
        else if(ss[0] == "empty") {
            if(q.empty()) cout << "1\n";
            else cout << "0\n";
        }
        else if(ss[0] == "front") {
            if(q.empty()) cout << "-1\n";
            else cout << q.front() << "\n";
        }
        else { // back
            if(q.empty()) cout << "-1\n";
            else cout << q.back() << "\n";
        }
    }
}