#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string to13(int x){
	string X;
	while(x){
		if(x%13<10) X.push_back(x%13+'0');
		else X.push_back(x%13-10+'A');
		x/=13;
	}
	for(int i=X.size();i<2;i++) X.push_back('0');
	reverse(X.begin(),X.end());
	return X;
}
int main(){
	int R,G,B;
	cin>>R>>G>>B;
	string r=to13(R),g=to13(G),b=to13(B);
	cout<<'#'<<r<<g<<b;
	return 0;
}
