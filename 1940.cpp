#include<bits/stdc++.h>
using namespace std;

int n, m, cnt, a[20000];

int main(){
	cin >> n;
	cin >> m;
	for(int i = 0; i < n; i++){
		int c;
		cin >> c;
		a[i] = c;
	}
	sort(a, a+n);
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			if(a[i] + a[j] == m)cnt++;
		}
	}
	
		cout << cnt;
}
