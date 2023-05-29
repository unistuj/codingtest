#include<bits/stdc++.h>
using namespace std;
string s;
int n, answer;


int main(){
	cin >> n;
	answer = n;
	for(int i = 0; i < n; i++){
		cin >> s;
		int f = s.size();
		vector<char> v;
		int cnt  = 0;
		int m = 0;
		v.push_back('K');
		while(cnt < f){	
			if(v[m] == s[0]){
				v.erase(v.begin()+m);
				s.erase(s.begin());
				m--;
			}
			else{
				v.push_back(s[0]);
				s.erase(s.begin());
				m++;
			}
			cnt++;
		}
		if(v.size() > 1){
			answer--;
		}
	}
	cout << answer;
}
