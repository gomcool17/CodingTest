#include <iostream>
#include <algorithm>
using namespace std;

const long long MN = 100001;

long long arr[MN];
long long INF = -1001;
long long dnc(int L, int R) {
	if (L == R) return arr[L];

	long long mid = (L + R) / 2;
	long long ret = max(dnc(L, mid), dnc(mid + 1, R));
    cout << "lR : " << L << " " <<R << "\n";
	long long l = INF, r = INF;
	long long sum = 0;
	for (int i = mid; i >= L; i--) {
		sum += arr[i];
		l = max(l, sum);
	}
	sum = 0;
	for (int i = mid + 1; i <= R; i++) {
		sum += arr[i];
		r = max(r, sum);
	}
	return max(ret, l+r);
}

int main()
{
	//int NUM; cin >> NUM;

	//while (NUM--) {
		int N; cin >> N;

		for (int i = 1; i <= N; i++)
			cin >> arr[i];

		cout << dnc(1, N) << '\n';
//	}
}