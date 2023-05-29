#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll c, k;
map<int, int> mp, mp_first;
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b){
	if(a.first == b.first){
		return mp_first[a.second] < mp_first[b.second];
	}
	return a.first > b.first;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	cin >> n >> c;
	for(int i = 0; i < n; i++){
		cin >> k;
		mp[k]++;
		if(mp_first[k] == 0)mp_first[k] = i + 1;
	}
	
	for(auto u : mp){
		v.push_back({u.second, u.first});
	}
	
	sort(v.begin(), v.end(), cmp);
	
	
	for(auto m : v){
		for(int i = 0; i < m.first; i++){
			cout << m.second <<' ';
		}
	}
	return 0;
}
