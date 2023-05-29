#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int sx, sy, ans, r, c, dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1}, y, x, ny, nx;
char a[1001][1001];
int m[1001][1001], b[1001][1001];
bool in(int a, int b){
	return 0 <= a && a < r && 0 <= b && b < c;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>> r>> c;
	queue<pair<int, int>> qq;
	fill(&b[0][0], &b[0][0] + 1001 * 1001, INF);
	for(int i = 0; i< r; i++){
		for(int l = 0; l < c; l++){
			cin >> a[i][l];
			if(a[i][l] == 'J'){
				sy = i; sx = l;
			}
			else if(a[i][l] == 'F'){
				qq.push({i, l});
				b[i][l] = 1;
			}
		}
	}
	while(qq.size()){
		tie(y, x) = qq.front(); qq.pop();
		for(int i = 0; i < 4; i++){
			nx = x + dx[i];
			ny = y + dy[i];
			if(!in(ny, nx))continue;
			if(a[ny][nx] == '#' || b[ny][nx] != INF)continue;
			b[ny][nx] = b[y][x] + 1;
			qq.push({ny, nx});
		}
	}	
	m[sy][sx] = 1;
	qq.push({sy, sx});
	while(qq.size()){
		tie(y, x) = qq.front(); qq.pop();
		if(y == r-1 || y == 0 || x == c-1 || x == 0){
				ans =  m[y][x];
				break;
			}
		for(int i = 0; i < 4; i++){
			nx = x + dx[i];
			ny = y + dy[i];
			if(!in(ny, nx))continue;
			if(a[ny][nx] == '#' || m[ny][nx])continue;
			if(b[ny][nx] <= m[y][x] + 1)continue;
			m[ny][nx] = m[y][x] + 1;
			qq.push({ny, nx});
		}
	}
	if(ans != 0){
		cout << ans;
	}else {
		cout << "IMPOSSIBLE";
	}
	
}
