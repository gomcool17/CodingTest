#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    char speak[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    long long N = 0;
    int lo = 0;
    p--;
   /* if(p == 0) {
        answer += speak[0];
        t--;
    }*/
    lo = -1;
    while(t > 0) {
        string s = "";
        int num = N;
        while(num) {
            s += speak[num%n];
            num /= n;
        }
        
        if(N == 0) s += "0";
        int si = s.size();
        int i=0;
        while(si) {
            lo++;
            if(t == 0) break;
            if(lo == m) lo = 0;
            
            if(lo == p) {
                reverse(s.begin(), s.end());
                answer += s[i];
                
                t--;
            }
            i++;
            si--;
        }
        N++;
    }
    
    return answer;
}