#include<iostream>
#include<algorithm>
#include<cmath>
#include<memory.h>
#include<vector>
using namespace std;

int f[22][22], n;
int l[22][22];
int jong[22][22];
vector<int> v;
int mx = -123;
int ga, se;
int flag = 0;
int no;

void up(){
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n; j++){
			if(f[i][j] == 0)continue;
			for(int e = i + 1; e < n; e++){
				if(f[e][j] == 0)continue;
				if(f[i][j] == f[e][j]){
					f[i][j] += f[e][j];
					f[e][j] = 0;
					e = n;
				}else{
					e = n;
				}
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		no = 0;
		for(int j = 0; j < n; j++){
			if(f[j][i] != 0){
				l[no][i] = f[j][i];
				no++;
			}
		}
	}
}

void down(){
	for(int i = n - 1; i > 0; i--){
		for(int j = 0; j < n; j++){
			if(f[i][j] == 0)continue;
			for(int e = i - 1; e > -1; e--){
				if(f[e][j] == 0)continue;
				if(f[i][j] == f[e][j]){
					f[i][j] += f[e][j];
					f[e][j] = 0;
					e = -1;
				}else{
					e = -1;
				}
			}

		}
		
	}
	
	for(int i = 0; i < n; i++){
		no = n-1;
		for(int j = n - 1; j > -1; j--){
			if(f[j][i] != 0){
				l[no][i] = f[j][i];
				no--;
			}
		}
	}
}

void left(){
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n; j++){
			if(f[j][i] == 0)continue;
			for(int e = i + 1; e < n; e++){
				if(f[j][e] == 0)continue;
				if(f[j][i] == f[j][e]){
					f[j][i] += f[j][e];
					f[j][e] = 0;
					e = n;
				}else{
					e = n;
				}
			}

		}
		
	}
	
	for(int i = 0; i < n; i++){
		no = 0;
		for(int j = 0; j < n ; j++){
			if(f[i][j] != 0){
				l[i][no] = f[i][j];
				no++;
			}
			
		}
	}
}

void right(){
	for(int i = n -1; i > 0; i--){
		for(int j = 0; j < n; j++){
			if(f[j][i] == 0)continue;
			for(int e = i-1; e > -1; e--){
				if(f[j][e] == 0)continue;
				if(f[j][i] == f[j][e]){
					f[j][i] += f[j][e];
					f[j][e] = 0;
					e = -1;
				}else{
					e = -1;
				}
			}
		}
		
	}
	
	for(int i = 0; i < n; i++){
		no = n-1;
		for(int j = n-1; j > -1 ; j--){
			if(f[i][j] != 0){
				l[i][no] = f[i][j];
				no--;
			}
			
		}
	}
}


void combi(){
	if(v.size() == 5){
		for(int q = 0; q < n; q++){
			for(int w = 0; w < n; w++){
				f[q][w] = jong[q][w];
			}
		}
		
		for(int k : v){
			if(k == 0)up();
			else if(k == 1)down();
			else if(k == 2)left();
			else if(k == 3)right();
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					f[i][j] = l[i][j];
				}
			}
			memset(l, 0, sizeof(l));
			
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				mx = max(mx, f[i][j]);
			}
		}
		
		return;
	}
	
	for(int i = 0 ; i < 4; i++){
		v.push_back(i);
		combi();
		v.pop_back();
	}
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> jong[i][j];
		}
	}
	
	combi();
	
	cout << mx;
}
