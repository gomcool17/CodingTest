#include <iostream>
#include <cstdlib>
using namespace std;

#define MAX 1000001
bool check[MAX];
int main(){
    ios_base::sync_with_stdio(false); 
    cout.tie(NULL); cin.tie(NULL);
    for(int i=2;i*i<MAX;i++) {
        if(check[i]) continue;
        for(int j=i*i;j<MAX;j+=i) check[j] = true;
    }
   
    string P;
    int K;
    cin >> P >> K;
    int re = 0;
    for(int i=2;i<K;i++) {
        if(check[i]) continue;
        int ans = 0;
        for(int j=0;j<P.length();j++) {
            ans = (ans * 10 + (P[j]-'0')) % i; // i => p
        }
        if(ans == 0) {
           re = i; break;
        }
    }
    if(re != 0) cout << "BAD " << re << "\n";
    else cout << "GOOD\n";
}