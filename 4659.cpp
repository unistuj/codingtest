#include<bits/stdc++.h>
using namespace std;

string s;
int cnt, mo, ja;
int flag;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	while(1){
		cin >> s;
		if(s == "end")return 0;
		mo =0;
		cnt = 0;
		ja = 0;
		flag = 1;
		
		if(s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u'){
			cnt++;
			mo++;
		}else{
			ja++;
		}
		
		for(int i = 1; i < s.size(); i++){
			if(flag){
				if(s[i-1] == s[i] && s[i] != 'e' && s[i] != 'o'){
					flag--;
					cout <<"<" << s << ">" << " is not acceptable."<<"\n";
					break;
				}
			}
			
			if(flag){
				if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
					cnt++;
					mo++;
					ja = 0;
					if(mo > 2){
						flag--;
						cout <<"<" << s << ">" << " is not acceptable."<<"\n";
						break;
					}
				}else{
					ja++;
					mo = 0;
					if(ja > 2){
						flag--;
						cout <<"<" << s << ">" << " is not acceptable."<<"\n";
						break;
					}
				}
			}
			
		}
		if(flag){
			if(cnt == 0){
				flag--;
				cout <<"<" << s << ">" << " is not acceptable."<<"\n";
			}
		}

		if(flag){
			cout <<"<" << s << ">" << " is acceptable."<<"\n";	
		}
	}
}
