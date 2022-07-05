#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long N,M; cin>>N>>M;
    vector<long long> v;
    for(int i=0;i<N;i++) { long long n; cin>>n; v.push_back(n);}
    v.push_back(0);
    int start = 0, end = 0;
    long long sum = v[0];
    int re = 0;
    while(1) {
       // if(sum == M) re++;
        if(sum == M) re++;
        if(end == start && start == N-1) break;
      //   cout <<"1 :" <<  start << " " << end << " " << sum << "\n";
       // if(sum == M) re++;
        if(start >=  N) {
            if(sum <= M) break;
            end++;
            sum -= v[end];
        }
        else {
            if(sum < M || start==end) {
                start++;
                sum += v[start];
             }
             else {
                sum -= v[end];
                end++;
             }
        }
        if(start >= N) continue;
      //  cout <<"2 :" <<  start << " " << end << " " << sum << "\n";
    }
    cout << re << "\n";
}