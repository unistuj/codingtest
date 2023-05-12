#include<bits/stdc++.h>
using namespace std;

string s, ret;
int n, cnt[26];

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> s;
		cnt[s[0] - 'a'] += 1;
		s = " ";
	}
	for(int j = 0; j < 26; j++){
		if(cnt[j] >= 5){
			ret += j + 'a';
		}
	}
	if(ret.size() == 0){
		cout << "PREDAJA";
	} else{
		cout << ret;
	}
}
