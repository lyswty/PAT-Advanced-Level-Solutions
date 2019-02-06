#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n, max = 0;
	long long p;
	cin >> n >> p;
	vector<long long>nums(n);
	for (int i = 0; i < n; i++) cin >> nums[i];
	sort(nums.begin(), nums.end());
	for (int i = 0; i + max < nums.size(); i++) {
		int length = distance(nums.begin() + i, upper_bound(nums.begin() + i + 1, nums.end(), nums[i] * p));
		if (length > max) max = length;
	}
	cout << max;
	system("pause");
	return 0;
}
