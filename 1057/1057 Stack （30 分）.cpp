#include<iostream>
#include<stack>
#include<set>
#include<string>
#include<climits>
using namespace std;
multiset<int>s1, s2;
int adjust() {
	if (s1.size() > s2.size() + 1) {
		auto it = s1.end();
		it--;
		s2.insert(*it);
		s1.erase(it);
	}
	if (s2.size() > s1.size()) {
		s1.insert(*s2.begin());
		s2.erase(s2.begin());
	}
	if (s1.empty()) return INT_MAX;
	auto med = s1.end();
	med--;
	return *med;
}
int main() {
	stack<int>s;
	int median = INT_MAX, n;
	scanf("%d", &n);
	while (n--) {
		char op[11];
		scanf("%s", op);
		if (op[1] == 'u') {
			int x;
			scanf("%d", &x);
			s.push(x);
			if (x <= median) s1.insert(x);
			else s2.insert(x);
			median = adjust();
		}
		else if (op[1] == 'o') {
			if (s.empty()) printf("Invalid\n");
			else {
				int x = s.top();
				s.pop();
				if (x > median) s2.erase(s2.find(x));
				else s1.erase(s1.find(x));
				printf("%d\n", x);
				median = adjust();
			}
		}
		else if (s.empty())  printf("Invalid\n");
		else printf("%d\n", median);
	}
	system("pause");
	return 0;
}
