#include<bits/stdc++.h>
using namespace std;

int n, m, k;
int a, b, c, d;
int v, ans;
vector<int> realans;
int box[102][102];
int visited[102][102];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void bfs(int y, int x){
	visited[y][x] = 1;
	v++;
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(nx < 0 || ny < 0 || ny >= m || nx >= n)continue;
		if(box[ny][nx] != 1 && visited[ny][nx] != 1){
			bfs(ny, nx);
		}
	}
}

int main(){
	scanf("%d %d %d", &m, &n, &k);
	while(k--){
		scanf("%d %d %d %d", &a, &b, &c, &d);
		for(int i = b; i < d; i++){
			for(int j = a; j < c; j++){
				box[i][j] = 1;
			}
		}
	}
	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(box[i][j] != 1 && visited[i][j] != 1){
				ans++;
				bfs(i, j);
				realans.push_back(v);
				v = 0;
			}
		}
	}
	sort(realans.begin(), realans.end());
	printf("%d\n", ans);
	for(int r : realans){
		printf("%d ", r);
	}
}
