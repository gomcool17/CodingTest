#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MN 100

int r,c,k;
int rn=3;
int cn=3;
vector<int> board[100];

int main()
{
    cin >> r>>c>>k;
    int time =100;
    r -= 1; c -= 1;

    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            int n; cin>>n;
            board[i].push_back(n);
        }
    }

    bool flag = false;
    
    
    if(flag)
        cout << 100-time<<"\n";
    else 
        cout << -1 << "\n";
}