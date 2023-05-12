#include<bits/stdc++.h>
using namespace std;

int a[102][102];
int cloud[102][102];
vector<pair<int, int>> v;
int h, w;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> h >> w;
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			char b;
			cin >> b;
			if(b == '.')cloud[i][j] = 0;
			if(b == 'c'){
				cloud[i][j] = 1;
				v.push_back(make_pair(i, j));
			}
			a[i][j] = -1;
		}
	}
	for(auto k : v){
		int count = 1;
		for(int l = k.second; l < w; l++){
			if(cloud[k.first][l + 1] != 1){
				a[k.first][l] += count;
				count++;
			}else{
				a[k.first][l] += count;
				break;
			}
		}
	}
	
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			cout << a[i][j];
		}
		cout<<"\n";
	}
	
}
