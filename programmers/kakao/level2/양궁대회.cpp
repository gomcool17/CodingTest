#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int N;
int result[13];
int lion_s[11];
int max_di =-1;

void cul_score(vector<int> info) {
    int score = 10;
    int appeach = 0, lion = 0;
    string re = "";
    for(int i=0;i<11;i++) {
        if(info[i] < lion_s[i])
            lion += 10-i;
        else if(info[i] >= lion_s[i] && info[i]!=0) 
            appeach += 10-i;
    }
    if(appeach < lion) {
        if(lion - appeach > max_di) {
            for(int i=0;i<11;i++) 
                result[i] = lion_s[i];
            max_di = lion-appeach;
        }
        else if(lion - appeach == max_di) {
            for(int i=11; i>=0; i--) {
                if(result[i] < lion_s[i]) {
                    for(int j=0;j<11;j++) result[j] = lion_s[j];
                    break;
                }
                if(result[i] > lion_s[i]) break;
            }
        }   
    }  
}

void find_win(vector<int> info, int idx, int  cnt) {
    if(cnt == 0) {
        cul_score(info);
        return;
    }

    if(idx == 11) {
        if(cnt > 0) {
            lion_s[10] += cnt;
            cul_score(info);
            lion_s[10] -= cnt;
        }
        return;
    }
    
    if(info[idx] + 1 <= cnt) {
        lion_s[idx] = info[idx] + 1;
        find_win(info, idx + 1, cnt - (info[idx] + 1)); // 점수를 내는 경우
        lion_s[idx] = 0;
    }
    find_win(info, idx + 1, cnt); // 점수를 내지 않는 경우
    return;
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    N = n;
    find_win(info,0,n);
    if(max_di == -1) answer.push_back(-1);
    else {
        for(int i=0;i<11;i++) {
            answer.push_back(result[i]);
        }
    }
    return answer;
}

int main()
{
  // solution(5, {2,1,1,1,0,0,0,0,0,0,0});
  // solution(1, {1,0,0,0,0,0,0,0,0,0,0});
   solution(9, {0,0,1,2,0,1,1,1,1,1,1});
  // solution(10,{0,0,0,0,0,0,0,0,3,4,3});
}