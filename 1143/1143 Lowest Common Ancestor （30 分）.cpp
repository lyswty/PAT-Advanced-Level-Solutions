#include<iostream>
#include<unordered_map>
using namespace std;
unordered_map<int,bool>fs;
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int *pre=new int[m];
	for(int i=0;i<m;i++){
		scanf("%d",&pre[i]);
		fs[pre[i]]=true;
	}
	for(int i=0;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if(!fs[x]&&!fs[y]) printf("ERROR: %d and %d are not found.\n",x,y);
		else if(!fs[x]) printf("ERROR: %d is not found.\n",x);
		else if(!fs[y]) printf("ERROR: %d is not found.\n",y);
		else for(int j=0;j<m;j++){
			if((pre[j]<x&&pre[j]<y)||(pre[j]>x&&pre[j]>y)) continue;
			if(pre[j]==x) printf("%d is an ancestor of %d.\n",x,y);
			else if(pre[j]==y) printf("%d is an ancestor of %d.\n",y,x);
			else printf("LCA of %d and %d is %d.\n",x,y,pre[j]);
			break;
		}
	}
	delete[] pre;
	return 0;
}
