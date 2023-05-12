#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> chicken;
vector<pair<int, int>> home;
vector<pair<int, int>> last;
int n, m, temp, s, cl, loute;
int ans = 987654321;

void per(int k){
		if(last.size() == m){
			s= 0;
			for(int u = 0; u < home.size(); u++){
				cl = 200;
				for(int i = 0; i < m; i++){
					loute = abs(last[i].first - home[u].first) + abs(last[i].second - home[u].second);
					cl = min(cl, loute);
				}
				s += cl;
			}
			ans = min(ans, s);
		}
		for(int i = k; i < chicken.size(); i++){
			last.push_back({chicken[i].first, chicken[i].second});
			per(k+1);
			last.pop_back();
		}
		return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j++){
			cin >> temp;
			if(temp == 1){
				home.push_back({i, j});
			}
			if(temp == 2){
				chicken.push_back({i, j});
			}
		}
	}
	per(0);
	cout << ans;
}
