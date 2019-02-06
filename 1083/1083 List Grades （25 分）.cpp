#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
struct student {
	string ID;
	string name;
	int grade;
};
bool cmp(const student &a, const student &b) {
	return a.grade > b.grade;
}
int main() {
	int n;
	cin >> n;
	vector<student>stu;
	while (n--) {
		student cur;
		cin >> cur.name >> cur.ID >> cur.grade;
		stu.push_back(cur);
	}
	int grade1, grade2;
	cin >> grade1 >> grade2;
	sort(stu.begin(), stu.end(), cmp);
	bool flag = false;
	for (int i = 0; i < stu.size(); i++) {
		if (stu[i].grade > grade2) continue;
		if (stu[i].grade < grade1) break;
		if (!flag) flag = true;
		cout << stu[i].name << ' ' << stu[i].ID << endl;
	}
	if (!flag) cout << "NONE";
	system("pause");
	return 0;
}
