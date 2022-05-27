#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> v;
vector<int> preorder, inorder;
int r;
void sol(int start, int end) {
    int n = r;
    int lo = -1;
   // if(r == N) return;
    if(start >= end) {
        return;
    }
    for(int i= start; i<end; i++) {
        if(inorder[i] == preorder[r]) {
            lo = i;
            break;
        }
    }
    r++;
    sol(start, lo);
    sol(lo+1, end);
    cout << preorder[n] << " ";
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int T; cin>>T;
    while(T--){
        cin >> N;
        for(int i=0;i<N;i++) {
            int n;cin>>n;
            preorder.push_back(n);
        }
        for(int i=0;i<N;i++) {
            int n;cin>>n;
            inorder.push_back(n);
        }
        sol(0, N);
        cout << "\n";
        v.clear(); preorder.clear(); inorder.clear();
        r=0;
    }
}