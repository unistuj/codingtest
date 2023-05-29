#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> land;
vector<vector<int>> landList;
int water[52][52];
int a, b, ans;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void combi(int start, vector<int> v){
	if(v.size() == 2){
		landList.push_back(v);
		return;
	}
	for(int i = start + 1; i < land.size(); i ++){
		v.push_back(i);
		combi(i, v);
		v.pop_back();
	}
}

void bfs(int x, int y, int xx, int yy, int cnt, int visited[52][52]){
	visited[y][x] = 1;
	if(x == xx && y == yy){
		return;
	}
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx < 0 || ny < 0 || nx >= a || ny >= b)continue;
		if(visited[ny][nx] == 1)continue;
		if(water[ny][nx] == 1)continue;
		cnt++;
		bfs(nx, ny, xx, yy, cnt, visited);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> a >> b;
	for(int i = 0; i < a; i++){
		for(int j = 0; j < b; j++){
			char temp;
			cin >> temp;
			if(temp == 'L'){
				land.push_back({i, j});
			}
			if(temp == 'W'){
				water[i][j] = 1;
			}
		}
	}
	
	vector<int> v;
	combi(-1, v);
	
	for(vector<int> vv : landList){
		int visited[52][52];
		int f = vv[0];
		int l = vv[1];
		int cnt = 0;
		bfs(land[f].second, land[f].first, land[l].second, land[l].first, cnt, visited);
		ans = max(ans, cnt);
	}
	
	cout << ans;
}
