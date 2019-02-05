#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
	string str;
	getline(cin,str);
	vector<int>*dp=new vector<int>[str.size()];
	int max=1;
	for(int i=0;i<str.size();i++){
		dp[i].resize(str.size());
		dp[i][i]=1;
		if(i!=str.size()-1){
			dp[i][i+1]=(str[i]==str[i+1]?2:0);
			if(dp[i][i+1]==2) max=2;
		} 
	}
	for(int i=0;i<str.size();i++)
		for(int j=i-2;j>=0;j--)
			if(str[j]==str[i])
				if(dp[j+1][i-1]>0){
					dp[j][i]=dp[j+1][i-1]+2;
					if(dp[j][i]>max) max=dp[j][i];
				}
				else dp[j][i]=0;
			else dp[j][i]=0;
	cout<<max;
	return 0;
}
