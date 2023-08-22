#include<bits/stdc++.h>
using namespace std;
int l;
int c;
int al[26];
vector<char> v;
vector<int> lll;
int mo;
int za;

void com(int cnt, int s){
	if(cnt == l){
		if(mo < 1 || za < 2)return;
		for(int i = 0; i < l; i++){
			int p = lll[i];
			cout << v[p];
		}
		cout << "\n";
		return;
	}
	for(int i = s; i < c; i++){
		if(v[i] == 'a' ||v[i] == 'e' ||v[i] == 'i' ||v[i] == 'o' ||v[i] == 'u'){
			mo++;
			lll.push_back(i);
			com(cnt+1, i+1);
			lll.pop_back();
			mo--;
		}else{
			za++;
			lll.push_back(i);
			com(cnt+1, i+1);
			lll.pop_back();
			za--;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> l >> c;
	for(int i = 0; i < c; i++){
		char tmp;
		cin >> tmp;
		al[tmp-'a'] = 1;
	}
	for(int i = 0; i < 26; i++){
		if(al[i] == 1){
			v.push_back(i+'a');
		}
	}
	com(0, 0);
}