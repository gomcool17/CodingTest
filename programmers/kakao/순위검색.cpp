#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, vector<int>> scores;

void addCase(string* s, int score) {
    for(int i=0;i<16;i++) {
        string str = "";
        int a = i;
        for(int j=3;j>=0;j--) {
            if(a == 0 || a%2 ==0) str = "-" + str;
            else str = s[j] + str;
            a /= 2;
        }
        cout << str << "\n";
        scores[str].push_back(score);
    }
    cout << "\n";
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    for(int i=0;i<info.size();i++) {
        istringstream stt(info[i]);
        string s[4], score="";
        int n;
        stt >> s[0] >> s[1] >> s[2] >> s[3] >> score;
        n = stoi(score);
        addCase(s, n);
    }
    
    for(auto it=scores.begin();it != scores.end(); it++) 
        sort(it->second.begin(),it->second.end());

    for(int i=0;i<query.size();i++) {
        istringstream stt(query[i]);
        string s[4], score="";
        stt >> s[0] >> score >> s[1] >> score >> s[2] >> score>>s[3] >> score;
       // string str = s[0] + s[1] + s[2] + s[3];
        vector<int> v = scores[ s[0] + s[1] + s[2] + s[3]];
        int n = stoi(score);
        if(v.size() != 0) {
            auto it = lower_bound(v.begin(), v.end(),n);
            int ans = v.size() - (it - v.begin());
            answer.push_back(ans);
        }
        else answer.push_back(0);
    }
    return answer;
}

int main()
{
    vector<string> info = {"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"};
    vector<string> query = {"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"};

    solution(info, query);
}