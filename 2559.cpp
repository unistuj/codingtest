#include<bits/stdc++.h>

using namespace std;

int t[100001];
int ret = -100000;
int n;
int k;
int temp;
int cnt;

int main(){
	cin >> n >> k ;
	for(int i = 1; i <= n; i++){
		cin >> temp;
		t[i] = t[i - 1] + temp;
	}
	
	for(int j = 0 ; j <= n - k ; j++){
		ret = max(ret, t[j + k] - t[j]);
	}
	
	cout << ret;
	
	return 0;
}
