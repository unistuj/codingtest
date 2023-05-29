#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<tuple>
#include<vector>
using namespace std;

int a[102][102], n, l, r, visited[102][102];
int sum, flag, cnt;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void bfs(int y, int x){
	if(visited[y][x] == 1)return;
	vector<pair<int, int>> v;
	v.push_back({y, x});
	sum += a[y][x];
	visited[y][x] = 1;
	queue<pair<int, int>> q;
	q.push({y, x});
	while(q.size()){
		tie(y, x) = q.front(); q.pop();
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
			if(visited[ny][nx] == 1)continue;
			int bi = abs(a[y][x] - a[ny][nx]);
			if(bi < l || bi > r)continue;
			flag = 1;
			visited[ny][nx] = 1;
			v.push_back({ny, nx});
			q.push({ny, nx});
			sum += a[ny][nx];
		}
	}
	sum = sum / v.size();
	for(auto k : v){
		a[k.first][k.second] = sum;
	}
}

int main(){
	cin >> n >> l >> r;
	for(int i = 0; i < n; i ++){
		for(int j = 0; i < n; j++){
			cin >> a[i][j];
		}
	}
	
	flag = 1;
	while(flag){
		flag = 0;
		cnt ++;
		memset(visited, 0, sizeof(visited));
		for(int i = 0; i < n; i++){
			for(int j = 0; i < n; j++){
				bfs(i, j);
			}
		}
	}
	cout << cnt-1;
}
	
	
