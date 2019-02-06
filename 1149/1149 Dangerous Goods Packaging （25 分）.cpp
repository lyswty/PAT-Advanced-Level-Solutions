#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	unordered_map<int,vector<int>>inc;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		inc[x].push_back(y);
		inc[y].push_back(x);
	}
	for(int i=0;i<m;i++){
		bool flag=true;
		int k;
		unordered_map<int,bool>cant;
		cin>>k;
		for(int j=0;j<k;j++){
			int x;
			cin>>x;
			if(cant[x]) flag=false;
			for(int i=0;i<inc[x].size();i++) cant[inc[x][i]]=true;
		}
		if(flag) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
