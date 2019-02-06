#include<iostream>
#include<set>
#include<string>
using namespace std;
int main() {
	int n;
	cin >> n;
	set<int>fs;
	for (int i = 0; i < n; i++) {
		string cur;
		int sum = 0;
		cin >> cur;
		for (int i = 0; i < cur.size(); i++) sum += cur[i] - '0';
		fs.insert(sum);
	}
	cout << fs.size() << endl;
	cout << *fs.begin();
	auto it = fs.begin();
	for (it++; it != fs.end(); it++) cout << ' ' << *it;
	system("pause");
	return 0;
}
