#include <iostream>
#include <stack>
#include <vector>
#include <cstdlib>
#include <sstream>

using namespace std;

#define MAX 1000000000

vector<string> v;
stack<long long> st;
bool POP() {
    if(st.empty()) return false;
    st.pop();
    return true;
}

bool MUL(){
    if(st.size() < 2) return false;
    long long n1 = st.top(); st.pop();
    long long n2 = st.top(); st.pop();
    st.push(n1*n2);
    return true;
}

bool DIV(){
    if(st.size() < 2) return false;
    long long n1 = st.top(); st.pop();
    long long n2 = st.top(); st.pop();
    if(n1 == 0) return false;
    long long n = llabs(n2) / llabs(n1);
    if(n1 * n2 < 0 ) n *= -1;
    st.push(n);
    return true;
}
bool MOD() {
    if(st.size() < 2) return false;
    long long n1 = st.top(); st.pop();
    long long n2 = st.top(); st.pop();
    if(n1 == 0) return false;
    long long n = llabs(n2) % llabs(n1);
    if(n2 < 0 ) n *= -1;
    st.push(n);
    return true;
}
bool INV() {
    if(st.empty()) return false;
    long long n = st.top(); st.pop();
    n *= -1;
    st.push(n);
    return true;
}
bool DUP() {
    if(st.empty()) return false;
 //   cout << "dup\n";
    long long n = st.top(); 
    st.push(n);
    return true;
}

bool SWP() {
    if(st.size() < 2) return false;
    long long n1 = st.top(); st.pop();
    long long n2 = st.top(); st.pop();
    st.push(n1); st.push(n2);
    return true;
}
bool ADD() {
    if(st.size() < 2) return false;
    long long n1 = st.top(); st.pop();
    long long n2 = st.top(); st.pop();
    st.push(n1+n2);
    return true;
}

bool SUB() {
    if(st.size() < 2) return false;
    long long n1 = st.top(); st.pop();
    long long n2 = st.top(); st.pop();
    st.push(n2-n1);
    return true;
}

bool NUM(string str) {
    istringstream stt(str);
    string s[2];
    stt >> s[0] >> s[1];
    long long n = stol(s[1]);
    st.push(n);
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while(1) {
        v.clear();
        while(1) {
            string ss; getline(cin, ss);
            if(ss=="") continue;
            if(ss == "END") break;
            if(ss=="QUIT") exit(0);
            v.push_back(ss);
        }

        int N; cin>>N;
        while(N--) {
            long long n; cin>>n; 
            st.push(n);
            bool notError;
            for(int i=0;i<v.size();i++) {
                if(v[i] == "POP") notError = POP();
                if(v[i] == "MUL") notError = MUL();
                if(v[i] == "DIV") notError = DIV();
                if(v[i] == "MOD") notError = MOD();
                if(v[i] == "INV") notError = INV();
                if(v[i] == "DUP") notError = DUP();
                if(v[i] == "SWP") notError = SWP();
                if(v[i] == "ADD") notError = ADD();
                if(v[i] == "SUB") notError = SUB();
                if(v[i].size() > 3) notError =  NUM(v[i]);

                if(!st.empty() && llabs(st.top()) > MAX) notError = false;
                if(!notError) break;
            }

            if(!notError || st.size() != 1) cout << "ERROR\n";
            else cout << st.top() << "\n";
            while(!st.empty()) st.pop();
        }
        cout << "\n";
    }
}