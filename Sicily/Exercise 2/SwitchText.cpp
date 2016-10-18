#include <iostream>
#include <string>
using namespace std;
int main() {
	string temp;
	int index = 0;
	string answer1 = "";
	string answer2 = "";
	while (getline(cin, temp)) {
		index++;
		string first, second;
		if (temp.length() % 2 == 0) {
			first = temp.substr(0, temp.length() / 2);
		    second = temp.substr(temp.length() / 2, temp.length() / 2);
		} else {
			first = temp.substr(0, (temp.length() + 1) / 2);
		    second = temp.substr((temp.length() + 1) / 2, (temp.length() + 1) / 2);
		}
		for (int i = first.length() - 1; i >= 0; i--) {
			if (index % 2 != 0) answer1 += first[i];
			else answer2 += first[i];
		}
		for (int i = second.length() - 1; i >= 0; i--) {
			if (index % 2 != 0) answer1 += second[i];
			else answer2 += second[i];
		}
		if (index % 2 == 0) {
			if (answer2.length() != 0) cout << answer2 << endl;
			if (answer1.length() != 0) cout << answer1 << endl;
			answer1.clear();
			answer2.clear();
		}
	}
	return 0;
}