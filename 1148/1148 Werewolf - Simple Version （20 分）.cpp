#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int>re(n+1);
	set<int>wolves,curw;
	int *iswolf=new int[n+1];
	for(int i=1;i<=n;i++) cin>>re[i];
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++){
		fill(iswolf,iswolf+n+1,-1);
		curw.clear();
		for(int k=1;k<=n;k++){
			if(k==i||k==j){
				if(re[k]>0){
					iswolf[re[k]]=1;
					curw.insert(re[k]);
				}
				else iswolf[-re[k]]=0;
			}
			if(k!=i&&k!=j){
				if(re[k]>0) iswolf[re[k]]=0;
				else{
					iswolf[-re[k]]=1;
					curw.insert(-re[k]);
				}
			}
			if(curw.size()>2) break;
			if((iswolf[i]==0&&iswolf[j]==0)||(iswolf[i]==1&&iswolf[j]==1)) break;
		}
		if(curw.size()>2||(iswolf[i]==0&&iswolf[j]==0)||(iswolf[i]==1&&iswolf[j]==1)) continue;
		if(curw.size()==2){
			auto wit=curw.begin();
			auto wit2=wit;
			wit2++;
			if(*wit!=i&&*wit!=j&&*wit2!=i&&*wit2!=j) continue;
		}
		if(curw.size()==0){
			if(iswolf[i]==-1){
				curw.insert(i);
				iswolf[i]=1;
				iswolf[j]=0;
			}
			else{
				curw.insert(j);
				iswolf[j]=1;
				iswolf[i]=0;
			}
			for(int k=1;k<=n;k++) if(iswolf[k]==-1){
				curw.insert(k);
				break;
			}
		}
		if(curw.size()==1){
			if(iswolf[i]==1){
				for(int k=1;k<=n;k++) if(k!=j&&iswolf[k]==-1){
					curw.insert(k);
					break;
				}
			}
			else if(iswolf[j]==1){
				for(int k=1;k<=n;k++) if(k!=i&&iswolf[k]==-1){
					curw.insert(k);
					break;
				}
			}
			else if(iswolf[i]==-1) curw.insert(i);
			else if(iswolf[j]==-1) curw.insert(j);
		}
		if(curw.size()!=2) continue;
		if(wolves.empty()||curw<wolves) wolves=curw;
	}
	if(wolves.empty()) cout<<"No Solution";
	else{
		auto it=wolves.begin();
		cout<<*it<<' ';
		cout<<*(++it);
	}
	return 0;
}
