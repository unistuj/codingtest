#include<iostream>
#include<vector>
using namespace std;

int n,e, node;
int cnt;
vector <int> no[51];

void countnode(int p) {
	int child = 0;
	for (int i = 0; i <no[p].size(); i++) {
		int t = no[p][i];
		if(t == e)continue;
		child++;
		countnode(t);
	}
	if(child == 0)cnt++;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if(temp == -1)node = i;
		else{
			no[temp].push_back(i);
		}
	}
	cin >> e;
	
	if(e == node){
		cout << 0 << "\n";
		return 0;
	}else{
		countnode(node);
		cout << cnt << "\n";
	}
	
}
