#include <iostream>
#include <deque>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;cin>>N;
    cin.ignore();
    deque<int> q;
    for(int i=0;i<N;i++) {
        string s; getline(cin, s);
        istringstream stt(s);
        string ss[2]; stt>>ss[0]>>ss[1];
        if(ss[0] == "push_front") {
            int n = stoi(ss[1]);
            q.push_front(n);
        }
        else if(ss[0] == "push_back") {
            int n = stoi(ss[1]);
            q.push_back(n);
        }
        else if(ss[0] == "pop_front") {
            if(q.empty()) cout << "-1\n";
            else {
                cout << q.front() << "\n";
                q.pop_front();
            }
        }
        else if(ss[0] == "pop_back") {
            if(q.empty()) cout << "-1\n";
            else {
                cout << q.back() << "\n";
                q.pop_back();
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