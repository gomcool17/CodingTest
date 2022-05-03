#include <string>
#include <vector>
#include <iostream>

using namespace std;

int p[1002][1002];
int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    
    for(int i=0;i<skill.size();i++) {
        int dgree = skill[i][0];
        int n;
        if(dgree == 1) 
            n = -skill[i][5];
        else n = skill[i][5];
        p[skill[i][1]][skill[i][2]] += n;
        p[skill[i][3] + 1][skill[i][4] + 1] += n;
        p[skill[i][3] + 1][skill[i][2]] += -n;
        p[skill[i][1]][skill[i][4] + 1] += -n;
    }
    
   
    for(int i=0;i<board.size();i++) {
        for(int j=1;j<board[i].size();j++) {
            p[i][j] = p[i][j - 1] + p[i][j];
        }
    }
    
    for(int i=0;i<board[0].size();i++) {
        for(int j=1;j<board.size();j++) {
            p[j][i] = p[j-1][i] + p[j][i];
        }
    }
    
     for(int i=0;i<board.size();i++) {
        for(int j=0;j<board[i].size();j++) {
            board[i][j] += p[i][j];
            if(board[i][j] >= 1) answer++;
        }
    }
    return answer;
}