// https://www.acmicpc.net/problem/7576
// 토마토
#include <iostream>
#include <queue>
#include <set>

using namespace std;

struct DIR
{
    int y,x;
};

int M, N;
DIR dir[4] = {{0,1},{0,-1},{1,0},{-1,0}};
int arr[1001][1001];
vector<pair<int,int>>v;
int cnt[1001][1001];
bool check[1001][1001];
int bfs() {
    queue<pair<int,int>> q;
    int ans=0;
    for(int i=0;i<v.size();i++) q.push({v[i].first, v[i].second});

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0;i<4;i++) {
            int ny = y + dir[i].y;
            int nx = x + dir[i].x;
            if(ny >= 0 && nx >= 0 && ny < N && nx < M && !check[ny][nx]) {
                check[ny][nx] = true;
                if(arr[ny][nx] == 0) {
                    arr[ny][nx] = 1;
                    q.push({ny,nx});
                    cnt[ny][nx] = cnt[y][x] + 1;
                    ans = max(ans, cnt[ny][nx]);
                }
            }
        }
    }
    return ans;
}

int main() {
    cin >> M>>N;

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 1) v.push_back({i,j});
        }
    }
    
    int ans = bfs();
    bool f = false;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(arr[i][j] == 0) f = true;
        }
    }
    if(f) cout << -1 << "\n";
    else cout << ans << "\n";
}