#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
struct student {
	string ID;
	int PTA, Gm, Gf, score;
	student() {
		Gm = Gf = -1;
		PTA = score = 0;
	}
	friend bool operator<(const student &a, const student &b) {
		if (a.score != b.score) return a.score > b.score;
		return a.ID < b.ID;
	}
};
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	unordered_map<string, student>stu;
	for (int i = 0; i < n; i++) {
		string ID;
		int score;
		cin >> ID >> score;
		stu[ID].PTA = score;
		stu[ID].ID = ID;
	}
	for (int i = 0; i < m; i++) {
		string ID;
		int score;
		cin >> ID >> score;
		stu[ID].Gm = score;
		stu[ID].ID = ID;
	}
	for (int i = 0; i < k; i++) {
		string ID;
		int score;
		cin >> ID >> score;
		stu[ID].Gf = score;
		stu[ID].ID = ID;
	}
	vector<student>out;
	for (auto it = stu.begin(); it != stu.end(); it++) {
		if (it->second.PTA < 200) continue;
		if (it->second.Gm > it->second.Gf) it->second.score = 0.4 * it->second.Gm + 0.6 * it->second.Gf + 0.5;
		else it->second.score = it->second.Gf;
		if (it->second.score >= 60) out.push_back(it->second);
	}
	sort(out.begin(), out.end());
	for (int i = 0; i < out.size(); i++) cout << out[i].ID << ' ' << out[i].PTA << ' ' << out[i].Gm << ' ' << out[i].Gf << ' ' << out[i].score << endl;
	system("pause");
	return 0;
}
