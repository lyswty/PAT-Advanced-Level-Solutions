#include<iostream>
#include<algorithm>
#include<string>
#include<utility>
#include<vector>
using namespace std;
bool cmp(const pair<string, int> &a, const pair<string, int> &b) {
	if (a.second != b.second) return a.second > b.second;
	return a.first < b.first;
}
int main() {
	int n, k;
	cin >> n >> k;
	vector<vector<pair<string, int>>>rows(k);
	rows[0].resize(n % k + n / k);
	for (int i = 1; i < k; i++) rows[i].resize(n / k);
	vector<pair<string, int>>stu;
	for (int i = 0; i < n; i++) {
		string name;
		int height;
		cin >> name >> height;
		stu.push_back(make_pair(name, height));
	}
	sort(stu.begin(), stu.end(), cmp);
	for (int i = 0; i < k; i++) {
		int start, end;
		if (!i) {
			start = 0;
			end = rows[i].size();
		}
		else {
			start = n / k * i + n % k;
			end = start + n / k;
		}
		int x = rows[i].size() / 2 - 1, y = rows[i].size() / 2, j = start;
		while (j < end) {
			rows[i][y++] = stu[j++];
			if (j == end) break;
			rows[i][x--] = stu[j++];
		}
	}
	for (int i = 0; i < k; i++) for (int j = 0; j < rows[i].size(); j++) {
		cout << rows[i][j].first;
		if (j != rows[i].size() - 1) cout << ' ';
		else cout << endl;
	}
	system("pause");
	return 0;
}
