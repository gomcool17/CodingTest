#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
const long long MN = 500001;
bool check[MN];
vector<int> g[MN];
long long rt, del, res;
int dep;
void dfs(int n)
{
	int cnt = 0;
//	check[n] = true;
	for (int next : g[n]) {
		cnt++;
	}

	if (cnt == 1)
		res++;
	
	return;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	long long N, W; cin >> N >> W;
	for (int i = 0; i < N - 1; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);

	}
	
	for (int i = 2; i <= N; i++) {
		dfs(i);
	}
	printf("%.10f",  (double)W / res);
}