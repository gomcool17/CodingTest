#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;
int N, M;
int flood[501][501];
int main() {
    cin >> N >> M;
    fill(&flood[0][0], &flood[500][501], INF);

    for(int i=0;i<M;i++) {
        int a,b; cin>>a>>b;
        flood[a][b] = 1;
    }

    for(int i=1;i<=N;i++) flood[i][i] = 1;

    for(int k=1;k<=N;k++) 
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++) flood[i][j] = min(flood[i][j], flood[i][k] + flood[k][j]);

    int cnt = 0;
	bool f = true;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (flood[i][j] != INF || flood[j][i] != INF)
				continue;
			else
				f = false;
		}
		if (f)
			cnt++;
		f = true;
	}

	cout << cnt;
}