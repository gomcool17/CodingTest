#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

bool right(int n, int d, char c)
{
    if(c == '=') {
        if(n == d) return true;
    }
    else if(c == '<'){
        if(n > d) return true;
    }
    else {
        if(n < d) return true;
    }
    
    return false;
}
int solution(int n, vector<string> data) {
    int answer = 0;
    string v = "ACFJMNRT";
    //put_data(0);
    do { 
        bool flag = true;
        for(int i=0;i<data.size();i++) {
            char a = data[i][0], b = data[i][2];
            int n = data[i][4] - '0' + 1;
            int d = abs((int)(v.find(a) - v.find(b)));
            if(!right(n,d,data[i][3])) {
                flag = false;
                break;
            }
        }
        if(flag)
            answer++;
    }while(next_permutation(v.begin(), v.end()));
    return answer;
}