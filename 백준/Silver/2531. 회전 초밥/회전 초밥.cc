#include<bits/stdc++.h>
using namespace std;

int n, d, k, c;
unordered_map<int, int> mp;
int mx;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> d >> k >> c;
	int cho[n];
	
	for(int i = 0; i < n; i++){
		cin >>cho[i];

	}
	for(int i = 0; i < k-1; i++){
		mp[cho[i]]++;
	}
	
	int s = 0;
	int e = k-1;
	for(int i = 0; i < n; i++){
		int del = cho[s];
		int ins = cho[e%n];
		mp[ins]++;
		int tans = mp.size();
		if(mp.find(c) == mp.end()){
			mx = max(mx, tans+1);
		}else{
			mx = max(mx, tans);
		}
		mp[del]--;
		if(mp[del] == 0)mp.erase(mp.find(del));
		s++;
		e++;
	}

	
	cout << mx;
}