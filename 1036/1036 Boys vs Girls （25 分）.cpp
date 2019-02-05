#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
struct student {
	string name, ID;
	int score;
};
bool cmp(const student &a, const student &b) {
	return a.score > b.score;
}
int main() {
	int n;
	cin >> n;
	vector<student>female, male;
	while (n--) {
		student cur;
		char g;
		cin >> cur.name >> g >> cur.ID >> cur.score;
		if (g == 'F') female.push_back(cur);
		else male.push_back(cur);
	}
	sort(female.begin(), female.end(), cmp);
	sort(male.begin(), male.end(), cmp);
	if (female.size()) cout << female[0].name << ' ' << female[0].ID << endl;
	else cout << "Absent" << endl;
	if (male.size()) cout << male[male.size() - 1].name << ' ' << male[male.size() - 1].ID << endl;
	else cout << "Absent" << endl;
	if (female.size() && male.size()) cout << female[0].score - male[male.size() - 1].score;
	else cout << "NA";
	system("pause");
	return 0;
}
