#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
int k, n, p, curn = 0, curk = 0, total = 0, maxtotal = 0;
vector<int>out, cur;
void DFS(int x) {
	curk++;
	curn += pow(x, p);
	total += x;
	cur.push_back(x);
	if (curn > n || curk > k || (curk == k && curn != n)) return;
	if (curn == n) {
		if (curk != k) return;
		if (total > maxtotal) {
			maxtotal = total;
			out = cur;
			reverse(out.begin(), out.end());
		}
		else if (total == maxtotal) {
			vector<int>curb = cur;
			reverse(curb.begin(), curb.end());
			if (curb > out) out = curb;
		}
	}
	else for (int i = x; i <= pow((n - curn) / (k - curk), (double)1 / p); i++) {
		DFS(i);
		curk--;
		curn -= pow(i, p);
		total -= i;
		cur.pop_back();
	}
}
int main() {
	cin >> n >> k >> p;
	for (int i = 1; i <= pow(n / k, (double)1 / p); i++) {
		DFS(i);
		curk = curn = total = 0;
		cur.clear();
	}
	if (!out.size()) cout << "Impossible";
	else {
		cout << n << " = ";
		for (int i = 0; i < k; i++) {
			cout << out[i] << '^' << p;
			if (i != k - 1) cout << " + ";
		}
	}
	system("pause");
	return 0;
}
