#include<bits/stdc++.h>
using namespace std;

int a, b, A, B, C, cost;
int cnt[101];

int main(){
	
	cin >> A >> B >> C;
	for(int i = 0; i < 3; i++){
		cin >> a >> b;
		for(int j = a; j < b; j++) cnt[j]++;
	}
	for(int i = 0; i < 100; i++){
		if(cnt[i]){
			if(cnt[i] == 1 )cost += A;
			else if(cnt[i] == 2) cost += 2*B;
			else if(cnt[i] == 3) cost += 3*C;
		}
	}
	cout << cost;
}
