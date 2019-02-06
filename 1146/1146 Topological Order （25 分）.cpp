#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>>G;
bool judge(vector<int> ne){
	bool flag=true;
	for(int i=0;i<G.size()-1;i++){
		int x;
		cin>>x;
		if(ne[x]) flag=false;
		if(flag) for(int j=0;j<G[x].size();j++) ne[G[x][j]]--;
	}
	return flag;
}
int main(){
	int n,m,k;
	cin>>n>>m;
	vector<int>ne(n+1,0),output;
	G.resize(n+1);
	for(int i=0;i<m;i++){
		int v1,v2;
		cin>>v1>>v2;
		G[v1].push_back(v2);
		ne[v2]++;
	}
	cin>>k;
	for(int i=0;i<k;i++) if(!judge(ne)) output.push_back(i);
	for(int i=0;i<output.size();i++){
		cout<<output[i];
		if(i!=output.size()-1) cout<<' ';
	}
	return 0;
}
