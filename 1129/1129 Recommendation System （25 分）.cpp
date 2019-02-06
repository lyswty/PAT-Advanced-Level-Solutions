#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int>fre,item;
bool cmp(const int &a,const int &b){
	if(fre[a]!=fre[b]) return fre[a]>fre[b];
	return a<b;
}
int main(){
	int n,k,last=-1;
	unordered_map<int,bool>mp;
	scanf("%d%d",&n,&k);
	fre.resize(n+1,0);
	for(int i=0;i<n;i++){
		int q;
		scanf("%d",&q);
		if(i){
			printf("%d: %d",q,item[0]);
			for(int j=1;j<item.size();j++) printf(" %d",item[j]);
			printf("\n");
		}
		fre[q]++;
		if(!mp[q]){
		    if(item.size()<k){
				item.push_back(q);
				sort(item.begin(),item.end(),cmp);
				mp[q]=true;
			}
		    else if(fre[item[item.size()-1]]<fre[q]||(fre[item[item.size()-1]]==fre[q]&&item[item.size()-1]>q)){
		    	mp[item[item.size()-1]]=false;
		    	item[item.size()-1]=q;
		    	sort(item.begin(),item.end(),cmp);
		    	mp[q]=true;
			}
		}
		else sort(item.begin(),item.end(),cmp);
	}
	return 0;
}
