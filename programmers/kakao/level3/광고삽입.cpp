#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int arr[360000];

int strToSec(string t) {
    int h = stoi(t.substr(0,2)) * 3600;
    int m = stoi(t.substr(3,2)) * 60;
    int s = stoi(t.substr(6));
    
    return h + m + s;
}

string secToStr(int s) {
    string h = to_string(s / 60 / 60);
    s = s % 60 % 60;
    string m = to_string(s / 60);
    s = s % 60;
    string se = to_string(s);
    return h + ":" + m + ":" + se;
}
string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    if(play_time == adv_time) return "00:00:00";
    for(int i=0;i<logs.size();i++) {
        int start = strToSec(logs[i].substr(0,8));
        int end = strToSec(logs[i].substr(9));
        for(int i=start;i<end;i++) arr[i]++;
    }
    
    int play = strToSec(play_time);
    int adv = strToSec(adv_time);
    
    queue<int> q;
    int max_ad=0;
    int sum = 0;
    for(int i=0;i<adv;i++) {
        sum += arr[i];
        q.push(arr[i]);
    }
    max_ad = sum;
    int lo = 0;
    for(int i=adv;i<=play;i++) {
        sum += arr[i];
        q.push(arr[i]);
        sum -= q.front();
        q.pop();
        if(sum > max_ad) {
            max_ad = sum;
            lo = i - adv+1;
        }
    }

    return secToStr(lo);
}
int main() {
    cout << solution("02:03:55","00:14:15",{"01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30"});
}