#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main(){
    int i,n,x,unique=0;
    cin>>n;
    vector<int>numbers;
    map<int,int>fre;
    for(i=0;i<n;i++){
    	cin>>x;
    	fre[x]++;
    	numbers.push_back(x);
	}
	for(i=0;i<n;i++) if(fre[numbers[i]]==1) {
		unique++;
		break;
	}
	if(unique) cout<<numbers[i];
	else cout<<"None";
	return 0;
}
