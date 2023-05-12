#include<bits/stdc++.h>
using namespace std;

int land[102][102];
int visited[102][102];
int n, ret;
int ans = 0;
int ma = 0;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void bfs(int y, int x, int m){
	visited[y][x] = 1;
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(ny < 0 || nx < 0 || nx >= n || ny >= n )continue;
		if(land[ny][nx] > m  && visited[ny][nx] != 1){
			bfs(ny, nx, m);		
		}
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &land[i][j]);
			if(ma < land[i][j])ma = land[i][j];
		}
	}

	while(--ma){
		for(int u = 0; u < n; u++){
			for(int l = 0; l < n; l++){
				if(land[u][l] > ma && visited[u][l] != 1){
					bfs(u, l, ma);
					ret++;
				}
			}
		}
		if(ans < ret)ans = ret;
		ret = 0;
		fill(&visited[0][0], &visited[0][0] + 102*102, 0);
	}
	printf("%d", ans);
}
