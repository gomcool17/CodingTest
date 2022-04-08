#include <iostream>
#include <vector>

using namespace std;

bool map[102][102];

struct DIR{
  int y,x;
};

DIR dir[4] = {{0,1},{-1,0},{0,-1},{1,0}};
vector<int> v;
int re = 0;

void result()
{
  for(int i=0;i<101;i++) {
    for(int j=0;j<101;j++) {
      if(map[i][j] && map[i][j+1] && map[i+1][j] && map[i+1][j+1])
        re++;
    }
  }
}

void dragon(int d, int y, int x, int cnt) 
{
  //cout << "\n";
  if(cnt > d)
    return;
  int s = v.size() - 1;

  for(int i = s; i>=0; i--) {
    int n = (v[i] + 1) % 4;
    v.push_back(n);
    y += dir[n].y; x += dir[n].x;
    map[y][x] = true;
  }
  
  dragon(d,y,x,cnt+1);
  return;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N; cin >> N;
  for(int i=0;i<N;i++) {
      int x,y,d,g; cin >> x >> y >> g >> d;
      map[y][x] = true;
      v.push_back(g);
      y += dir[g].y;
      x += dir[g].x; // 선 긋고
      map[y][x] = true;
      
      if(d == 0)
        continue;
      
      dragon(d,y,x,1);
      v.clear();
  }
  
  result();
  cout << re <<"\n";
}