#include<bits/stdc++.h>
using namespace std;

string f;
vector<char> v1;
vector<char> v2;
int a;

int main(){
	cin >> f;
	for(int i = 0; i < f.length(); i++){
		v1.push_back(f[i]);
	}
	
	for(int i = 0; i < v1.size(); i++){
		v2.push_back(v1[i]);
	}
	
	reverse(v2.begin(), v2.end());
	
	cout << (v1 == v2);
}
