#include<iostream>
#include<queue>
#include<memory.h>
#include<vector>
#include<algorithm>
using namespace std;

int h[101][101];
int n;
int s;
int visited[101];
int mx;
queue<int> q;
vector<int> an;
vector<int> ans;
int cnt;
int before;
int after;

bool compare(int a , int b){
	return a > b;
}

void gogogo() {
	visited[s] = 1;
	q.push(s);
	an.clear();
	before = 1;
	after = 0;
	while(q.size() != 0){
		int now = q.front();
		q.pop();
		before--;
		for(int i = 1; i <= 100; i++){
			if(visited[i] == 1)continue;
			if(h[now][i] == 1){
				visited[i] = 1;
				an.push_back(i);
				q.push(i);
				after++;
				
			}
		}
		if(before == 0  && after != 0){
			before = after;
			after = 0;
			ans.clear();
			for(int tam : an){
				ans.push_back(tam);
			}
			an.clear();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int test = 1; test <= 10; test++) {
		memset(h, 0, 101 * 101 * sizeof(int));
		memset(visited, 0, 101 * sizeof(int));
		cin >> n >> s;
		for (int i = 0; i < n / 2; i++) {
			int from, to;
			cin >> from >> to;
			h[from][to] = 1;
		}
		
		gogogo();
		sort(ans.begin(), ans.end(), compare);
		mx = ans[0];

		cout << "#" << test << " " << mx << "\n";
	}
}