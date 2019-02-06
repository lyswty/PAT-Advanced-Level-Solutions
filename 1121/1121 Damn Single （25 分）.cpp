#include<iostream>
#include<unordered_map>
#include<vector>
#include<iomanip>
#include<set>
using namespace std;
int main() {
	int n, m;
	cin >> n;
	unordered_map<int, bool>in;
	unordered_map<int, int>couple;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		couple[a] = b;
		couple[b] = a;
	}
	cin >> m;
	vector<int>v;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		v.push_back(x);
		in[x] = true;
	}
	set<int>damnsingles;
	for (int i = 0; i < m; i++) if (couple.find(v[i]) == couple.end() || !in[couple[v[i]]]) damnsingles.insert(v[i]);
	if (damnsingles.size()) {
		cout << damnsingles.size() << endl << setw(5) << setfill('0') << *damnsingles.begin();
		auto it = damnsingles.begin();
		for (it++; it != damnsingles.end(); it++) cout << ' ' << setw(5) << setfill('0') << *it;
	}
	else cout << 0 << endl;
	system("pause");
	return 0;
}
