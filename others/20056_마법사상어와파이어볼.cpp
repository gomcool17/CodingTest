#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M,K;

struct INFO {
    int y,x;
    int m,s,d;
};

struct DIR {
    int y,x;
};


bool cmp(INFO a, INFO b) {
    if(a.y == b.y)
        return a.x < b.x;
    return a.y < b.y;
}
DIR dir[8] = {{-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1},{-1,-1}};
vector<INFO> info;
int cnt[51][51];

int main()
{
    cin >> N>>M>>K;
    for(int i=0;i<M;i++) {
        int y,x,m,s,d; cin >> y>>x>>m>>s>>d;
        y-=1; x-=1;
        info.push_back({y,x,m,s,d});
    }

    while(K--) {
        for(int i=0;i<info.size();i++) {
            int y = info[i].y + dir[info[i].d].y * info[i].s;
            int x = info[i].x + dir[info[i].d].x * info[i].s;
            while(y < 0) {
                y += N;
            }
            while(x < 0){
                x += N;
            }
            y = y % N; x = x % N;
            info[i].y = y; info[i].x= x;      
            cnt[y][x]++;  
        }

        sort(info.begin(), info.end(), cmp);
       
        vector<INFO> tmp;
        for(int i=0;i<info.size();) {
            int n;
            int y = info[i].y, x = info[i].x;
            
            if(cnt[y][x] > 1) {
                int sm =0 , ss=0;
                int c = cnt[y][x];
                int odd = 0;
                while(cnt[y][x]--) {
                    sm += info[i].m;
                    ss += info[i].s;
                    if(info[i].d % 2 != 0)
                        odd++;
                    i++;
                }
                cnt[y][x] = 0;
                sm /= 5; ss /= c;
              
                if(sm == 0) {
                    continue;
                }

                if(odd == c || odd == 0) {
                    tmp.push_back({y,x,sm,ss,0});
                    tmp.push_back({y,x,sm,ss,2});
                    tmp.push_back({y,x,sm,ss,4});
                    tmp.push_back({y,x,sm,ss,6});
                }
                else {
                    tmp.push_back({y,x,sm,ss,1});
                    tmp.push_back({y,x,sm,ss,3});
                    tmp.push_back({y,x,sm,ss,5});
                    tmp.push_back({y,x,sm,ss,7});
                }
            }
            else if(cnt[y][x] == 1){
                tmp.push_back({y,x,info[i].m, info[i].s, info[i].d});
                cnt[y][x]--;
                i++;
            }
        }

        info.clear();
        
        info = tmp;
    }

    int re = 0;

    for(int i=0;i<info.size();i++) {
        re += info[i].m;
    }

    cout << re << "\n";
}