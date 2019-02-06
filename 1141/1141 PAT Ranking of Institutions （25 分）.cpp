#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
struct school{
	string code;
	double TWS;
	int rank,ns;
	school(){
		ns=0;
		TWS=0.0;
	}
	friend bool operator<(const school &a,const school &b){
		if((int)a.TWS!=(int)b.TWS) return (int)a.TWS>(int)b.TWS;
		if(a.ns!=b.ns) return a.ns<b.ns;
		return a.code<b.code;
	}
};
int main(){
	int n;
	cin>>n;
	unordered_map<string,school>mp;
	vector<school>list;
	for(int i=0;i<n;i++){
		string ID,schoolcode;
		int score;
		cin>>ID>>score>>schoolcode;
		for(int j=0;j<schoolcode.size();j++) schoolcode[j]=tolower(schoolcode[j]);
		mp[schoolcode].code=schoolcode;
		mp[schoolcode].ns++;
		if(ID[0]=='B') mp[schoolcode].TWS+=score/1.5;
		else if(ID[0]=='A') mp[schoolcode].TWS+=score;
		else mp[schoolcode].TWS+=1.5*score;
	}
	for(auto it=mp.begin();it!=mp.end();it++) list.push_back(it->second);
	sort(list.begin(),list.end());
	cout<<list.size()<<endl;
	list[0].rank=1;
	cout<<list[0].rank<<' '<<list[0].code<<' '<<(int)list[0].TWS<<' '<<list[0].ns<<endl;
	for(int i=1;i<list.size();i++){
	    if((int)list[i].TWS==(int)list[i-1].TWS) list[i].rank=list[i-1].rank;
	    else list[i].rank=i+1;
	    cout<<list[i].rank<<' '<<list[i].code<<' '<<(int)list[i].TWS<<' '<<list[i].ns<<endl;
	}
	return 0;
}
