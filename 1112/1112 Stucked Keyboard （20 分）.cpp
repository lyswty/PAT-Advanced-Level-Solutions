#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
bool judge(const string &a, int i, int k) {
	if (i + k > a.size()) return false;
	for (int j = i + 1; j < i + k; j++) if (a[i] != a[j]) return false;
	return true;
}
int main() {
	int k;
	string a;
	cin >> k >> a;
	unordered_map<char, int>stucked;
	unordered_map<char, bool>out;
	for (int i = 0; i < a.size(); i++) {
		if (stucked[a[i]] == -1) continue;
		if (!judge(a, i, k)) stucked[a[i]] = -1;
		else {
			stucked[a[i]] = 1;
			i += k - 1;
		}
	}
	string output;
	for (int i = 0; i < a.size(); i++) if (stucked[a[i]] == 1) {
		if (!out[a[i]]) {
			output+=a[i];
			out[a[i]] = true;
		}
		a.erase(i + 1, k - 1);
	}
	cout << output << endl << a;
	system("pause");
	return 0;
}
