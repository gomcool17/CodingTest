#include <iostream>
#include <vector>
using namespace std;

#define MAX 4000001

bool check[MAX];
vector<int> prime;
void checkPrime(){
    for(int i=2;i*i<MAX;i++) {
        if(check[i]) continue;
        for(int j=i*i;j<MAX;j+=i) check[j] = true;
    }
    for(int i=2;i<=MAX;i++) {
        if(!check[i]) prime.push_back(i);
    }
}

int main() {
    checkPrime();
    int N; cin>>N;
    int start = 0, end = 0;
    int sum = prime[0];
    int re = 0;
    int s = 0;
    while(1) {
       // cout << start << " " << end << " " << sum << "\n";
        if(sum == N) {
             re++;
        }
        if(prime[start] >= N && sum <= N || start > end || end >= prime.size()) break;
        if(sum <= N) {
            end++;
            sum += prime[end];
        }
        else {
            sum -= prime[start];
            start++;
        }
    }
    cout << re << "\n";
}