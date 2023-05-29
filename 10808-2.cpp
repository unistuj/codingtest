#include<bits/stdc++.h>
using namespace std;

int no;
int ain;
int aout;
int bin;
int bout;
int ccin;
int ccout;
int cost;
int firstc;
int secondc;
int thirdc;
vector<int> v;

int main(){
	
	std::cin >> firstc >> secondc >> thirdc;
	std::cin >> ain >> aout;
	std::cin >> bin >> bout;
	std::cin >> ccin >> ccout;
	v.push_back(aout);
	v.push_back(bout);
	v.push_back(ccout);
	sort(v.begin(), v.end());
	for(int i = 1; i <= v[2]; i++){
		if(ain == i){
			no++;
		} else if(aout == i){
			no--;
		}
		
		if(bin == i){
			no++;
		} else if(bout == i){
			no--;
		}
		
		if(ccin == i){
			no++;
		} else if(ccout == i){
			no--;
		}
		
		if(no == 1){
			cost += no*firstc;
		} else if( no == 2){
			cost += no*secondc;
		} else if(no == 3){
			cost += no*thirdc;
		}
	}
	cout << cost;
}
