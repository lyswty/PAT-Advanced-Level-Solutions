#include<iostream>
#include<cmath>;
#include<algorithm>
using namespace std;
bool isprime(int x) {
	if (x < 2) return false;
	if (x == 2) return true;
	if (x % 2 == 0) return false;
	for (int i = 3; i <= sqrt(x); i += 2) if (x % i == 0) return false;
	return true;
}
int nextprime(int x) {
	if (x <= 2) return 2;
	if (x % 2 == 0) x++;
	while (!isprime(x)) x += 2;
	return x;
}
int main() {
	int msize, n;
	cin >> msize >> n;
	int tsize = nextprime(msize);
	bool *occupied = new bool[tsize];
	fill(occupied, occupied + tsize, false);
	int *pos = new int[n];
	fill(pos, pos + n, -1);
	for (int i = 0; i < n; i++) {
		int cur;
		cin >> cur;
		int p = cur % tsize;
		if (!occupied[p]) {
			occupied[p] = true;
			pos[i] = p;
		}
		else {
			for (int j = 1; j < tsize; j++) {
				p += j * j;
				if (!occupied[p % tsize]) {
					occupied[p % tsize] = true;
					pos[i] = p % tsize;
					break;
				}
				p -= j * j;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (pos[i] != -1) cout << pos[i];
		else cout << '-';
		if (i != n - 1) cout << ' ';
	}
	delete[] pos, occupied;
	system("pause");
	return 0;
}
