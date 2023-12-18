#include<bits/stdc++.h>
using namespace std;

const int MAX = 200000;
int n, k;
int ago[MAX+4];
int route[MAX+4];


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	if(k <= n){
		cout << n-k << "\n";
		for(int i = 0; i <= n-k; i++){
			cout << n-i<< " ";
		}
		return 0;
	}else{
		memset(route, 0, sizeof(route));
		memset(ago, 0, sizeof(ago));
		queue<int> q;
		q.push(n);
		while(!q.empty()){
			int now = q.front();
			q.pop();
			for(int next : {now*2, now+1, now-1}){
				if(next < 0 || next >= MAX) continue;
				if(route[next] != 0 || route[next] > route[now])continue;
				route[next]= route[now]+1;
				ago[next] = now;
				q.push(next);
			}
		}
		if(n== 0)cout << route[k]-1 <<"\n";
		else cout << route[k] <<"\n";
		stack<int> s;
		s.push(k);
		int p= k;
		while(p != n){
			p = ago[p];
			s.push(p);
		}
		while(!s.empty()){
			cout << s.top()<< " ";
			s.pop();
		}
		return 0;
	}
}