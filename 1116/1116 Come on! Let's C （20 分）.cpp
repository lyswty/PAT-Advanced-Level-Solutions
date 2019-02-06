#include<iostream>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int Rank[10000], checked[10000];
bool isprime(int x) {
	if (x < 2) return false;
	if (x == 2) return true;
	if (x % 2 == 0) return false;
	for (int i = 3; i <= sqrt(x); i += 2) if (x%i == 0) return false;
	return true;
}
int main() {
	int n, m;
	cin >> n;
	memset(Rank, -1, sizeof(Rank));
	memset(checked, 0, sizeof(checked));
	for (int i = 1; i <= n; i++) {
		int ID;
		cin >> ID;
		Rank[ID] = i;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int cur;
		cin >> cur;
		cout << setw(4) << setfill('0') << cur << ": ";
		if (Rank[cur] == -1) cout << "Are you kidding?" << endl;
		else if (checked[cur]) cout << "Checked" << endl;
		else if (Rank[cur] == 1) cout << "Mystery Award" << endl;
		else if (isprime(Rank[cur])) cout << "Minion" << endl;
		else cout << "Chocolate" << endl;
		checked[cur] = 1;
	}
	system("pause");
	return 0;
}
