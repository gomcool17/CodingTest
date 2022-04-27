#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <regex>
using namespace std;

vector<string> split(string str, char Delimiter) {
    istringstream iss(str);         
    vector<string> result;
    string buffer;
 
    while (getline(iss, buffer, Delimiter)) {
        result.push_back(buffer);              
    }
 
    return result;
}
string solution(string m, vector<string> musicinfos) {
    string answer = "";
    string save = m;
    int re = 0, relo = 0;
    vector<string> results;
    m = regex_replace(m, regex("C#"),"c");
    m = regex_replace(m, regex("D#"),"d");
    m = regex_replace(m, regex("F#"),"f");
    m = regex_replace(m, regex("G#"),"g");
    m = regex_replace(m, regex("A#"),"a");
    m = regex_replace(m, regex("B#"),"b");
    m = regex_replace(m, regex("E#"),"e");
    for(int i=0;i<musicinfos.size();i++) {
        vector<string> v = split(musicinfos[i], ',');
        vector<string> start = split(v[0], ':');
        vector<string> end = split(v[1], ':');
     
        int start_h = stoi(start[0]), start_m = stoi(start[1]);
        int end_h = stoi(end[0]), end_m = stoi(end[1]);
        int t = (end_h * 60 + end_m) - (start_h*60 +start_m);
        v[3] = regex_replace(v[3], regex("C#"),"c");
        v[3] = regex_replace(v[3], regex("D#"),"d");
        v[3] = regex_replace(v[3], regex("F#"),"f");
        v[3] = regex_replace(v[3], regex("G#"),"g");
        v[3] = regex_replace(v[3], regex("A#"),"a");
        v[3] = regex_replace(v[3], regex("B#"),"b");
        v[3] = regex_replace(v[3], regex("E#"),"e");
    
        v[3] = v[3].substr(0, t);
        int s = v[3].size();
        int j = 0;
        while(t > s) {
            v[3] += v[3][j];
            j++, s++;
        }
     
        if(v[3].find(m) != string::npos) {
            results.push_back(v[2]);
            if(re < t) {
                re = t;
                relo = results.size() - 1;
            }
        }
    }
    if(results.size() == 0) answer ="(None)";
    else answer = results[relo];
    return answer;
}