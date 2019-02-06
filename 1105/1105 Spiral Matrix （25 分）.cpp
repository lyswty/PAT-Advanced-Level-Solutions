#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<cmath>
using namespace std;
int main() {
	int d, m, n, i = 0, j = -1, direction = 0;
	cin >> d;
	for (n = sqrt(d); d % n; n--);
	m = d / n;
	vector<vector<int>>matrix(m, vector<int>(n, -1));
	vector<int>list(d);
	for (int i = 0; i < d; i++) cin >> list[i];
	sort(list.begin(), list.end(), greater<int>());
	for (int k = 0; k < d; k++) {
		if (direction == 0)
			if (i - 1 < 0 || matrix[i - 1][j] != -1) {
				direction = 1;
				matrix[i][++j] = list[k];
			}
			else matrix[--i][j] = list[k];
		else if (direction == 1)
			if (j + 1 >= n || matrix[i][j + 1] != -1) {
				direction = 2;
				matrix[++i][j] = list[k];
			}
			else matrix[i][++j] = list[k];
		else if (direction == 2)
			if (i + 1 >= m || matrix[i + 1][j] != -1) {
				direction = 3;
				matrix[i][--j] = list[k];
			}
			else matrix[++i][j] = list[k];
		else if (direction == 3)
			if (j - 1 < 0 || matrix[i][j - 1] != -1) {
				direction = 0;
				matrix[--i][j] = list[k];
			}
			else matrix[i][--j] = list[k];
	}
	for (i = 0; i < m; i++) for (j = 0; j < n; j++) {
		cout << matrix[i][j];
		if (j != n - 1) cout << ' ';
		else cout << endl;
	}
	system("pause");
	return 0;
}
