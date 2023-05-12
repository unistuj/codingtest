#include <bits/stdc++.h>
using namespace std;

int a[9];
int answer[7];
int sum = 0;

int main(){
	for(int i = 0; i < 9; i++){
		cin >> a[i];
	}
	sort(a, a+9);
	do{
		for(int j = 0; j <7; j++){
			sum += a[j];
		}
		if(sum == 100){
			break;
		} else{
			sum = 0;
		}
	}while(next_permutation(a, a+9));
	
	for(int j = 0; j <7; j++){
		cout << a[j] << '\n';
	}
	
}
