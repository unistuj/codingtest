#include<iostream>
#include<algorithm>
#include<memory.h>

using namespace std;

int r, c, t;
int room[54][54];
int afroom[54][54];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
int air, ans;

void dust(){
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			if(i == air -1 && j == 0)continue;
			if(i == air && j == 0)continue;
			int cnt = 0;
			int a= room[i][j] / 5;
			for(int k = 0; k < 4; k++){
				int ny = i + dy[k];
				int nx = j + dx[k];
				if(nx < 0 || nx >= c || ny < 0 || ny >= r)continue;
				if(nx == 0 && (ny == air-1|| ny == air))continue;
				cnt++;
				afroom[ny][nx] += a;
			}
			afroom[i][j] = afroom[i][j] + room[i][j] - (cnt * a);
		}
	}
}

void move(){
	for(int i = 0; i < r; i++){
		for(int j = 0; j< c; j++){
			room[i][j] = afroom[i][j];
		}
	}
}


void cleanup(){
	for(int h = air - 2 ; h > 0; h--){
		room[h][0] = room[h-1][0];
	}
	for(int d = 0; d < c - 1; d++){
		room[0][d] = room[0][d+1];
	}
	for(int s = 0; s < air-1; s++){
		room[s][c-1] = room[s+1][c-1];
	}
	for(int n = c-1; n > 1; n--){
		room[air-1][n] = room[air-1][n-1];
	}
	room[air-1][1] = 0;
}

void cleandown(){
	for(int h = air+1; h < r - 1; h++){
		room[h][0] = room[h+1][0];
	}
	for(int d = 0; d < c - 1; d++){
		room[r-1][d] = room[r-1][d+1];
	}
	for(int s = r-1; s > air; s--){
		room[s][c-1] = room[s-1][c-1];
	}
	for(int n = c-1; n > 1; n--){
		room[air][n] = room[air][n-1];
	}
	room[air][1] = 0;
}


int main(){
	cin >> r >> c >> t;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cin >> room[i][j];
			if(room[i][j] == -1){
				air = i;
				room[i][j] = 0;
			}
		}
	}
	
	while(t--){
		memset(afroom, 0, sizeof(afroom));
		dust();
		move();
		cleanup();
		cleandown();
	}
	
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			ans += room[i][j];
		}
	}
	
	cout << ans;
	
}
