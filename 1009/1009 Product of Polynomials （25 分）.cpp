#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
struct polymonial{
	int expon;
	double coef;
};
int findexpon(vector<polymonial> &v,int expon){
	for(int i=0;i<v.size();i++) if(v[i].expon==expon) return i;
	return -1;
}
bool cmp(const polymonial &a,const polymonial &b){
	return a.expon>b.expon;
}
int main(){
	polymonial x;
	int na,nb;
	vector<polymonial>A,B;
	cin>>na;
	for(int i=0;i<na;i++){
		cin>>x.expon>>x.coef;
		if(x.coef) A.push_back(x);
	}
	cin>>nb;
	for(int i=0;i<nb;i++){
		cin>>x.expon>>x.coef;
		if(x.coef) B.push_back(x);
	}
	vector<polymonial>C;
	for(int i=0;i<na;i++)
	    for(int j=0;j<nb;j++){
	    	x.coef=A[i].coef*B[j].coef;
	    	x.expon=A[i].expon+B[j].expon;
	    	if(findexpon(C,x.expon)==-1) C.push_back(x);
	    	else{
		        C[i].coef+=x.coef;
		        if(!C[i].coef) C.erase(C.begin()+i);
		    }
		}
	sort(C.begin(),C.end(),cmp);
	cout<<C.size()<<' ';
	for(int i=0;i<C.size();i++)
	    if(i==C.size()-1) cout<<C[i].expon<<' '<<fixed<<setprecision(1)<<C[i].coef;
	    else cout<<C[i].expon<<' '<<fixed<<setprecision(1)<<C[i].coef<<' ';
	return 0;
}
