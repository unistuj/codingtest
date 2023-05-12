#include<bits/stdc++.h>
using namespace std;

int n, m, j;
int a[22];
int cnt1 = 0;
int f, l;
int ans;


int main(){
	scanf("%d %d", &n, &m);
	scanf("%d", &j);
	for(int i = 0; i < j; i++){
		int u;
		scanf("%d", &u);
		a[i]= u-1;
	}
	int f = 0;
	int l = m-1;
	for(int i = 0; i < j; i++){
		int cnt1 = 0;
		while(f > a[i] || l < a[i]){
			if(a[i] > l){
				f += 1;
				l += 1;
				cnt1 += 1;
			}
			if(a[i] < f){
				f -= 1;
				l -= 1;
				cnt1 += 1;
			}
		}
		ans += cnt1;
	}
	printf("%d", ans);
}
