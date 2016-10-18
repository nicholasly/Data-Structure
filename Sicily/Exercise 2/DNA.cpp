#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) {
    return a.size() > b.size();
}

bool check(string num1, string num2) {
	for (size_t i = 0; i < num1.size(); i++) {
		int a = num1[i] - '0';
		int b = num2[i] - '0';
		if (a + b != 5) return false;
	}
	return true;
}

int main() {
	int test;
	cin >> test;
	while (test--) {
		int num;
		string a[100];
		cin >> num;
		for (int i = 0; i < num; i++) {
			string temp;
			cin >> temp;
			string n = "";
			for (size_t j = 0; j < temp.size(); j++) {
				if (temp[j] == 'A') n += '1';
				else if (temp[j] == 'G') n += '2';
				else if (temp[j] == 'C') n += '3';
				else if (temp[j] == 'T') n += '4';
			}
    		a[i] = n;
		}
		sort(a, a + num, cmp);
		int sum = 0;
		int b[100] = {0};
		for (int i = 0; i < num; i++) {
			if (b[i] == 0) {
				for (int j = i + 1; j < num && a[i].size() == a[j].size(); j++) {
					if (check(a[i], a[j]) && b[j] == 0) {
						sum++;
						b[i] = b[j] = 1;
						break;
					}
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}