#include<bits/stdc++.h>
using namespace std;

const int n_max = 102;
int a[n_max][n_max], visited[n_max][n_max];
int n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int y, x;

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%1d", &a[i][j]);
		}
	}
	
	visited[0][0] = 1;
	queue<pair<int, int>> q;
	q.push({0,0});
	while(q.size()){
		tie(y, x) = q.front();
		q.pop();
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(ny >= n|| nx >= m|| nx < 0 || ny < 0 || a[ny][nx] == 0)continue;
			if(visited[ny][nx])continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ny, nx});
		}
	}
	printf("%d", visited[n-1][m-1]);
	return 0;
}
