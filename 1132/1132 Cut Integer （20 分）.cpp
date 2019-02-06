#include<iostream>
#include<string>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string x;
		cin>>x;
		long long a=stoi(x),b=stoi(x.substr(0,x.size()/2)),c=stoi(x.substr(x.size()/2));
		if(b&&c&&a%b==0&&a/b%c==0) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
