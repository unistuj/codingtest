#include<bits/stdc++.h>
using namespace std;
vector<int> v(26);
string x;
char l;
int k = 0;
int m = 'a';

int main(){
	cin >> x;
	for(int i = 0; i < x.length(); i++){
		l = x[i];
		k = int(l) - m;
		v[k] += 1;
	}
	for(int j = 0; j < 26; j++){
		cout << v[j] << ' ';
	}
}
