#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int G[201][201];
int main(){
	int nv,ne,q;
	cin>>nv>>ne;
	memset(G,0,sizeof(G));
	for(int i=0;i<ne;i++){
		int v1,v2;
		cin>>v1>>v2;
		G[v1][v2]=1;
		G[v2][v1]=1;
	}
	cin>>q;
	for(int i=0;i<q;i++){
		int k,judge=2;
		cin>>k;
		int *subset=new int[k];
		bool *issub=new bool[nv+1];
		fill(issub,issub+nv+1,false);
		for(int j=0;j<k;j++){
		    cin>>subset[j];
		    issub[subset[j]]=true;
		}
		for(int j=1;j<=nv;j++){
			if(!judge) break;
			if(issub[j]) for(int l=0;l<k;l++){
				if(j!=subset[l]&&!G[j][subset[l]]){
					judge=0;
					break;
				}
			}
			else{
				bool flag=true;
				for(int l=0;l<k;l++) if(!G[j][subset[l]]){
					flag=false;
					break;
				}
				if(flag) judge=1;
			}
		}
		switch(judge){
			case 0:cout<<"Not a Clique"<<endl;break;
			case 1:cout<<"Not Maximal"<<endl;break;
			default:cout<<"Yes"<<endl;
		}
		delete[] subset,issub;
	}
	return 0;
}
