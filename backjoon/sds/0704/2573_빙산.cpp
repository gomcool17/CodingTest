#include <iostream>
#include <queue>
#include <cstdlib>
#include <cstring>
using namespace std;

int N,M;
int board[300][300];
int tmp[300][300];
bool visited[300][300];
vector<pair<int,int>> v;
struct DIR {
    int y,x;
};
DIR dir[4] = {{1,0},{-1,0},{0,1},{0,-1}};
void bfs(int idx, int jdx) {
    queue<pair<int,int>> q;
    q.push({idx,jdx});
    visited[idx][jdx] = true;
    while(!q.empty()) {
        int ny = q.front().first;
        int nx = q.front().second;
        q.pop();
        int cnt=0;
        for(int i=0;i<4;i++) {
            int y = ny + dir[i].y;
            int x = nx + dir[i].x;
            
            if(y >= 0 && x >= 0 && y < N && x < M && !visited[y][x]) {
                if(board[y][x] > 0) {
                    q.push({y,x});
                    visited[y][x] = true;
                }
            }
        }
    }
}

int melt(int idx, int jdx) {
   // cout << idx << " " << jdx << "\n";
    int cnt = 0;
    for(int i=0;i<4;i++) {
        int y = idx + dir[i].y;
        int x = jdx + dir[i].x;
        if(board[y][x] <= 0) {
            cnt++;
        }
    }
    return cnt;
}
int main() {
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++){ 
            cin >> board[i][j];
            if(board[i][j] > 0) v.push_back({i,j});
        }
    }

    int year = 0;
    while(1) {
        int cnt = 0;
        for(int i=0;i<v.size();i++) {
            int y = v[i].first; 
            int x = v[i].second;
            if(!visited[y][x]) {
                bfs(y,x);
                cnt++;
            }
        }
        if(cnt == 0) {
            year = 0;
            break;
        }
        if(cnt >=2) {
            break;
        } 

        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                if(board[i][j] > 0) {
                    tmp[i][j] = board[i][j] - melt(i,j);
                }
            }
        }

        v.clear();
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
            if(tmp[i][j] > 0) v.push_back({i,j});
               board[i][j] = tmp[i][j];
            }
        }
        year++;
        for(int i=0;i<N;i++) memset(visited[i],false,sizeof(visited[i]));
        for(int i=0;i<N;i++) memset(tmp[i], 0, sizeof(tmp[i]));
    }
    cout << year << "\n";
}