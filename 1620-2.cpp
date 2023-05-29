#include <bits/stdc++.h>
using namespace std;

int n, k;
map<string, int> mp1;
string temp;
string a[100002];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> temp;
		mp1[temp] = i;
		a[i] = temp;
	}
	
	for(int j = 0; j < k; j++){
		cin >> temp;
		if(atoi(temp.c_str()) == 0){
			cout << mp1[temp] << '\n';
		}else{
			cout << a[ atoi(temp.c_str()) ] << '\n';
		}
	}	
}
