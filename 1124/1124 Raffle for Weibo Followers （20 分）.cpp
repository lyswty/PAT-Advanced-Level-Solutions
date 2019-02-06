#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
int main() {
	unordered_map<string, bool>iswinner;
	vector<string>winner;
	int n, m, s;
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) {
		string cur;
		cin >> cur;
		if (i == s && !iswinner[cur]) {
			iswinner[cur] = true;
			winner.push_back(cur);
			s += m;
		}
		else if (i == s && iswinner[cur]) s++;
	}
	if (!winner.size()) cout << "Keep going...";
	else for (int i = 0; i < winner.size(); i++) cout << winner[i] << endl;
	system("pause");
	return 0;
}
