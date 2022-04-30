#include <string>
#include <vector>
#include <iostream>

using namespace std;

int MN;
int start, e;
int count_key;
vector<vector<int>> map;

void rotate(vector<vector<int>> &key) {
    int arr[21][21];
    int n = key.size();
    for(int i=0;i<key.size();i++) 
        for(int j=0;j<key.size();j++) 
            arr[i][j] = key[n-1-j][i];
    
    for(int i=0;i<key.size();i++)
        for(int j=0;j<key.size();j++)
            key[i][j] = arr[i][j];
}

bool check_unlock(vector<vector<int>> key, vector<vector<int>> lock, int idx, int jdx) {
    if(jdx > e) {
        return check_unlock(key,lock,idx+1, 0);
    }

    if(idx > e) return false;

    int s = key.size();
    int y = 0;
    int cnt = 0;

    for(int i=idx; i<idx+s;i++) {
        int x =0;
        for(int j=jdx;j<jdx+s;j++) {
            if(i < start || i > e || j < start || j > e) {
                x++;
                continue;
            }
            if(key[y][x] == 1 && map[i][j] == 1){
                return check_unlock(key,lock,idx,jdx+1);
            }

            if(key[y][x] == 1 && map[i][j] ==0) cnt++;
            x++;
        }
        y++;
    }

    if(cnt == count_key) return true;
    return check_unlock(key,lock,idx,jdx+1);;
}

bool find_unlock(vector<vector<int>> key, vector<vector<int>> lock) {

    for(int i=0;i<4;i++) {
        if(check_unlock(key,lock,0,0)) return true;
        rotate(key);
    }

    return false;
}

void ck(vector<vector<int>> lock) {
    for(int i=0;i<lock.size();i++) {
        for(int j=0;j<lock.size();j++) {
            if(lock[i][j] == 0)
                count_key++;
        }
    }
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    MN = key.size() * 2 - 2 + lock.size();
    vector<vector<int>> m(MN, vector<int>(MN,0));
    map = m;
    int s = key.size()-1 + lock.size();
    int k = key.size() - 1;
    start = k, e = s - 1;

    ck(lock);
    for(int i=k;i < s;i++)
        for(int j =k;j < s;j++) 
            map[i][j] = lock[i-k][j-k];

    answer = find_unlock(key, lock);
    return answer;
}