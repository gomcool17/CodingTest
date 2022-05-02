#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <queue>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;

// 다른 것들 풀고 마지막에
bool check[27];
vector<string> res;
vector<string> b;
vector<pair<int,int>> v;
int c;
int M,N;
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
struct DIR {
    int y,x;
};
DIR dir[4] = {{1,0},{0,1},{-1,0},{0,-1}};
bool check_can(int idx, int jdx) {
    char c = b[idx][jdx];
    cout << "check_c : " << c << "\n";
    bool visit[101][101];
    for(int i=0;i<M;i++) {
        memset(visit[i], false, sizeof(bool) * N);
    }
    visit[idx][jdx] = true;
    queue<pair<int,int>> lo;
    queue<pair<bool, int>> q;
    
    lo.push({idx,jdx});
    q.push({false,-1});
  //for(int i=0;i<4;i++) cout << check[i] << " ";
 //   cout << "\n";
 //   cout <<"=====\n";
    while(!q.empty()) {
        int y = lo.front().first;
        int x = lo.front().second;
        int di = q.front().second;
        bool f = q.front().first;
        q.pop();
        lo.pop();
        cout << "yx : " << y << " " << x << " " << di << " " << f << "\n";
        for(int d=0;d<4;d++) {
            int ny = y + dir[d].y, nx = x + dir[d].x;
            cout << ny << " " << nx << " " << b[ny][nx] << "\n";
            if(ny>=0 && nx>=0 && ny < M && nx < N && !visit[ny][nx]) {
                visit[ny][nx] = true;
                cout << ny << " " << nx << " " << b[ny][nx] << " " <<d << "\n";
                if(b[ny][nx] == '*') continue;
                if(b[ny][nx] == c) {
                    if(di == -1) return true;
                    if(di == d) return true;
                    if(!f) return true;
                }
                else if(b[ny][nx] == '.' || check[b[ny][nx] - 'A']) {
                    cout << " " << b[ny][nx] << "\n";
                    if(di == -1 || di == d) {
                        cout << "가\n";
                        q.push({f, d});
                        lo.push({ny,nx});
                        continue;
                    }
                    else if(di != d && !f) {
                        cout << "나\n";
                        q.push({true, d});
                        lo.push({ny,nx});
                        continue;
                    }
                }    
            }
        }
    }
    
    return false;
}

void dfs(int cnt, string s) {

    cout << cnt << " " << s << "\n";
    for(int i=0;i<v.size();i++) {
        int y = v[i].first, x = v[i].second;
     //   cout << "? : " <<  y << " " << x << " " << check[b[y][x] - 'A'] << "\n";
        if(check[b[y][x] - 'A']) continue;
        if(check_can(y,x)) {
            check[b[y][x] - 'A'] = true;
          //  cout << y << " " << x << "\n";
            cout << "\ncan " << b[y][x] << " " << s << "\n";
            dfs(cnt + 1, s + b[y][x]);
            check[b[y][x] - 'A'] = false;
        }
    }

    if(cnt >= c) {
        cout << s << "\n";
        res.push_back(s);
        //exit(0);
        return;
    }
    
    exit(0);
    return;
}

void init(vector<string> board,int m, int n) {
    memset(check, false, sizeof(char) * 27);
    res.clear();
    v.clear();
    b.clear();
    b = board;
    set<char> s;
    M = m, N = n;
    for(int i=0;i<board.size();i++) {
        for(int j=0;j<board[i].size();j++) {
            if(board[i][j] >= 'A' && board[i][j] <= 'Z') {
                if(s.count(board[i][j]) == 1) continue;
                s.insert(board[i][j]);
                v.push_back({i,j});
            }
        }
    }
    c = s.size();
    return;
}
string solution(int m, int n, vector<string> board) {
    string answer = "";
    init(board,m,n);
    dfs(0,"");
    cout << c << "\n";
    for(int i=0;i<v.size();i++) {
        cout << b[v[i].first][v[i].second] << " ";
    }
    cout << "\n";
  for(int i=0;i<res.size();i++) cout << res[i] << "\n";
    if(res.size() == 0) return "IMPOSSIBLE";
    sort(res.begin(), res.end());
    return answer;
}

int main()
{
    solution(5,5,{"FGHEI", "BAB..", "D.C*.", "CA..I", "DFHGE"});
    //ABCDFHGIE
   //solution(3,3,{"AAB","...","BCC"});
}