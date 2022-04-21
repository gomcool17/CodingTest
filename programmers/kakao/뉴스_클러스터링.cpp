#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<string> unions,intersection;
bool check[1000];
void find_set(string str, vector<string> &ss) {

    for(int i=0;i<str.size() - 1; i++) {
        string s = "";
        if(str[i] >= 'A' && str[i] <= 'Z' && str[i+1] >= 'A' && str[i+1] <= 'Z') {
            s = s + str[i] + str[i+1];
            ss.push_back(s);
        }
    }
}

int solution(string str1, string str2) {
    vector<string> s1, s2;
    int answer = 0;
    string s = "";
    for(int i=0;i<str1.size();i++) {
        if(str1[i] >= 'a' && str1[i] <= 'z') {
            str1[i] -= 'a' - 'A'; 
        }
    }

    for(int i=0;i<str2.size();i++) {
        if(str2[i] >= 'a' && str2[i] <= 'z') {
            str2[i] -= 'a' - 'A'; 
        }
    }

    find_set(str1, s1); find_set(str2, s2);

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    for(int i=0;i<s1.size();i++) {
        string is = s1[i];
        for(int j=0;j<s2.size();j++) {
            
        }
    }

    int r = 0, l = 0;
    
    while(1) {
        if(r >= s1.size() || l >= s2.size()){
            if(r == s1.size() && l == s2.size())
                break;
            if(r >= s1.size()) {
                unions.push_back(s2[l]);
                l++;
            }
            else {
                unions.push_back(s1[r]);
                r++;
            }
           
            continue;
        }
        
        if(s1[r] < s2[l]) {
            unions.push_back(s1[r]); r++;
        }
        else if(s1[r] > s2[l]) {
            unions.push_back(s2[l]);  l++;
        }
        else {
            intersection.push_back(s1[r]);
            unions.push_back(s1[r]);
            r++; l++;
        }
    }
    double d  = (double)intersection.size() / unions.size();
   if(s1.size() == 0 && s2.size() == 0)
       answer = 65536;
    else
        answer =d * 65536;
    return answer;
}