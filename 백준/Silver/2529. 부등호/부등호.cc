#include <bits/stdc++.h>
using namespace std;

int k;
char bi[10];
int visited[10];
vector<string> v;

void setNum(int count, int beforeNum, string numStr){
	if(count == k){
		v.push_back(numStr);
		return;
	}
	for(int i = 0; i < 10; i++){
		
		if(visited[i])continue;
		
		if(bi[count] == '<'){
			if(beforeNum < i){
				visited[i] = 1;
				setNum(count+1, i , numStr+to_string(i));
				visited[i] = 0;
			}
		}else{
			if(beforeNum > i){
				visited[i] = 1;
				setNum(count+1, i, numStr+to_string(i));
				visited[i] = 0;
			}
		}
	}
	
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> k;
	for(int i = 0; i < k; i++){
		cin >> bi[i];
	}
	
	for(int i = 0; i < 10; i++){
		visited[i] = 1;
		setNum(0, i, to_string(i));
		visited[i] = 0;
	}
	
	sort(v.begin(), v.end());
    cout << v.back() << "\n"; // 최대값
    cout << v.front() << "\n"; // 최소값
}