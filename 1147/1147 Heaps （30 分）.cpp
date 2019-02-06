#include<iostream>
#include<vector>
using namespace std;
void post(const vector<int> &T,int x){
	if(x>=T.size()) return;
	post(T,2*x+1);
	post(T,2*x+2);
	cout<<T[x];
	if(x) cout<<' ';
	else cout<<endl;
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		vector<int>T(m);
		int heapstate=0;
		for(int j=0;j<m;j++) cin>>T[j];
		for(int j=0;j*2+1<m;j++){
			if(T[j]>T[j*2+1]&&(j*2+2>=m||T[j]>T[j*2+2])){
				if(heapstate==0||heapstate==1) heapstate=1;
				else heapstate=3;
			}
			else if(T[j]<T[j*2+1]&&(j*2+2>=m||T[j]<T[j*2+2])){
				if(heapstate==0||heapstate==2) heapstate=2;
				else heapstate=3;
			}
			else heapstate=3;
			if(heapstate==3) break;
		}
		switch(heapstate){
			case 1:cout<<"Max Heap"<<endl;break;
			case 2:cout<<"Min Heap"<<endl;break;
			default:cout<<"Not Heap"<<endl;
		}
		post(T,0);
	}
	return 0;
}
