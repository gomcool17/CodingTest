// https://www.acmicpc.net/problem/2110
// 공유기 설치
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> house;
int N, M;

int sol(int num) {
    int count = 1;
    int last = house[0];
    for(int i=1;i<N;i++) {
        if(house[i] - last >= num) {
            count++;
            last= house[i];
        }
    }
    return count;
}
int main() {
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        int n; cin >> n;
        house.push_back(n);
    }
    sort(house.begin(), house.end());
    int low = 1;
    int high = house[N-1] - house[0];
    int ans = 0;
    while(low <= high) {
       // cout << low << " " << high << "\n";
        int mid = (low + high) / 2;
        if(sol(mid) < M) high = mid - 1;
        else {
            low = mid + 1;
            ans = mid;
        }
    }
    cout << low - 1 << "\n";
}