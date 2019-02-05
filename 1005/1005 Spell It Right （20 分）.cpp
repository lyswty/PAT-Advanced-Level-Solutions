#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
void print(int n) {
	switch (n) {
	case 0:cout << "zero"; break;
	case 1:cout << "one"; break;
	case 2:cout << "two"; break;
	case 3:cout << "three"; break;
	case 4:cout << "four"; break;
	case 5:cout << "five"; break;
	case 6:cout << "six"; break;
	case 7:cout << "seven"; break;
	case 8:cout << "eight"; break;
	default:cout << "nine"; break;
	}
}
int main() {
	string input;
	vector<int>v;
	int sum = 0;
	cin >> input;
	for (int i = 0; i < input.size(); i++) {
		sum += input[i] - '0';
	}
	int b = 1;
	while (1) {
		if (sum >= pow(10,b)) b++;
		else break;
	}
	while (sum >= 10 || b != 1) {
		print(sum / int(pow(10, b - 1)));
		cout << ' ';
		sum %= int(pow(10, b - 1));
		b--;
	}
	print(sum);
	system("pause");
	return 0;
}
