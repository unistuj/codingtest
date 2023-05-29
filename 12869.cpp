#include<bits/stdc++.h>
using namespace std;
int n, d, e, f;
int g[6][3] = {
	{1, 3, 9},
	{1, 9, 3},
	{3, 9, 1},
	{3, 1, 9},
	{9, 3, 1},
	{9, 1, 3}
	};
int m[64][64][64], visited[64][64][64], o[3];
int ans = 987654321;

struct A{
	int a, b, c;
}; 

queue<A> q;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++) cin >> o[i]; 
	q.push({o[0], o[1], o[2]});
	visited[o[0]][o[1]][o[2]] = 1;
	
	while(q.size()){
		if(visited[0][0][0])break;
		d = q.front().a;
		e = q.front().b;
		f = q.front().c;
		q.pop();
		for(int i = 0; i < 6; i++){
			int na = max(0, d - g[i][0]);
			int nb = max(0, e - g[i][1]);
			int nc = max(0, f - g[i][2]);
			if(visited[na][nb][nc])continue;
			q.push({na, nb, nc});
			visited[na][nb][nc] = visited[d][e][f] + 1;
		}
	}
	
	
	
	cout << visited[0][0][0]-1;
	
	
}
