#include <iostream>
#include <algorithm>
using namespace std;

int arr[501][501];

int main(){
    int N; cin>>N;
    for(int i=1;i<=N;i++) 
        for(int j=0;j<i;j++) cin >> arr[i][j];

    for(int i=N-1;i>=1;i--) {
        for(int j=0;j<i+1;j++) {
            arr[i][j] += max(arr[i+1][j], arr[i+1][j+1]);
        }
    }
    cout << arr[1][0];
}