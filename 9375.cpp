#include<bits/stdc++.h>
using namespace std;

int testcase;
int n;
string a, b;

int main(){
	cin >> testcase;
	for(int  l = 0; l < testcase; l++){
		map<string, int> mp;
		
		cin >> n;
		
		for(int i = 0; i < n; i++){
			cin >> a >> b;
			mp[b] += 1;
		}
		
		int m = 1;
		
		for(auto k : mp){
			m *= (k.second + 1);
		}
		
		m--;
		
		cout << m << '\n';
	}
}
