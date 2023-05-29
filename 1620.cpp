#include<bits/stdc++.h>
using namespace std;

string v[100001];
int n, k;
string temp;
int l = -1;

int main(){
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> temp;
		v[i] = temp;
	}
	
	for(int j = 0; j < k; j++){
		cin >> temp;
		if(atoi(temp.c_str()) == 0){
			while(temp != v[l]){
				l++;
				if(temp == v[l]){
					cout << l + 1 << '\n';
				}
			}
		}else{
			cout << v[atoi(temp.c_str()) - 1] << '\n';
		}
		l = 0;
	}
}
