#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
long long arr[4000][4];
vector<long long> AB,CD;
int main() {
    cin >> N;
    for(int i=0;i<N;i++) {
        for(int j=0;j<4;j++) cin >> arr[i][j];
    }

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            AB.push_back({arr[i][0] + arr[j][1]});
            CD.push_back({arr[i][2]+arr[j][3]});
        }
    }
    sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end());

    long long re = 0;
    long long M = N*N;
    for(long long i=0;i<M;i++) {
        long long n = lower_bound(CD.begin(), CD.end(), -AB[i]) - CD.begin();
        if(AB[i] + CD[n] == 0) {
            long long ab = i + 1, cd = n + 1;
            long long abcnt = 1, cdcnt = 1;
            long long abN = AB[i], cdN = CD[n];

            while(ab < M && abN == AB[ab]) {
                abcnt++;
                ab++;
                i++;
            }

            while(cd < M && cdN == CD[cd]) {
                cdcnt++;
                cd++;
            }
            re += abcnt*cdcnt;
        }
    }

    cout << re << "\n";
}