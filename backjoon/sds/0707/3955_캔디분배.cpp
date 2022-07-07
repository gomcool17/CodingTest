#include <iostream>
#include <cstdio>
using namespace std;

#define ll long long

ll EEA(ll a, ll b) {
	ll r1 = a, r2 = b, s1 = 1, s2 = 0, t1 = 0, t2 = 1;
	ll r, s, t, q;
	while (r2) {
		q = r1 / r2;
		// gcd 계산
		r = r1 % r2;
		r1 = r2, r2 = r;

		// s 계산
		s = s1 - q * s2;
		s1 = s2, s2 = s;

		// t 계산
		t = t1 - q * t2;
		t1 = t2, t2 = t;
	}
	r = r1, s = s1, t = t1;
	if (r == 1) {
		if (t < 0) {
			t += a;

		}
		return t;
	}
	else return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T; cin>>T;

    while(T--) {
        ll a,b; cin>>a>>b;
        ll re = EEA(a,b);
        if(b==1) {
            if(a+1 > 1e9) cout << "IMPOSSIBLE\n";
            else cout << a+1 << "\n";
            continue;
        }
        if(a==1) {
            cout << 1 << "\n";
            continue;
        }
        if(re == 0) cout << "IMPOSSIBLE\n";
        else cout << re << "\n";
    }
}