#include<iostream>
#include<vector>
using namespace std;
struct highway{
	int cost;
	int dist;
};
vector<int>path;
vector<int>curpath;
highway G[500][500];
bool visited[500];
int dist=0,mindist=99999999,cost=0,mincost=99999999;
void DFS(int n,int s,int d){
	if(dist>mindist) return;
	if(s==d){
		if(dist<mindist){
			mindist=dist;
			mincost=cost;
			path.clear();
			path=curpath;
		}
		else if(cost<mincost){
			mincost=cost;
			path.clear();
			path=curpath;
		}
	}
	for(int i=0;i<n;i++){
		if(!visited[i]&&G[s][i].dist<99999999){
			dist+=G[s][i].dist;
			cost+=G[s][i].cost;
			visited[i]=true;
			curpath.push_back(i);
			DFS(n,i,d);
			visited[i]=false;
			cost-=G[s][i].cost;
			dist-=G[s][i].dist;
			curpath.pop_back();
		}
	}
}
int main(){
	int n,m,s,d;
	cin>>n>>m>>s>>d;
	for(int i=0;i<n;i++){
		visited[i]=false;
	    for(int j=0;j<n;j++)
	        if(i==j){
	        	G[i][j].dist=0;
	        	G[i][j].cost=0;
			}
	        else{
	        	G[i][j].dist=99999999;
	        	G[i][j].cost=99999999;
	        	G[j][i].dist=99999999;
	        	G[j][i].cost=99999999;
			}
    }
    for(int i=0;i<m;i++){
    	int v1,v2;
    	cin>>v1>>v2;
    	cin>>G[v1][v2].dist>>G[v1][v2].cost;
    	G[v2][v1].dist=G[v1][v2].dist;
    	G[v2][v1].cost=G[v1][v2].cost;
	}
	curpath.push_back(s);
	visited[s]=true;
	DFS(n,s,d);
	for(int i=0;i<path.size();i++) cout<<path[i]<<' ';
	cout<<mindist<<' '<<mincost;
	return 0;
}
