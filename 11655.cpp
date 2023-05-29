#include <bits/stdc++.h>
using namespace std;

string s;

int main(){
	getline(cin, s);
	for(int i = 0; i < s.length(); i++){
		if(isupper(s[i])){
			s[i] -= 'A';
			s[i] += 13;
			s[i] = s[i]%26;
			s[i] = s[i] + 'A';
		}else if(islower(s[i])){
			s[i] -= 'a';
			s[i] += 13;
			s[i] = s[i]%26;
			s[i] = s[i] + 'a';
		} else{
			continue;
		}
	}
	cout << s;
}
