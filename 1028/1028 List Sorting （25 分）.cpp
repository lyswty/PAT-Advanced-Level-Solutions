#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
struct record {
	string ID, name;
	int grade;
};
bool cmp1(const record &a, const record &b) {
	return a.ID < b.ID;
}
bool cmp2(const record &a, const record &b) {
	if (a.name != b.name) return a.name < b.name;
	return a.ID < b.ID;
}
bool cmp3(const record &a, const record &b) {
	if (a.grade != b.grade) return a.grade < b.grade;
	return a.ID < b.ID;
}
int main() {
	int n, c;
	cin >> n >> c;
	record *List = new record[n];
	for (int i = 0; i < n; i++) {
		char ID[10], name[10];
		scanf("%s%s%d", ID, name, &List[i].grade);
		List[i].ID = ID;
		List[i].name = name;
	}
	switch (c) {
	case 1:sort(List, List + n, cmp1); break;
	case 2:sort(List, List + n, cmp2); break;
	default:sort(List, List + n, cmp3);
	}
	for (int i = 0; i < n; i++) printf("%s %s %d\n", List[i].ID.c_str(), List[i].name.c_str(), List[i].grade);
	system("pause");
	return 0;
}
