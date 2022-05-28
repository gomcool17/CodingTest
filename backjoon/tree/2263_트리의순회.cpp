#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> inorder, postorder;
int r;
void sol(int in_s, int in_e, int pos_s, int pos_e) {
    if(in_s > in_e && pos_s>pos_e) return;
    cout << postorder[pos_e] << " ";
    for(int i = in_s; i<= in_e; i++) {
        if(postorder[pos_e] == inorder[i]) {
            int n = i - in_s;
            sol(in_s, i-1, pos_s,pos_s+n-1);
            sol(i+1, in_e, pos_s+n, pos_e-1);
            break;
        }
    }
}

int main() {
    cin>>N;
    for(int i=0;i<N;i++) {
        int n; cin>>n;
        inorder.push_back(n);
    }

    for(int i=0;i<N;i++) {
        int n; cin>>n;
        postorder.push_back(n);
    }
    r = N-1;
    sol(0, N-1,0,N-1);
}