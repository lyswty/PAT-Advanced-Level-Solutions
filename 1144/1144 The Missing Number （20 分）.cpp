#include<iostream>
#include<map>
using namespace std;
map<int,bool>have;
int main(){
	int n,min=1;
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		if(x<=0) continue;
		have[x]=true;
		if(x==min) for(min++;have[min];min++);
	}
	cout<<min;
	return 0;
}
