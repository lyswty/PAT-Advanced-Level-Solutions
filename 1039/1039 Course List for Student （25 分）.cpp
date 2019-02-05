#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
  int n, k, index, sn;
  scanf("%d %d",&n,&k);
  vector<int>courselist[200000];
  char name[5];
  for (int i = 0; i < k; i++) {
    scanf("%d %d",&index,&sn);
    while (sn--) {
      scanf("%s",name);
      int sum = 0;
      sum +=  (name[0]-'A')*26*26*10 + (name[1]-'A')*26*10 + (name[2]-'A')*10 + name[3]-'0';
      courselist[sum].push_back(index);
    }
  }
  for (int i = 0; i < n; i++) {
    scanf("%s",name);
    int sum = 0;
    sum += (name[0]-'A')*26*26*10 + (name[1]-'A')*26*10 + (name[2]-'A')*10 + name[3]-'0';
    sort(courselist[sum].begin(),courselist[sum].end());
    printf("%s %d",name,courselist[sum].size());
    for (int i = 0; i < courselist[sum].size() ; i++) printf(" %d",courselist[sum][i]);
    printf("\n");
  }
  system("pause");
  return 0;
}
