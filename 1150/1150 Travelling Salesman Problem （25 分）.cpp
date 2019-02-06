#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int G[201][201];
bool vis[201];
int main(){
	int n,m,k,mini=-1,min=99999999;
	cin>>n>>m;
	memset(G,-1,sizeof(G));
	for(int i=0;i<m;i++){
		int v1,v2,d;
		cin>>v1>>v2>>d;
		G[v1][v2]=d;
		G[v2][v1]=d;
	}
	cin>>k;
	for(int i=1;i<=k;i++){
		memset(vis,false,sizeof(vis));
		int cnt,flag=1,total=0;
		cin>>cnt;
		vector<int>path(cnt);
		for(int j=0;j<cnt;j++){
			cin>>path[j];
			if(flag==0) continue;
			if(vis[path[j]]) flag=2;
			if(j!=0){
				vis[path[j]]=true;
				if(G[path[j-1]][path[j]]==-1) flag=0;
				else total+=G[path[j-1]][path[j]];
			}
		}
		cout<<"Path "<<i<<": ";
		if(flag) for(int j=1;j<=n;j++) if(!vis[j]) flag=3;
		if(!flag) cout<<"NA (Not a TS cycle)"<<endl;
		else if(path[path.size()-1]!=path[0]||flag==3) cout<<total<<" (Not a TS cycle)"<<endl;
		else if(flag==1){
			cout<<total<<" (TS simple cycle)"<<endl;
			if(total<min){
				min=total;
				mini=i;
			}
		}
		else{
			cout<<total<<" (TS cycle)"<<endl;
			if(total<min){
				min=total;
				mini=i;
			}
		}
	}
	cout<<"Shortest Dist("<<mini<<") = "<<min<<endl;
	return 0;
}
