#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
#include<utility>
using namespace std;
int gcc(int a,int b){
	if(a<b) swap(a,b);
	if(a%b==0) return b;
	gcc(b,a%b);
}
int lcm(int a,int b){
	int c=gcc(a,b);
	return a*(b/c);
}
pair<int,int> conv(string a){
	pair<int,int>A;
	int pos=0;
	while(a[pos]!='/') pos++;
	A.first=atoi(a.substr(0,pos).c_str()),A.second=atoi(a.substr(pos+1).c_str());
	if(!A.first) A.second=1;
	else{
		int g=gcc(abs(A.first),A.second);
		if(g>1) {
		    A.first/=g;
		    A.second/=g;
		}
	}
	return A;
}
pair<int,int> add(pair<int,int> a,pair<int,int> b){
	pair<int,int>c;
	c.second=lcm(a.second,b.second);
	c.first=c.second/a.second*a.first+c.second/b.second*b.first;
	if(!c.first) c.second=1;
	else{
		int g=gcc(abs(c.first),c.second);
		if(g>1) {
		    c.first/=g;
		    c.second/=g;
		}
	}
	return c;
}
int main(){
	int n;
	cin>>n;
	string input;
	pair<int,int>sum;
    for(int i=0;i<n;i++){
		cin>>input;
		if(!i) sum=conv(input);
		else sum=add(sum,conv(input));
	}
	int x=0;
	if(abs(sum.first)>=sum.second){
		x=sum.first/sum.second;
		sum.first=abs(sum.first)%sum.second;
	}
	if(x!=0){
		cout<<x;
		if(sum.first) cout<<' '<<sum.first<<'/'<<sum.second;
	}
	else if(!sum.first) cout<<0;
	else cout<<sum.first<<'/'<<sum.second;
	return 0;
}
