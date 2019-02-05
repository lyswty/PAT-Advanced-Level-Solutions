#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct customer {
	int serve, arrive;
	friend bool operator<(const customer &a, const customer &b) {
		return a.arrive < b.arrive;
	}
};
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	customer *queues = new customer[n];
	int *windows = new int[k];
	fill(windows, windows + k, 8 * 60 * 60);
	for (int i = 0; i < n; i++) {
		int hh, mm, ss;
		scanf("%d:%d:%d %d", &hh, &mm, &ss, &queues[i].serve);
		queues[i].arrive = hh * 3600 + mm * 60 + ss;
		queues[i].serve = queues[i].serve * 60 < 3600 ? queues[i].serve * 60 : 3600;
	}
	sort(queues, queues + n);
	int total = 0, i;
	for (i = 0; i < n; i++) {
		if (queues[i].arrive > 17 * 3600) break;
		int min = 999999999, minwindow = -1;
		for (int j = 0; j < k; j++) if (windows[j] < min) {
			min = windows[j];
			minwindow = j;
		}
		if (queues[i].arrive < min) {
			total += min - queues[i].arrive;
			windows[minwindow] += queues[i].serve;
		}
		else windows[minwindow] = queues[i].arrive + queues[i].serve;
	}
	printf("%.1f", (double)total / 60 / i);
	system("pause");
	return 0;
}
