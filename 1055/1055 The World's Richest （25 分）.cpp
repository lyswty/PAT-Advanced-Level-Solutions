#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct person {
	string name;
	int age, networth;
	friend bool operator<(const person &a, const person &b) {
		if (a.networth != b.networth) return a.networth > b.networth;
		if (a.age != b.age) return a.age < b.age;
		return a.name < b.name;
	}
};
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	vector<person>list;
	while (n--) {
		person cur;
		char name[10];
		scanf("%s %d %d", name, &cur.age, &cur.networth);
		cur.name = name;
		list.push_back(cur);
	}
	sort(list.begin(), list.end());
	for (int i = 1; i <= k; i++) {
		int m, amin, amax, cnt = 0;
		scanf("%d%d%d", &m, &amin, &amax);
		printf("Case #%d:\n", i);
		for (int j = 0; j < list.size(); j++) {
			if (list[j].age >= amin && list[j].age <= amax) {
				printf("%s %d %d\n", list[j].name.c_str(), list[j].age, list[j].networth);
				cnt++;
			}
			if (cnt == m) break;
		}
		if (!cnt) printf("None\n");
	}
	system("pause");
	return 0;
}
