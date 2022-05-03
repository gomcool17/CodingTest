#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define A 1
#define B 2
#define CAN 1
#define CNAT 0
#define INF 987654321

int re = INF;
int loseMin = INF;
int winMax = 0;
int N,M; // 세로 가로
struct DIR {
    int y, x;
};

DIR dir[4] = {{1,0},{-1,0},{0,1},{0,-1}};

void playing(int ay, int ax, int by, int bx, int turn, int ac, int bc, vector<vector<int>> &board) {
    int cnt = 0;
    if(turn == A) {
        for(int i=0;i<4;i++) {
            int y = ay + dir[i].y;
            int x = ax + dir[i].x;

            if(y>=0 && x>=0 && y < N && x < N && board[y][x] == CAN) {
                
            }
            else cnt++;
        }
    }
    else {

    }

}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    int answer = -1;
    N = board.size();
    M = board[0].size();
    answer = re;
    cout << answer << "\n";
    return answer;
}
int main()
{
    //solution({{1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1}, {1,1,1,1,1}, {1,1,1,1,1}},{0,0},{4,4});
   // solution({{1,1,1},{1,1,1},{1,1,1}}, {1,0},{1,2});
   solution({{1,1,1},{1,0,1},{1,1,1}}, {1,0},{1,2});
}