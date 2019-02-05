#include<iostream>
using namespace std;
struct form{
	int Galleon;
	int Sickle;
	int Knut;
};
int main(){
	form A,B;
	scanf("%d.%d.%d %d.%d.%d",&A.Galleon,&A.Sickle,&A.Knut,&B.Galleon,&B.Sickle,&B.Knut);
	A.Knut+=B.Knut;
	if(A.Knut>=29){
		A.Knut-=29;
		A.Sickle++;
	}
	A.Sickle+=B.Sickle;
	if(A.Sickle>=17){
		A.Sickle-=17;
		A.Galleon++;
	}
	A.Galleon+=B.Galleon;
	printf("%d.%d.%d",A.Galleon,A.Sickle,A.Knut);
	return 0;
}
