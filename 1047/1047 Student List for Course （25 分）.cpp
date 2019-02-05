#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<string> *course = new vector<string>[m];
	for (int i = 0; i < n; i++) {
		char name[5];
		int k;
		scanf("%s %d", name, &k);
		while (k--) {
			int c;
			scanf("%d", &c);
			course[c - 1].push_back(name);
		}
	}
	for (int i = 0; i < m; i++) {
		printf("%d %d\n", i + 1, course[i].size());
		sort(course[i].begin(), course[i].end());
		for (auto j = course[i].begin(); j != course[i].end(); j++) printf("%s\n", (*j).c_str());
	}
	delete[] course;
	system("pause");
	return 0;
}
