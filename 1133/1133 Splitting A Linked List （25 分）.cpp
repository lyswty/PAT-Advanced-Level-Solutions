#include<iostream>
#include<unordered_map>
#include<vector>
#include<iomanip>
using namespace std;
struct node{
	int addr,next,data;
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int start,n,k;
	cin>>start>>n>>k;
	unordered_map<int,node>mp;
	while(n--){
	    node cur;
		cin>>cur.addr>>cur.data>>cur.next;
		mp[cur.addr]=cur;
	}
	vector<node>neg,lowk,highk;
	for(;start!=-1;start=mp[start].next){
		if(mp[start].data<0) neg.push_back(mp[start]);
		else if(mp[start].data<=k) lowk.push_back(mp[start]);
		else highk.push_back(mp[start]);
	}
	for(int i=0;i<neg.size();i++){
		cout<<setw(5)<<setfill('0')<<neg[i].addr<<' '<<neg[i].data<<' ';
		if(i!=neg.size()-1) cout<<setw(5)<<setfill('0')<<neg[i+1].addr<<endl;
		else if(lowk.size()) cout<<setw(5)<<setfill('0')<<lowk[0].addr<<endl;
		else if(highk.size()) cout<<setw(5)<<setfill('0')<<highk[0].addr<<endl;
		else cout<<-1<<endl;
	}
	for(int i=0;i<lowk.size();i++){
		cout<<setw(5)<<setfill('0')<<lowk[i].addr<<' '<<lowk[i].data<<' ';
		if(i!=lowk.size()-1) cout<<setw(5)<<setfill('0')<<lowk[i+1].addr<<endl;
		else if(highk.size()) cout<<setw(5)<<setfill('0')<<highk[0].addr<<endl;
		else cout<<-1<<endl;
	}
	for(int i=0;i<highk.size();i++){
		cout<<setw(5)<<setfill('0')<<highk[i].addr<<' '<<highk[i].data<<' ';
		if(i!=highk.size()-1) cout<<setw(5)<<setfill('0')<<highk[i+1].addr<<endl;
		else cout<<-1<<endl;
	}
    return 0;
}
