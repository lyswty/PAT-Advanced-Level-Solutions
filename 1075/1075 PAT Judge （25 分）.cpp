#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
using namespace std;
struct student {
	int id, perfect, total, rank;
	bool out;
	vector<int>score;
	student() {
		perfect = 0, total = 0, out = false;
	}
	friend bool operator<(const student &a, const student &b) {
		if (!a.out) return false;
		if (!b.out) return true;
		if (a.total != b.total) return a.total > b.total;
		if (a.perfect != b.perfect) return a.perfect > b.perfect;
		return a.id < b.id;
	}
};
int main() {
	int n, k, m;
	cin >> n >> k >> m;
	student *students = new student[n];
	for (int i = 0; i < n; i++) {
		students[i].score.resize(k, -2);
		students[i].id = i + 1;
	}
	int *ps = new int[k];
	for (int i = 0; i < k; i++) cin >> ps[i];
	for (int i = 0; i < m; i++) {
		int id, pn, sc;
		cin >> id >> pn >> sc;
		if (sc >= 0) students[id - 1].out = true;
		if (sc > students[id - 1].score[pn - 1]) {
			if (sc > 0 && students[id - 1].score[pn - 1] > 0) students[id - 1].total += sc - students[id - 1].score[pn - 1];
			else if (sc > 0 && students[id - 1].score[pn - 1] <= 0) students[id - 1].total += sc;
			students[id - 1].score[pn - 1] = sc;
			if (sc == ps[pn - 1]) students[id - 1].perfect++;
		}
	}
	sort(students, students + n);
	students[0].rank = 1;
	cout << 1 << ' ' << setw(5) << setfill('0') << students[0].id << ' ' << students[0].total << ' ';
	for (int i = 0; i < k; i++) {
		if (students[0].score[i] >= 0) cout << students[0].score[i];
		else if (students[0].score[i] == -2) cout << '-';
		else cout << 0;
		if (i != k - 1) cout << ' ';
		else cout << endl;
	}
	for (int j = 1; j < n; j++) {
		if (!students[j].out) break;
		if (students[j].total == students[j - 1].total) students[j].rank = students[j - 1].rank;
		else students[j].rank = j + 1;
		cout << students[j].rank << ' ' << setw(5) << setfill('0') << students[j].id << ' ' << students[j].total << ' ';
		for (int i = 0; i < k; i++) {
			if (students[j].score[i] >= 0) cout << students[j].score[i];
			else if (students[j].score[i] == -2) cout << '-';
			else cout << 0;
			if (i != k - 1) cout << ' ';
			else cout << endl;
		}
	}
	delete[] students, ps;
	system("pause");
	return 0;
}
