#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
int main() {
	string a, b;
	unordered_map<char, int>mpa, mpb;
	cin >> a >> b;
	for (int i = 0; i < a.size(); i++) mpa[a[i]]++;
	for (int i = 0; i < b.size(); i++) mpb[b[i]]++;
	int missing = 0;
	for (auto it = mpb.begin(); it != mpb.end(); it++) if (mpa[it->first] < it->second) missing += it->second - mpa[it->first];
	if (missing) cout << "No " << missing;
	else cout << "Yes " << a.size() - b.size();
	system("pause");
	return 0;
}
