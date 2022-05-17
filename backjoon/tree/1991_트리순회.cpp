#include <iostream>
#include <vector>

using namespace std;

char R[27];
char L[27];

void pre(char root) {
    cout << root;
    if(L[root-'A'] != '.') pre(L[root-'A']);
    if(R[root-'A'] != '.') pre(R[root-'A']);
}

void in(char root) {
    if(L[root-'A'] != '.') in(L[root-'A']);
    cout << root;
    if(R[root-'A'] != '.') in(R[root-'A']);
}

void pos(char root) {
    if(L[root-'A'] != '.') pos(L[root-'A']);
    if(R[root-'A'] != '.') pos(R[root-'A']);
    cout << root;
}
int main() {
    int N; cin>>N;
    for(int i=0;i<N;i++) {
        char a,b,c; cin>>a>>b>>c;
        L[a-'A'] = b;
        R[a-'A'] = c;
    }

    pre('A');
    cout << "\n";
    in('A');
    cout << "\n";
    pos('A');
    cout << "\n";
}