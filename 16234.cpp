#include<iostream>
#include<tuple>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<memory.h>
using namespace std;

int visited[102][102], a[102][102], n, l, r, sum;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int day, flag, temp;

void bfs(int y, int x){
	sum = 0;
	vector<pair<int, int>> v;
	visited[y][x] = 1;
	int cnt = 1;
	sum += a[y][x];
	queue<pair<int, int>> q;
	v.push_back({y, x});
	q.push({y, x});
	while(q.size()){
		tie(y,x) = q.front(); q.pop();
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx < 0 || nx >=n || ny < 0 || ny >= n)continue;
			if(visited[ny][nx] == 1)continue;
			if(abs(a[y][x] - a[ny][nx]) < l || abs(a[y][x] - a[ny][nx]) > r)continue;
			visited[ny][nx] = 1;
			flag = 1;
			sum += a[ny][nx];
			cnt++;
			v.push_back({ny, nx});
			q.push({ny, nx});
		}
	}
	sum = sum / cnt;
	for(auto k : v){
		a[k.first][k.second] = sum;
	}
}

int main(){
	cin >> n >> l >> r;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
	flag = 1;
	while(flag){
		day++;
		flag = 0;
		memset(visited, 0, sizeof(visited));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(visited[i][j] == 1)continue;
				bfs(i, j);
			}
		}
	}
	
	cout << day-1;
}
