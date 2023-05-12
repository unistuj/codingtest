#include<bits/stdc++.h>
using namespace std;

int n;
int a[66][66];

void ap(int y, int x, int m){
	int cnt = 0;
	for(int i = y; i < (y + m); i ++) {
		for(int j = x ; j < (x + m); j++){
			if(a[i][j] == 1)cnt++;
		}
	}
	if(cnt == (m *m)){
		printf("1");
		return;
	}
	if(!cnt){
		printf("0");
		return;	
	}
	m = m / 2;
	printf("(");
	for(int k = 0; k < 2; k++){
		for(int l = 0; l < 2; l++){
			int ny = y + m *k;
			int nx = x + m *l;
			ap(ny, nx, m);
		}
	}
	printf(")");
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%1d", &a[i][j]);
		}
	}
	ap(0, 0, n);
}
