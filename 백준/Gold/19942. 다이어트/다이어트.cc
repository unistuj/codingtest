#include <bits/stdc++.h>
using namespace std;

struct Food{
	int p;
	int f;
	int s;
	int v;
	int c;
};

int n;
int mp, mf, ms, mv;
map<int,Food> f;
vector<int> visited;
vector<int> answer;
int value = INT_MAX;

void find(int start, int protein, int fat, int carbs, int vitamin, int cost) {
    if(protein >= mp && fat >= mf && carbs >= ms && vitamin >= mv) {
        if(cost < value) {
            value = cost;
            answer.clear();
            answer = visited;
        } 
        return;
    }

    for(int i = start; i <= n; i++) {
        Food &nowFood = f[i];
        visited.push_back(i);
        find(i + 1, protein + nowFood.p, fat + nowFood.f, carbs + nowFood.s, vitamin + nowFood.v, cost + nowFood.c);
        visited.pop_back();
    }
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	cin >>mp >>mf >> ms >>mv;
	for(int i = 1; i <= n; i++){
		int tempP, tempF, tempS, tempV, tempC;
		cin >> tempP >> tempF >> tempS >> tempV >> tempC;
		Food temp = {tempP, tempF, tempS, tempV, tempC};
		f[i] = temp;
	}
	find(1, 0, 0, 0, 0, 0);
	if(value == INT_MAX){
		cout << -1 << "\n";
	}else{
		cout << value << "\n";
		for(int ans : answer){
			cout << ans << " ";
		}
		cout << "\n";
	}
	
}