#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

char tmp[11][11];
bool red_check[11][11];
bool blue_check[11][11];
pair<int,int> hole;
int re = 0;
int N, M;
struct INFO {
    int y,x;
    char color;
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

void init(char copys[11][11], char board[11][11]) {
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            copys[i][j] = board[i][j];
        }
    }
}

void get_result(int cnt) {
    re = max(re, cnt);
}

void prints(char board[11][11],int cnt) {
    cout << cnt << "\n";
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}
void game(char board[11][11], int cnt, vector<INFO> v) {
    char save[11][11];
    cout << "up" <<"\n";
    init(save, board);
    sort(v.begin(), v.end(), cmp_up);

    bool RED = false, BLUE = false;
    bool R=false, B = false;
    vector<INFO> next;
    prints(save, cnt); //
   // cout << "up\n";
    for(int i=0;i<2;i++) {
        int y = v[i].y;
        int x = v[i].x;
        char color = v[i].color;
        cout << y << " " << x << " " << color << "\n";
        save[y][x] = '.';
        for(int i=y;i>=0;i--) {
            if(save[i][x] == 'O') {
                if(color == 'R') RED = true;
                if(color == 'B') BLUE = true;
                break;
            }
            if(save[i][x] != '.') {
                if(i+1 != y) {
                if(color == 'R') {
                    if(red_check[i+1][x]) R = true;
                    red_check[i+1][x] = true;
                }
                else {
                    if(blue_check[i+1][x]) B = true;
                    blue_check[i+1][x] = true;
                }
                
                next.push_back({i+1,x,color});
                }
                save[i+1][x] = color;
                break;
            }
        }
    }
    if(R&&B) return;
    if(BLUE) return;
    if(RED){
        get_result(cnt);
        return;
    }
    prints(save, cnt); //
    game(save, cnt+1, next);

    cout << "down\n";
    init(save, board);
    prints(save, cnt); //
    sort(v.begin(), v.end(), cmp_down);
    v.clear();
    RED = false, BLUE = false;
    R = false, B = false;
    for(int i=0;i<2;i++) {
        int y = v[i].y;
        int x = v[i].x;
        char color = v[i].color;
        save[y][x] = '.';
        for(int i=y;i < N;i++) {
            if(save[i][x] == 'O') {
                if(color == 'R') RED = true;
                if(color == 'B') BLUE = true;
                break;
            }
            if(save[i][x] != '.') {
                if(i-1 != y) {
                if(color == 'R') {
                    if(red_check[i-1][x]) R = true;
                    red_check[i-1][x] = true;
                }
                else {
                    if(blue_check[i-1][x]) B = true;
                    blue_check[i-1][x] = true;
                }
                
                next.push_back({i-1,x,color});
                }
                save[i-1][x] = color;
                break;
            }
        }
    }
    if(R&&B) return;
    if(BLUE) return;
    if(RED){
        get_result(cnt);
        return;
    }
    prints(save, cnt); //
    game(save, cnt+1, next);
    
    cout << "right\n";
    init(save, board);
    prints(save, cnt); //
    sort(v.begin(), v.end(), cmp_right);
     RED = false, BLUE = false;
      R = false, B = false;
    for(int i=0;i<2;i++) {
        int y = v[i].y;
        int x = v[i].x;
        char color = v[i].color;
        save[y][x] = '.';
        for(int i=x;i<M;i++) {
            if(save[y][i] == 'O') {
                if(color == 'R') RED = true;
                if(color == 'B') BLUE = true;
                break;
            }
            if(save[y][i] != '.') {
                if(i-1 != x) {
                if(color == 'R') {
                    if(red_check[y][i-1]) R = true;
                    red_check[y][i-1] = true;
                }
                else {
                    if(blue_check[y][i-1]) B = true;
                    blue_check[y][i-1] = true;
                }
                
                next.push_back({y,i-1,color});
                }
                save[y][i-1] = color;
                break;
            }
        }
    }
    if(R&&B) return;
    if(BLUE) return;
    if(RED){
        get_result(cnt);
        return;
    }
    prints(save, cnt); //
    game(save, cnt+1, next);

    cout << "left\n";
    init(save, board);
    prints(save, cnt); //
    sort(v.begin(), v.end(), cmp_left);
     RED = false, BLUE = false;
      R = false, B = false;
    for(int i=0;i<2;i++) {
        int y = v[i].y;
        int x = v[i].x;
        char color = v[i].color;
        save[y][x] = '.';
        for(int i=x;i>=0;i--) {
            if(save[y][i] == 'O') {
                if(color == 'R') RED = true;
                if(color == 'B') BLUE = true;
                break;
            }
            if(save[y][i] != '.') {
                if(i+1 != x){
                if(color == 'R') {
                    if(red_check[y][i+1]) R = true;;
                    red_check[y][i+1] = true;
                }
                else {
                    if(blue_check[y][i+1]) B = true;
                    blue_check[y][i+1] = true;
                }
                
                next.push_back({y,i+1});
                }
                save[y][i+1] = color;
                break;
            }
        }
    }
    if(R&&B) return;
    if(BLUE) return;
    if(RED){
        get_result(cnt);
        return;
    }
    prints(save, cnt); //
    game(save, cnt+1, next);
}

int main() {
    cin >> N >> M;
    char board[11][11];
    vector<INFO> v;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> board[i][j];
            if(board[i][j] == 'B' || board[i][j] == 'R') {
                v.push_back({i,j, board[i][j]});
               // if(board[i][j] == 'B') blue_check[i][j] = true;
               // else red_check[i][j] = true;
            }
            if(board[i][j] == 'O') hole.first = i, hole.second = j;
        }
    }

    game(board, 1, v);
    cout << "result : " << re << "\n";
}