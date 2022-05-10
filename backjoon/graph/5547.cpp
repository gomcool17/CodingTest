#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int board[102][102];
bool check[102][102];
int R,C;
vector<pair<int,int>> v;

struct DIR{
    int y,x;
};

int dy[2][6] = {
    {-1, 0, 1, 1, 0, -1},
    {-1, 0, 1, 1, 0, -1}
};  // 세로
int dx[2][6] = {
    {0, 1, 0, -1, -1, -1},
    {1, 1, 1, 0, -1, 0}
};  // 가로

DIR dir[2][6] = {
     {{-1,0},{0,1},{1,0},{1,-1},{0,-1},{-1,-1}},
    {{-1,1},{0,1},{1,1},{1,0},{0,-1},{-1,0}}
};
 
int main() {
    cin>>C>>R;

    for(int i=1;i<=R;i++) for(int j=1;j<=C;j++) cin>>board[i][j];

    check[0][0] = true;

    queue<pair<int,int>> q;
    q.push({0,0});

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0;i<6;i++) {
            int ny = y + dir[y%2][i].y;
            int nx = x + dir[y%2][i].x;
            if(ny>=0&&nx>=0&&y<=R+1&&x<=C+1) {
                if(check[ny][nx] || board[ny][nx]) continue;
                check[ny][nx] = true;
                q.push({ny,nx});
            }
        }
    }

    int ans=0;
    for(int i=1;i<=R;i++) {
        for(int j=1;j<=C;j++) {
            if(!board[i][j]) continue;
            int cnt=0;
            for(int k=0;k<6;k++) {
                int ny = i+dir[i%2][k].y;
                int nx = j+dir[i%2][k].x;
                if(check[ny][nx])  ans++;
            }
        }
    }
    cout << ans << "\n";
}