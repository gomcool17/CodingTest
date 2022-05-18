#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

void sol(int start, int end) {
    if(start > end) return;
    int root = v[start];
    int i;
    for(i = start+1;i<=end;i++) {
        if(v[i] > root) break;
    }

    sol(start + 1,i-1);
    sol(i,end);
    cout << v[start] << "\n";
}

int main() {
    int n;
    while(cin>>n) v.push_back(n);

    sol(0,v.size()-1);   
}