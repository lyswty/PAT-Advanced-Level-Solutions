#include<iostream>
#include<cmath>
#include<unordered_map>
#include<algorithm>
#include<iomanip>
using namespace std;
bool isprime(int x){
	if(x<2) return false;
	if(x==2) return true;
	if(x%2==0) return false;
	for(int i=3;i<=sqrt(x);i+=2) if(x%i==0) return false;
	return true;
}
int nextprime(int x){
	if(x==2) return x;
	if(x%2==0) x++;
	while(!isprime(x)) x+=2;
	return x;
}
int main(){
	int n,m,size,total=0;
	cin>>size>>n>>m;
	size=nextprime(size);
	int *hl=new int[size];
	fill(hl,hl+size,-1);
	unordered_map<int,int>time;
	for(int i=0;i<n;i++){
		int x,j;
		cin>>x;
		for(j=0;j<size;j++) if(hl[(x%size+j*j)%size]==-1){
			hl[(x%size+j*j)%size]=x;
			break;
		}
		if(j==size) cout<<x<<" cannot be inserted."<<endl;
		time[x]=j+1;
	}
	for(int i=0;i<m;i++){
		int x,j;
		cin>>x;
		if(time[x]) total+=time[x];
		else{
			for(j=0;j<size;j++) if(hl[(x%size+j*j)%size]==-1) break;
			total+=j+1;
		}
	}
	cout<<setprecision(1)<<fixed<<(double)total/m;
	return 0;
}
