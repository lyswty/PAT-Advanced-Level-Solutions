#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
int main() {
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	unordered_map<char, bool>iss2;
	for (int i = 0; i < s2.size(); i++) iss2[s2[i]] = true;
	for (int i = 0; i < s1.size(); i++) if (!iss2[s1[i]]) cout << s1[i];
	system("pause");
	return 0;
}
