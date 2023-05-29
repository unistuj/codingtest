#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int mo[32][12];
int n, m, h, a, b;
int dx[3] = {1, 0, -1};
int dy[3] = {1, 1, 1};
vector<pair<int, int>> v;
vector<pair<int, int>> w;
int line;
int ans, flag, temp;

void move(int y, int x, int u){
	if(v.size() >= line)return;
	if(mo[y][x] == 1){
		x++;
		y++;
		move(y, x, u);
		return;
	}
	if(mo[y][x] == -1){
		x--;
		y++;
		move(y, x, u);
		return;
	}
	if(y == h && x == u){
		flag = 1;
		w.clear();
		line = v.size();
		for(auto k : v){
			w.push_back(k);
		}
		return;
	}
	
	for(int j = 0; j < 3; j++){
		int ny = y + 1;
		int nx = x + dx[j];
		if(nx >= n || nx < 0 || ny > h)continue;
		if(j == 0){
			if(mo[ny-1][nx] == 1)continue; 
			v.push_back({ny-1, nx-1});
			move(ny, nx, u);
			v.pop_back();
			continue;
		}
		if(j == 1){
			move(ny, nx, u);
			continue;
		}
		if(j == 2){
			if(mo[ny-1][nx] == -1)continue;
			v.push_back({ny-1, nx});
			move(ny, nx, u);
			v.pop_back();
			continue;
		}
	}
}

int main(){
	cin >> n >> m >> h;
	for(int i = 0; i < m; i++){
		cin>> a >> b;
		mo[a-1][b-1] = 1;
		mo[a-1][b] = -1;
	}
	
	for(int i = 0; i < n; i++){
		line = 987654;
		flag = 0;
		move(0, i, i);
		for(auto k: w){
			mo[k.first][k.second] = 1;
			mo[k.first][k.second+1] = -1;
		}
		ans += line;
		if(ans > 3 || flag == 0){
			ans = -1;
			break;
		}
	}
	
	
	cout << ans;
}


