#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int cur=0;
	int to;
	int time=0;
	while(n--){
		cin>>to;
		if(to<cur) time+=4*(cur-to)+5;
		else if(to==cur) time+=5;
		else time+=6*(to-cur)+5;
		cur=to;
	}
	cout<<time;
	return 0;
}
