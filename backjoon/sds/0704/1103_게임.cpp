#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;

#define MAX 51
#define INF 2501
int board[MAX][MAX];
int dp[MAX][MAX];
int N,M;
int re;
bool visited[MAX][MAX];

struct DIR {
   int y, x;
};
DIR dir[4] = {{0,1},{0,-1},{-1,0},{1,0}};
int dfs(int idx, int jdx) {
   // cout << idx << " " << jdx << "\n";
    if(idx < 0 || jdx < 0 || idx >= N || jdx >= M || board[idx][jdx] == -1) return 0;

    if(visited[idx][jdx]) {
        cout << "-1\n";
        exit(0);
    }

    int &cache = dp[idx][jdx];
    if(cache != -1) return cache;

    visited[idx][jdx] = true;

    cache = 0;

    for(int i=0;i<4;i++) {
        int y = idx + dir[i].y * board[idx][jdx];
        int x = jdx + dir[i].x * board[idx][jdx];
        cache = max(cache, dfs(y,x) + 1);
    }

    visited[idx][jdx] = false;
    return cache;
}
int main() {
    cin >> N >> M;
    memset(dp, -1, sizeof(dp));
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            char c; cin >> c;
            if(c != 'H') board[i][j] = c - '0';
            else board[i][j] = -1;
        }
    }

   cout << dfs(0,0);
}