#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
struct fraction {
	long long first, second;
	bool negative;
};
long long gcd(long long a, long long b) {
	if (a < b) swap(a, b);
	while (a % b) {
		a %= b;
		swap(a, b);
	}
	return b;
}
long long lcm(long long a, long long b) {
	return a * b / gcd(a, b);
}
fraction reduction(fraction a) {
	if (!a.second) return a;
	if (!a.first) {
		a.second = 1;
		return a;
	}
	long long c = gcd(a.first, a.second);
	a.first /= c;
	a.second /= c;
	return a;
}
fraction conver(string x) {
	fraction a;
	if (x[0] == '-') {
		a.negative = true;
		x = x.substr(1);
	}
	else a.negative = false;
	auto it = find(x.begin(), x.end(), '/');
	a.first = stoi(x.substr(0, distance(x.begin(), it)));
	a.second = stoi(x.substr(distance(x.begin(), it) + 1));
	return reduction(a);
}
void output(fraction a) {
	if (!a.second) cout << "Inf";
	else if (!a.first) cout << '0';
	else {
		if (a.negative) cout << "(-";
		if (a.first >= a.second) {
			cout << a.first / a.second;
			a.first %= a.second;
			if (a.first) cout << ' ';
		}
		if (a.first) cout << a.first << '/' << a.second;
		if (a.negative) cout << ')';
	}
}
fraction add(fraction a, fraction b);
fraction reduce(fraction a, fraction b);
fraction add(fraction a, fraction b) {
	a = reduction(a), b = reduction(b);
	if (a.negative && !b.negative) {
		a.negative = false;
		return reduce(b, a);
	}
	if (!a.negative && b.negative) {
		b.negative = false;
		return reduce(a, b);
	}
	long long r = lcm(a.second, b.second);
	a.first *= r / a.second;
	b.first *= r / b.second;
	a.first += b.first;
	a.second = b.second = r;
	return reduction(a);
}
fraction reduce(fraction a, fraction b) {
	if (a.negative && !b.negative) {
		b.negative = true;
		return add(a, b);
	}
	if (!a.negative && b.negative) {
		b.negative = false;
		return add(a, b);
	}
	long long r = lcm(a.second, b.second);
	a.first *= r / a.second;
	b.first *= r / b.second;
	a.second = b.second = r;
	a.first -= b.first;
	if (a.first < 0) {
		a.negative = !a.negative;
		a.first = 0 - a.first;
	}
	return reduction(a);
}
fraction multiply(fraction a, fraction b) {
	a.first *= b.first;
	a.second *= b.second;
	if (a.negative == b.negative) a.negative = false;
	else a.negative = true;
	return reduction(a);
}
fraction divide(fraction a, fraction b) {
	swap(b.first, b.second);
	return multiply(a, b);
}
int main() {
	string a, b;
	cin >> a >> b;
	fraction x = conver(a), y = conver(b);
	output(x);
	cout << " + ";
	output(y);
	cout << " = ";
	output(add(x, y));
	cout << endl;
	output(x);
	cout << " - ";
	output(y);
	cout << " = ";
	output(reduce(x, y));
	cout << endl;
	output(x);
	cout << " * ";
	output(y);
	cout << " = ";
	output(multiply(x, y));
	cout << endl;
	output(x);
	cout << " / ";
	output(y);
	cout << " = ";
	output(divide(x, y));
	cout << endl;
	system("pause");
	return 0;
}
