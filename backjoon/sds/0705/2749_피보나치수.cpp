#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000000
#define ll long long

vector<vector<ll>> mul(vector<vector<ll>> a, vector<vector<ll>> b) {
    vector<vector<ll>> c(a.size(),vector<ll>(b[0].size(),0));

    for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b[0].size(); j++) {
			for (int k = 0; k < b.size(); k++) {
				c[i][j] += a[i][k] * b[k][j];
				c[i][j] %= MOD;
			}
		}
	}

    return c;

}

vector<vector<ll>> pw(vector<vector<ll>> a, long long n) {
    if(n==1) return a;
    if(n%2) return mul(pw(a, n-1), a);
    vector<vector<ll>> tmp = pw(a, n/2);
    return mul(tmp, tmp);
}
int main() {
    long long n; cin>>n;
    if(n==1) {
        cout << 1 << "\n";
        return 0;
    }
     vector<vector<ll>> A(2, vector<ll>(2,0));
     A[0][0] = 1, A[0][1] = 1, A[1][0] = 1, A[1][1] =0;
     vector<vector<ll>> B(2, vector<ll>(1,0));
     B[0][0] = 1, B[0][1] = 0;

     A = pw(A, n-1);

     B = mul(A,B);

     cout << B[0][0] << "\n";
}