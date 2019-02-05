#include<iostream>
#include<string>
using namespace std;
int convert(char a){
	if(isdigit(a)) return a-'0';
	else return a-'a'+10;
}
long long tolongint(string x,long long r){
	long long sum=0;
	for(int i=0;i<x.size();i++){
		sum=sum*r+convert(x[i]);
		if(sum<0) return -1;
	}
	return sum;
}
long long find(long long x1,string x2){
	if(x1<0) return -1;
	int max=0;
	for(int i=0;i<x2.size();i++) if(convert(x2[i])>max) max=convert(x2[i]);
	long long start=max+1,end=x1+1;
	while(start<=end){
		long long mid=(start+end)/2;
		if(tolongint(x2,mid)==x1) return mid;
		if(tolongint(x2,mid)<0||tolongint(x2,mid)>x1) end=mid-1;
		else start=mid+1;
	}
	return -1;
}
int main(){
	string s1,s2;
	long long radix,outradix;
	int flag;
	cin>>s1>>s2>>flag>>radix;
	if(flag==1) outradix=find(tolongint(s1,radix),s2);
	else outradix=find(tolongint(s2,radix),s1);
	if(outradix<0) cout<<"Impossible"<<endl;
	else cout<<outradix<<endl;
	return 0;
}
