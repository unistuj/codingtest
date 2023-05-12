#include<bits/stdc++.h>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int visited[52][52];
int t, n, m, k;
int cnt, bo;


int main(){
	scanf(" %d", &t);
	while(t--){
		cnt = 0;
		scanf("%d %d %d", &m, &n, &k);
		cnt = k;
		fill(&visited[0][0], &visited[51][51], 0);
		for(int j = 0; j < k; j++){
			int g, s;
			scanf("%d %d", &g, &s);
			visited[s][g] = 1;
			for(int l = 0; l < 4; l++){
				int nx = g + dx[l];
				int ny = s + dy[l];
				if(ny >= n || nx >=m || nx <0|| ny <0|| visited[ny][nx] == 0)continue;
				bo = 1;
			}
			if(bo)cnt-=1;
			bo = 0;
		}
		printf("%d", cnt);
	}
}
