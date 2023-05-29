#include<bits/stdc++.h>
using namespace std;

int a[52][52], visited[52][52];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int t, n, m, k, ret, l, u;

void dfs(int y, int x){
	visited[y][x] = 1;
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx >= m || ny >= n || n < 0 || m < 0)continue;
		if(a[ny][nx] == 1 && !visited[ny][nx]){
			dfs(ny, nx);
		}
	}
	return;
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while(t--){
		fill(&a[0][0], &a[0][0] + 51 * 51, 0);
		fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
		ret = 0;
		cin >> m >> n >> k;
		for(int i = 0 ; i < k ; i++){
			cin >> l >> u;
			a[u][l] = 1;
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(a[i][j] == 1 && !visited[i][j]){
					dfs(i, j);
					ret ++;
				}
			}
		}
		cout << ret << "\n";
	}
	return 0;
}
