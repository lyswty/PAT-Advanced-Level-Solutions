#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct student {
	int ID, t, v;
	friend bool operator<(const student &a, const student &b) {
		if (a.t + a.v != b.t + b.v) return a.t + a.v > b.t + b.v;
		if (a.t != b.t) return a.v > b.v;
		return a.ID < b.ID;
	}
};
int main() {
	vector<student>sage, fool, small, noble;
	int n, l, h;
	scanf("%d%d%d", &n, &l, &h);
	while (n--) {
		student cur;
		scanf("%d%d%d", &cur.ID, &cur.v, &cur.t);
		if (cur.v >= l && cur.t >= l) {
			if (cur.v >= h && cur.t >= h) sage.push_back(cur);
			else if (cur.v >= h) noble.push_back(cur);
			else if (cur.v >= cur.t) fool.push_back(cur);
			else small.push_back(cur);
		}
	}
	sort(sage.begin(), sage.end());
	sort(noble.begin(), noble.end());
	sort(fool.begin(), fool.end());
	sort(small.begin(), small.end());
	printf("%d\n", sage.size() + noble.size() + fool.size() + small.size());
	for (int i = 0; i < sage.size(); i++) printf("%08d %d %d\n", sage[i].ID, sage[i].v, sage[i].t);
	for (int i = 0; i < noble.size(); i++) printf("%08d %d %d\n", noble[i].ID, noble[i].v, noble[i].t);
	for (int i = 0; i < fool.size(); i++) printf("%08d %d %d\n", fool[i].ID, fool[i].v, fool[i].t);
	for (int i = 0; i < small.size(); i++) printf("%08d %d %d\n", small[i].ID, small[i].v, small[i].t);
	system("pause");
	return 0;
}
