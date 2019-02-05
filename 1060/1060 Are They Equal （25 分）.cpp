#include<iostream>
#include<string>
#include<sstream>
using namespace std;
string tran(string a,int n){
	int del,point,k;
	for(del=0;del<a.size();del++) if(a[del]!='0') break;
	if(del==a.size()) a="0";
	else if(a[del]=='.') a=a.substr(del-1);
	else a=a.substr(del);
	for(point=0;point<a.size();point++) if(a[point]=='.') break;
	if(point==1&&a[point-1]=='0'){
		int i;
		for(i=2;i<a.size();i++) if(a[i]!='0') break;
		if(i==a.size()) k=0;
		else k=2-i;
	}
	else if(a=="0") k=0;
	else k=point;
	string b="0.";
	int start;
	for(start=0;start<a.size();start++) if(a[start]!='0'&&a[start]!='.') break;
	for(int i=0;i<n;i++){
		if(start<a.size()&&a[start]=='.') start++;
		if(start<a.size()){
			b+=a[start];
			start++;
		}
		else b+='0';
	}
	stringstream ss;
	ss<<k;
	string K=ss.str();
	b=b+"*10^"+K;
	return b;
}
int main(){
	int n;
	string a,b;
	cin>>n>>a>>b;
	a=tran(a,n);
	b=tran(b,n);
	if(a==b) cout<<"YES"<<' '<<a;
	else cout<<"NO"<<' '<<a<<' '<<b;
	return 0;
}
