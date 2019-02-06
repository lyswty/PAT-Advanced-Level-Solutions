#include<iostream>
#include<string>
#include<vector>
using namespace std;
string dig[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
string pos[3]={"Shi","Bai","Qian"};
int main(){
	string n;
	int i=0;
	cin>>n;
	vector<string>output;
	if(n[0]=='-'){
		n=n.substr(1);
		output.push_back("Fu");
	}
	if(n.size()==9) {
		output.push_back(dig[n[0]-'0']);
		output.push_back("Yi");
		i++;
	}
	if(n.size()-i>4){
	    while(n.size()-i>4)
		    if(n[i]!='0'){
			    output.push_back(dig[n[i]-'0']);
			    if(n.size()-i>=6) output.push_back(pos[n.size()-6-i]);
			    i++;
		    }
		    else for(;n.size()-i>4;i++)
		    	if(n[i]!='0'){
		    		output.push_back(dig[0]);
		    		break;
				}
		output.push_back("Wan");
    }
    if(n.size()-i>0){
	    while(n.size()-i>0)
		    if(n[i]!='0'){
			    output.push_back(dig[n[i]-'0']);
			    if(n.size()-i>=2) output.push_back(pos[n.size()-2-i]);
			    i++;
		    }
		    else for(;n.size()-i>0;i++)
		    	if(n[i]!='0'){
		    		output.push_back(dig[0]);
		    		break;
				}
    }
    if(n=="0") output.push_back(dig[0]);
    for(int i=0;i<output.size();i++){
    	cout<<output[i];
    	if(i!=output.size()-1) cout<<' ';
	}
    return 0;
}
