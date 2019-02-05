#include<iostream>
#include<algorithm>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
	int n, swaps = 0, i = 0;
	cin >> n;
	int *nums = new int[n];
	int *pos = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		pos[nums[i]] = i;
	}
	while (true) {
		while (pos[0]) {
			swap(nums[pos[0]], nums[pos[pos[0]]]);
			swap(pos[pos[0]], pos[0]);
			swaps++;
		}
		for (; i < n; i++) if (pos[i] != i) {
			swap(nums[pos[i]], nums[0]);
			swap(pos[0], pos[i]);
			swaps++;
			break;
		}
		if (i == n) break;
	}
	cout << swaps;
	delete[] pos, nums;
	system("pause");
	return 0;
}
