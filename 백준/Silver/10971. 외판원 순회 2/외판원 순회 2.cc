#include<bits/stdc++.h>
using namespace std;
int town[11][11];
int route = 0;
int visited[11];
int n;
int ans = 987654321;
int fir;

void gogo(int cnt, int from, int route){
	if(cnt == n){
		if(town[from][fir] == 0)return;
		ans = min(ans, route+ town[from][fir]);
		return;
	}
	for(int i = 0; i < n; i++){
		if(town[from][i] == 0)continue;
		if(visited[i] == 1)continue;
		visited[i] = 1;
		gogo(cnt+1, i, route+town[from][i]);
		visited[i] = 0;
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> town[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		visited[i] = 1;
		fir = i;
		gogo(1, i, route);
	}
	
	cout << ans;
}