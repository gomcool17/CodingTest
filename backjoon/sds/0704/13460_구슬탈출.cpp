#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define WALL 9
#define EMPTY 8
#define HOLE 3
#define RED 0
#define BLUE 1

bool color_check[2][11][11]; // 0 : red, 1 : blue
int re = 987654321;
int N, M;

struct INFO {
    int y,x;
    int color;
};

bool cmp_up(const INFO &a, const INFO &b) {
    return a.y < b.y;
}

bool cmp_down(const INFO &a, const INFO &b) {
    return a.y > b.y;
}

bool cmp_right(const INFO &a, const INFO &b) {
    return a.x > b.x;
}

bool cmp_left(const INFO &a, const INFO &b) {
    return a.x < b.x;
}

void init(int copys[11][11], int board[11][11]) {
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            copys[i][j] = board[i][j];
        }
    }
}

void get_result(int cnt) {
    re = min(re, cnt);
}

void prints(int board[11][11],int cnt) {
    cout << cnt << "\n";
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(board[i][j] == WALL) cout << "#";
            if(board[i][j] == EMPTY) cout << ".";
            if(board[i][j] == HOLE) cout << "O";
            if(board[i][j] == RED) cout << "R";
            if(board[i][j] == BLUE) cout << "B";
        }
        cout << "\n";
    }
    cout << "\n";
}
void game(int board[11][11], int cnt, vector<INFO> v, string str) {
    prints(board, 99);
    int save[11][11];
    vector<INFO> info;
    bool flag[2]; flag[0] = false, flag[1] = false;
    bool visited[2]; visited[0] = false; visited[1] = false;
    vector<INFO> tmp;
  //  if(cnt == 4) exit(0);
    if(str != "up") {
    init(save, board);
    info = v;
    sort(info.begin(), info.end(), cmp_up);
    for(int i=0;i<2;i++) {
        int y = info[i].y, x = info[i].x;
        int color = info[i].color;
        int sy, sx;
        cout << y << " " << x << " " <<color << "\n";
        save[y][x] = EMPTY;
        for(int i=y; i>=0; i--) {
            if(save[i][x] == HOLE) {
                flag[color] = true; break;
            }
            if(save[i][x] != EMPTY) {
               // cout << "noempyu\n";
                if(color_check[color][i+1][x]) {
                    visited[color] = true;
                }
                save[i+1][x] = color;
                color_check[color][i+1][x] = true;
                tmp.push_back({i+1,x,color});
                break;
            }
        }
    }
    for(int k=0;k<tmp.size();k++) {
        cout << tmp[k].y << " " << tmp[k].x << " " <<tmp[k].color<<"\n";
    }
    if(visited[BLUE] && visited[RED]) return;
    cout << "up\n";
    prints(save,cnt);
    if(flag[BLUE]) return;
    if(flag[RED]) {
        get_result(cnt);
        return;
    }
    game(save, cnt+1, tmp, "up");
    color_check[info[0].color][info[0].y][info[0].x] = false;
    color_check[info[1].color][info[0].y][info[0].x] = false;
    }


    tmp.clear();
    init(save, board);
    info = v;
    sort(info.begin(), info.end(), cmp_down);
    flag[0] = false, flag[1] = false;
    visited[0] = false; visited[1] = false;
    for(int i=0;i<2;i++) {
        int y = info[i].y, x = info[i].x;
        int color = info[i].color;
        int sy, sx;
      //  cout << y << " " << x << " " <<color << "\n";
        save[y][x] = EMPTY;
        for(int i=y; i<=N; i++) {
            if(save[i][x] == HOLE) {
                flag[color] = true; break;
            }
            if(save[i][x] != EMPTY) {
                if(color_check[color][i-1][x]) {
                    visited[color] = true;
                }
             //   cout << "noempyu\n";
                save[i-1][x] = color;
                color_check[color][i-1][x] = true;
                tmp.push_back({i-1,x,color});
                break;
            }
        }
    }
    if(visited[BLUE] && visited[RED]) return;
    cout << "down\n";
    prints(save,cnt);
    if(flag[BLUE]) return;
    if(flag[RED]) {
        get_result(cnt); return;
    }
    game(save, cnt+1, tmp);
    color_check[info[0].color][info[0].y][info[0].x] = false;
    color_check[info[1].color][info[0].y][info[0].x] = false; 

    tmp.clear();
    init(save, board);
    info = v;
    sort(info.begin(), info.end(), cmp_right);
    flag[0] = false, flag[1] = false;
    visited[0] = false; visited[1] = false;
    for(int i=0;i<2;i++) {
        int y = info[i].y, x = info[i].x;
        int color = info[i].color;
        int sy, sx;
    //    cout << y << " " << x << " " <<color << "\n";
        save[y][x] = EMPTY;
        for(int i=x; i<=M; i++) {
            if(save[y][i] == HOLE) {
                flag[color] = true; break;
            }
            if(save[y][i] != EMPTY) {
                if(color_check[color][y][i-1]) {
                    visited[color] = true;
                }
            //    cout << "noempyu\n";
                save[y][i-1] = color;
                color_check[color][y][i-1] = true;
                tmp.push_back({y,i-1,color});
                break;
            }
        }
    }
    if(visited[BLUE] && visited[RED]) return;
    cout << "right\n";
    prints(save,cnt);
    if(flag[BLUE]) return;
    if(flag[RED]) {
        get_result(cnt);
        return;
    }
    game(save, cnt+1, tmp);
   color_check[info[0].color][info[0].y][info[0].x] = false;
   color_check[info[1].color][info[0].y][info[0].x] = false;

    tmp.clear();
    init(save, board);
    info = v;
    sort(info.begin(), info.end(), cmp_left);
    flag[0] = false, flag[1] = false;
    visited[0] = false; visited[1] = false;
    for(int i=0;i<2;i++) {
        int y = info[i].y, x = info[i].x;
        int color = info[i].color;
        int sy, sx;
     //   cout << y << " " << x << " " <<color << "\n";
        save[y][x] = EMPTY;
        for(int i=x; i>=0; i--) {
            if(save[y][i] == HOLE) {
                flag[color] = true; break;
            }
            if(save[y][i] != EMPTY) {
                if(color_check[color][y][i+1]) {
                    visited[color] = true;
                }
            //    cout << "noempyu\n";
                save[y][i+1] = color;
                color_check[color][y][i+1] = true;
                tmp.push_back({y,i+1,color});
                break;
            }
        }
    }
    if(visited[BLUE] && visited[RED]) return;
    cout << "left\n";
    prints(save,cnt);
    if(flag[BLUE]) return;
    if(flag[RED]){
         get_result(cnt); return;
    }
    game(save, cnt+1, tmp);
   color_check[info[0].color][info[0].y][info[0].x] = false;
   color_check[info[1].color][info[0].y][info[0].x] = false;
}

int main() {
    cin >> N >> M;
    int board[11][11];
    vector<INFO> v;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            char c; cin>>c;
            if(c=='#') board[i][j] = WALL;
            else if(c == '.') board[i][j] = EMPTY;
            else if(c=='O') board[i][j] = HOLE;
            else if(c=='R'){
                 board[i][j] = RED;
                 v.push_back({i,j,RED});
            }
            else {
                board[i][j] = BLUE;
                v.push_back({i,j,BLUE});
            }
        }
    }

    game(board, 1, v, "");
    if(re > 10) cout << -1 << "\n";
    else cout << "result : " << re << "\n";
}