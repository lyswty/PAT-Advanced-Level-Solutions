#include<iostream>
#include<cmath>
#include<vector>
#include<utility>
using namespace std;
bool isprime(int n){
	if(n<2) return false;
	if(n==2) return true;
	if(n%2==0) return false;
	for(int i=3;i<=sqrt(n);i+=2) if(n%i==0) return false;
	return true;
}
int nextprime(int n){
	if(n<2) return 2;
	if(n==2) return 3;
	int i=n+2;
	while(true){
		if(isprime(i)) return i;
		i+=2;
	}
}
int main(){
	int n;
	pair<int,int>prime;
	vector<pair<int,int>>primelist;
	cin>>n;
	int i=1,a=n;
	while(a!=1){
		i=nextprime(i);
		prime.first=i;
		prime.second=0;
		while(a%i==0){
			prime.second++;
			a/=i;
		}
		if(prime.second) primelist.push_back(prime);
	}
	cout<<n<<'=';
	if(n==1) cout<<1;
	for(i=0;i<primelist.size();i++){
		cout<<primelist[i].first;
		if(primelist[i].second!=1) cout<<'^'<<primelist[i].second;
		if(i!=primelist.size()-1) cout<<'*';
	}
	return 0;
}
