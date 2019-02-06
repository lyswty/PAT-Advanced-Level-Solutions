#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n, end;
	bool insertion = true;
	cin >> n;
	int *a = new int[n], *b = new int[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	for (end = 1; b[end] >= b[end - 1]; end++);
	for (int i = end; i < n; i++) if (a[i] != b[i]) insertion = false;
	if (insertion) {
		cout << "Insertion Sort" << endl;
		sort(b, b + end + 1);
	}
	else {
		cout << "Heap Sort" << endl;
		for (end = n - 1; b[end] >= b[0]; end--);
		swap(b[0], b[end]);
		make_heap(b, b + end);
	}
	for (int i = 0; i < n; i++) {
		cout << b[i];
		if (i != n - 1) cout << ' ';
	}
	delete[] a, b;
	system("pause");
	return 0;
}
