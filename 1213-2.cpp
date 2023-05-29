#include <bits/stdc++.h>
using namespace std;

int cnt[500], flag;
string a, ret;
char mid;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a;
	for(char i : a)cnt[(int)i]++;
	for(int i = 'Z'; i >= 'A'; i--){
		if(cnt[i]){
			if(cnt[i] & 1){
				mid = char(i);
				flag++;
				cnt[i]--;
			}
			if(flag == 2){
					cout << "I'm Sorry Hansoo\n";
					return 0;
			}
			for(int j = 0; j < cnt[i]; j += 2){
				ret = char(i) + ret;
				ret += char(i);
			}
		}
	}
	if(mid)ret.insert(ret.begin() + ret.size()/2, mid);
	cout << ret;
}
