#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
	int n;
	cin>>n;
	while(n--){
		int m;
		bool flag=true;
		cin>>m;
		unordered_map<int,bool>row,sum,re;
		for(int i=0;i<m;i++){
			int j;
			cin>>j;
			if(flag&&row[j]) flag=false;
			else row[j]=true;
			if(flag&&sum[i+j]) flag=false;
			else sum[i+j]=true;
			if(flag&&re[i-j]) flag=false;
			else re[i-j]=true;
		}
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
