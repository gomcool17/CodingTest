#include <string>
#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
//하... 다시풀기
bool f;
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

bool cmp(pair<char, int> a, pair<char, int> b) {
    return a.second < b.second;
}
string solution(string s) {
    string answer = "";
    string rs = s;
    reverse(rs.begin(), rs.end());
    
    
    map<char, int> m;
    for(int i=0;i<s.size();i++) {
        if(s[i] >= 'a' && s[i] <= 'z') {
            if(m.find(s[i])== m.end()) m[s[i]] = 1;
            else m[s[i]]++;
        }
    }
    vector<pair<char, int>> save(m.begin(),m.end());
    sort(save.begin(), save.end(), cmp);

   // for(int i=0;i<save.size();i++) 
       // cout << save[i].first << " " << save[i].second <<"\n";

    string re = "";
    vector<string> r;
    int si = s.size();
    for(int i=0;i < si;i++) {
        if(s[i] >= 'a' && s[i] <= 'z' && m[s[i]] == 2) {
            r.push_back(re);
            re="";
            int n = rs.find(s[i]);
            n = si-n;
            for(int j=i+1;j<n - 1;j++) {
                re += s[j];
            }
            r.push_back(re);
            re = "";
            i = n - 1;
            m.erase(s[i]);
        }
        else {
            re += s[i];
        }
    }
    r.push_back(re);

    for(int i=0;i<r.size();i++) {
        if(r[i] == "") continue;
        cout << r[i] << "\n";
    }

    vector<string> fin;
    for(int i=0;i<r.size();i++) {
        re ="";
        if(r[i] == "") continue;
        bool rule_on = false, upstart=false, find_c = false;
        char now = '?';
        cout << r[i] << "\n";
        for(int j=0;j<r[i].size();j++) {
            if(!rule_on && r[i][j] >= 'a' && r[i][j] <= 'z') { //규칙이 시작되지 않았는데 소문자이면은
               return "invalid";
            }
            else if(j==0) rule_on = true;
            if(r[i][j] >= 'A' && r[i][j] <= 'Z') {
                cout << "in : " <<r[i][j] << " now : " << now  << " ";
                if(rule_on) {
                   re += r[i][j];
                   if(now != '?' && m[now] <= 0) {
                       m.erase(now);
                       rule_on = false;
                       find_c = false;
                       now = '?';
                       cout << "1\n";
                   }
                   cout << "3\n";
               }
               else if(!find_c && !rule_on) { // 규칙 문자가 없는데 대문자가 왔다면
                    string t = " ";
                    t += r[i][j];
                   re += t;
                   rule_on = true;
                   now = '?';
                   cout << "2\n";
               }
           }
           else  {
               if(!find_c) find_c = true;
               now = r[i][j];
               m[now]--;
               cout << now << " " << r[i][j] << "\n";
           }
           cout << re << "\n";
       }
       cout << "final : " << re <<"/"<< "\n";
       r[i] = re;
      // re = "";
    }
    vector<string> real_ans;
    cout << "r[i] \n";
     for(int i=0;i<r.size();i++) {
         cout << r[i] << "\n";
        if(r[i] == "") continue;
        real_ans.push_back(r[i]);
    }
    cout << real_ans.size() << "\n";
    for(int i=0;i<real_ans.size();i++) {
        answer += real_ans[i];
        if(i < real_ans.size() - 1) answer += " ";
    }
       // cout << r[i] << "\n";
    cout << answer<<"//\n";
    return answer;
}

int main()
{
  /*  cout << solution("aHbEbLbLbOacWdOdRdLdDc");
    cout << "\n\n\n";
    cout << solution("HaEaLaLObWORLDb");
    cout << "\n\n\n";
    cout << solution("AxAxAxAoBoBoB");
    cout << "\n\n\n";
    cout << solution("SpIpGpOpNpGJqOqA");
    cout << "\n\n\n";
    cout << solution("abHELLObaWORLD");*/
    solution("AbAaAbAaC");

  /*  테스트 1
입력값 〉 "HaEaLaLaObWORLDb"
기댓값 〉 "HELLO WORLD"

테스트 2
입력값 〉 "SpIpGpOpNpGJqOqA"
기댓값 〉 "SIGONG JOA" 또는 "SIGONG J O A"

테스트 3
입력값 〉 "AxAxAxAoBoBoB"
기댓값 〉 "invalid"

테스트 4
입력값 〉 "aIaAM"
기댓값 〉 "I AM"

테스트 5
입력값 〉 "AAAaBaAbBBBBbCcBdBdBdBcCeBfBeGgGGjGjGRvRvRvRvRvR"
기댓값 〉 "AAA B A BBBB C BBBB C BB GG G G G RRRRRR" 또는 "AA ABA BBBB C BBBB C BB GG GGG RRRRRR"

테스트 6
입력값 〉 "aaA"
기댓값 〉 "invalid"

테스트 7
입력값 〉 "Aaa"
기댓값 〉 "invalid"

테스트 8
입력값 〉 "HaEaLaLaOWaOaRaLaD"
기댓값 〉 "invalid"

테스트 9
입력값 〉 "aHELLOWORLDa"
기댓값 〉 "HELLOWORLD"

테스트 10
입력값 〉 "HaEaLaLObWORLDb"
기댓값 〉 "HELL O WORLD"

테스트 11
입력값 〉 "HaEaLaLaObWORLDb"
기댓값 〉 "HELLO WORLD"

테스트 12
입력값 〉 "aHbEbLbLbOacWdOdRdLdDc"
기댓값 〉 "HELLO WORLD"

테스트 13
입력값 〉 "abAba"
기댓값 〉 "invalid"

테스트 14
입력값 〉 "HELLO WORLD"
기댓값 〉 "invalid"

테스트 15
입력값 〉 "xAaAbAaAx"
기댓값 〉 "invalid"

테스트 16
입력값 〉 "AbAaAbAaCa"
기댓값 〉 "invalid"

테스트 17
입력값 〉 "AbAaAbAaC"
기댓값 〉 "invalid" */
}