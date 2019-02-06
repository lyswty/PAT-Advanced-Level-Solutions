#include<iostream>
#include<vector>
#include<string>
using namespace std;
int Hash(char x) {
	if (isdigit(x)) return x - '0';
	else if (isalpha(x)) return toupper(x) - 'A' + 10;
	else return 36;
}
int main() {
	bool inv[37] = { false };
	string a, b;
	getline(cin, a);
	getline(cin, b);
	vector<char>broken;
	for (int i = 0, j = 0; i < a.size(); i++) {
		while (i < a.size() && j == b.size() || a[i] != b[j]) {
			if (!inv[Hash(a[i])]) {
				if (isalpha(a[i])) broken.push_back(toupper(a[i]));
				else broken.push_back(a[i]);
				inv[Hash(a[i])] = true;
			}
			i++;
		}
		j++;
	}
	for (int i = 0; i < broken.size(); i++) cout << broken[i];
	system("pause");
	return 0;
}
