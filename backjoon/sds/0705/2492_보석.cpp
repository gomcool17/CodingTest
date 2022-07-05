#include <iostream>
#include <vector>
#define x first
#define y second
using namespace std;

typedef pair<int, int> p;

int n, m, t, k;
vector<p> v;

int f(int x, int y){
	int ret = 0;
	for(auto i : v){
		if(x <= i.x && i.x <= x + k && y <= i.y && i.y <= y+k) ret++;
	}
	return ret;
}

int main(){
	cin >> n >> m >> t >> k; v.resize(t);
	for(auto &i : v) cin >> i.x >> i.y;

	int mx = 0;
	int x, y;
	for(int i=0; i<t; i++){
		for(int j=0; j<t; j++){
			int xx, yy;
			if(v[i].x+k > n) xx = n - k;
			else xx = v[i].x;
			if(v[j].y+k > m) yy = m - k;
			else yy = v[j].y;
			int now = f(xx, yy);
			if(mx < now){
				mx = now;
				x = xx, y = yy+k;
			}
		}
	}

	cout << x << " " << y << "\n";
	cout << mx;
}