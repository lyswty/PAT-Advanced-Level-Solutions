#include<iostream>
#include<vector>
#include<unordered_map>
#include<iomanip>
#include<climits>
using namespace std;
unordered_map<int,vector<vector<int>>>G,line;
int cnt=0,mincnt=INT_MAX,change=0,minchan=INT_MAX,dest;
unordered_map<int,bool>vis;
vector<pair<int,int>>path,curpath;
void DFS(int x,int l){
	vis[x]=true;
	cnt++;
	if(cnt>mincnt||(cnt==mincnt&&x!=dest)) return;
	if(x==dest){
		if(cnt<mincnt){
			mincnt=cnt;
			minchan=change;
			path=curpath;
		}
		else if(cnt==mincnt&&change<minchan){
			minchan=change;
			path=curpath;
		}
	}
	else for(int i=0;i<G[x].size();i++) for(int j=0;j<G[x][i].size();j++){
		if(!vis[G[x][i][j]]){
			vector<pair<int,int>>lastpath=curpath;
			int lastchan=change;
			if(i!=l){
				change++;
				curpath.push_back(pair<int,int>(l,x));
			}
			if(G[x][i][j]==dest) curpath.push_back(pair<int,int>(i,dest));
			DFS(G[x][i][j],i);
			curpath=lastpath;
			vis[G[x][i][j]]=false;
			cnt--;
			change=lastchan;
		}
	}
}
int main(){
	int n,m;
	cin>>n;
	for(int i=0;i<n;i++){
		int last=-1,k;
		cin>>k;
		for(int j=0;j<k;j++){
			int cur;
			cin>>cur;
			if(!G[cur].size()) G[cur].resize(n);
			if(last!=-1){
				G[last][i].push_back(cur);
				G[cur][i].push_back(last);
			}
			last=cur;
		}
	}
	cin>>m;
	for(int i=0;i<m;i++){
		int start;
		cin>>start>>dest;
		mincnt=INT_MAX,cnt=0,change=0,minchan=INT_MAX;
		path.clear();
		curpath.clear();
		DFS(start,-1);
		vis[start]=false;
		cout<<mincnt-1<<endl;
		for(int j=1;j<path.size();j++) cout<<"Take Line#"<<path[j].first+1<<" from "<<setw(4)<<setfill('0')<<path[j-1].second<<" to "<<setw(4)<<setfill('0')<<path[j].second<<'.'<<endl;
	}
	return 0;
}
