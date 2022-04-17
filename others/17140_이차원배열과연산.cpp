#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

#define MN 100

int r,c,k;
int rn=3;
int cn=3;
int board[100][100];

bool cmp(const pair<int,int>& a, const pair<int,int>& b) {
	if (a.second != b.second) return a.second < b.second;
	return a.first < b.first;
}

int main()
{
    cin >> r>>c>>k;
    int time = 0;
    r -= 1; c -= 1;

    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            cin >> board[i][j];
        }
    }

    bool flag = false;
    int cr = 52;
    while(++time) {
        //cout << rn << " " << cn << "\n";
        if(board[r][c] == k) {
            flag=true;
            break;
        }
        if(rn >= cn) {
            for(int i=0;i<rn;i++) {
                map<int, int> m;
                int cnt = 0;
                //cout << "rnrnrnr\n";
                for(int j=0;j<cn;j++) {
                    //cout << board[i][j] << "\n";
                   if(m.find(board[i][j]) != m.end())
                        m[board[i][j]]++;
                    else
                        m.insert({board[i][j], 1});
                }
                vector<pair<int,int>> v(m.begin(), m.end());
                vector<int> tmp;
                sort(v.begin(), v.end(), cmp);
               // cout << "after sort \n";
                for(int j=0;j<v.size();j++) {
                    if(v[j].first == 0) continue;
                    if(j == 50)  break;
                    tmp.push_back(v[j].first);  tmp.push_back(v[j].second);
                   // cout << v[j].first << " " << v[j].second << "\n";
                }
                memset(board[i], 0, sizeof(int) * 100);
    
                for(int j=0;j<tmp.size();j++) {
                    board[i][j] = tmp[j];
                   // cout << tmp[j] << " ";
                }
                 cn = max(cn, (int)tmp.size());
                if(cn > 100)
                    cn = 100;
            }
        }   
        else {
            for(int i=0;i<cn;i++) {
                map<int, int> m;
                int cnt = 0;
                for(int j=0;j<rn;j++) {
                    if(m.find(board[j][i]) != m.end())
                        m[board[j][i]]++;
                    else
                        m.insert({board[j][i], 1});
                }
                vector<pair<int,int>> v(m.begin(), m.end());
                vector<int> tmp;
                sort(v.begin(), v.end(), cmp);
                for(int j=0;j<v.size();j++) {
                    if(v[j].first == 0) continue;
                    if(j == 50) break;
                    tmp.push_back(v[j].first); tmp.push_back(v[j].second);
                }
                rn = max(rn, (int)tmp.size());
              // cout << "size : " << tmp.size() << "\n";
                for(int j=0;j<rn;j++) {
                    if(tmp.size() <= j) {
                        board[j][i] = 0; continue;
                    }
                    board[j][i] = tmp[j];
                   // cout << tmp[j] << " ";
                }
                if(rn > 100)
                    rn = 100;
            }
        }
       // cout << rn << " " << cn << "\n";
      /*  for(int a=0;a<rn;a++) {
            for(int b=0;b<cn;b++) {
                cout << board[a][b] << " ";
            }
            cout << "\n";
        }
        cout << "\n";*/

        if(time > 100)
            break;
    }

    if(flag)
        cout << time - 1 <<"\n";
    else 
        cout << -1 << "\n";
}