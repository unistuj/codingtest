#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while(true){
		string s;
		getline(cin, s);
		if(s == ".")break;
		stack<int> st;
		bool b = true;
		for(int i = 0; i<s.size(); i++){
			if(s[i] == '(')st.push(s[i]);
			if(s[i] == '[')st.push(s[i]);
			if(s[i] == ')'){
				if(st.size() == 0 || st.top() == '['){
					b = false;
					break;
				}else{
					st.pop();
				}
			}
			if(s[i] == ']'){
				if(st.size() == 0 || st.top() == '('){
					b = false;
					break;
				}else{
					st.pop();
				}
			}
		}
		if(b && st.size() == 0)cout<< "yes"<<"\n";
		else cout << "no" <<"\n";
	}
}