#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<memory.h>

using namespace std;

int cnt, n, m;
int pan[101][101];
int visited[101][101];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };
int ch;
vector<int> v;

void checkair(int y, int x) {
	visited[y][x] = 1;
	pan[y][x] = 2;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m)continue;
		if (visited[ny][nx] == 1)continue;
		if (pan[ny][nx] == 1)continue;
		checkair(ny, nx);
	}
	
}

void erasech() {
	ch = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (pan[i][j] == 1) {
				ch++;
				for (int k = 0; k < 4; k++) {
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (pan[ny][nx] == 2) {
						pan[i][j] = 0;
						break;
					}
				}
			}
		}
	}
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> pan[i][j];
			if (pan[i][j] == 1)ch++;
		}
	}
	while(ch) {
		memset(visited, 0, 101*101*sizeof(int));
		checkair(0, 0);
		erasech();
		v.push_back(ch);
		cnt++;
	}
	
	cout << cnt-1 << "\n" << v[v.size()-2];
	
}