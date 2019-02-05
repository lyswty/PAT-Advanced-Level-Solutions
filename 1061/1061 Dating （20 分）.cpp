#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int main() {
	string week[7] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
	string a1, a2, b1, b2;
	cin >> a1 >> a2 >> b1 >> b2;
	int i, day, hour, minute;
	for (i = 0; i < a1.size(); i++) if (a1[i] == a2[i] && a1[i] >= 'A'&&a1[i] <= 'G') break;
	day = a1[i] - 'A';
	for (i++; i < a1.size(); i++) if (a1[i] == a2[i] && (isdigit(a1[i]) || (a1[i] >= 'A'&&a1[i] <= 'N'))) break;
	if (isdigit(a1[i])) hour = a1[i] - '0';
	else hour = a1[i] - 'A' + 10;
	for (i = 0; i < b1.size(); i++) if (b1[i] == b2[i] && isalpha(b1[i])) break;
	minute = i;
	cout << week[day] << ' ' << setw(2) << setfill('0') << hour << ':' << setw(2) << setfill('0') << minute;
	system("pause");
	return 0;
}
