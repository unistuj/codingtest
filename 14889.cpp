#include<iostream>
#include<algorithm>
#include<cmath>
#include<memory.h>
#include<vector>

using namespace std;

int a[22][22];
int n;
vector<int> v;
int sum;
int ch;
int teamSum;
int another;
int vi;
int ans = 987654321;

void cmp(int x, int info[]){
	if(v.size() == n/2){
		vector<int>temp;
		for(int i = 0; i < n; i++)temp.push_back(i);
		teamSum = 0;
		another = 0;
			
		for(int k = 0; k < v.size(); k++){
			for(int l = 0; l < v.size(); l++){
				teamSum += a[v[k]][v[l]];
			}
		}
		
		for(int k = 0; k < n; k++){
			if(info[k] == 1)continue;
			for(int l = 0; l < n; l++){
				if(info[l] == 1)continue;
				another += a[k][l];
			}
		}
		
		vi = abs(teamSum - another);
		if(vi == 0){
			ans = 0;
			return;
		}

		ans = min(ans, vi);
		return;
	}
	
	for(int i = x; i < n; i++){
		v.push_back(i);
		info[i] = 1;
		cmp(i+1, info);
		info[i] = 0;
		v.pop_back();
	}
}


int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
			sum += a[i][j];
			ch = sum % 2;
		}
	}
	
	int info[n] = {0,};
	
	cmp(0, info);
	
	cout <<ans;
	
}
