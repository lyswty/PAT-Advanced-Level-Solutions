#include<iostream>
#include<string>
using namespace std;
string next(const string &a){
	string out;
	int j;
	for(int i=0;i<a.size();i=j){
		for(j=i+1;j<a.size()&&a[j]==a[i];j++);
		out+=a[i];
		out+=to_string(j-i);
	}
	return out;
}
int main(){
	string a;
	int cnt;
	cin>>a>>cnt;
	for(int i=1;i<cnt;i++) a=next(a);
	cout<<a;
	return 0;
}
