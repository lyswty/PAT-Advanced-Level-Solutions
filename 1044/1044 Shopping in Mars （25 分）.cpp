#include<iostream>
#include<vector>
#include<climits>
#include<utility>
using namespace std;
vector<int>sum;
int cal(int start, int end) {
	if (start == 0) return sum[end];
	else return sum[end] - sum[start - 1];
}
int binary_search(int a, int m) {
	int start = a, end = sum.size() - 1;
	int mid;
	while (start <= end) {
		mid = (start + end) / 2;
		if (m > cal(a, mid)) start = mid + 1;
		else end = mid - 1;
	}
	return mid;
}
int main() {
	int n, m, t = 0, min = INT_MAX;
	vector<pair<int, int>>output;
	scanf("%d%d", &n, &m);
	sum.resize(n);
	for (int i = 0; i < n; i++) {
		int cur;
		scanf("%d", &cur);
		t += cur;
		sum[i] = t;
	}
	for (int i = 0; i < n; i++) {
		if (cal(i, n - 1) < m) break;
		int j = binary_search(i, m);
		if (cal(i, j) < m) j++;
		if (cal(i, j) < min) {
			min = cal(i, j);
			output.clear();
			output.push_back(make_pair(i + 1, j + 1));
		}
		else if (cal(i, j) == min) output.push_back(make_pair(i + 1, j + 1));
	}
	for (int i = 0; i < output.size(); i++) printf("%d-%d\n", output[i].first, output[i].second);
	system("pause");
	return 0;
}
