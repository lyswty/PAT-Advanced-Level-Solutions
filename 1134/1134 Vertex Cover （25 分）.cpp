#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;
int main(){
	int n,m,k;
	cin>>n>>m;
	bool *vertex=new bool[n];
	pair<int,int> *edge=new pair<int,int>[m];
	for(int i=0;i<m;i++) cin>>edge[i].first>>edge[i].second;
	cin>>k;
	while(k--){
		fill(vertex,vertex+n,false);
		int c;
		bool yn=true;
		cin>>c;
		for(int i=0;i<c;i++){
			int cur;
			cin>>cur;
			vertex[cur]=true;
		}
		for(int i=0;i<m;i++) if(!vertex[edge[i].first]&&!vertex[edge[i].second]){
			yn=false;
			break;
	    }
		if(yn) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
