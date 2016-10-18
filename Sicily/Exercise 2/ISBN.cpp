#include <iostream>
#include <sstream>
using namespace std;
int main() {
	string temp;
	while (cin >> temp) {
		int sum = 0;
		int weight = 10;
		for (unsigned int i = 0; i < temp.size(); i++) {
			if (temp[i] == '-') continue;
			sum += (temp[i] - '0') * (weight--);
		}
		temp += '-';
		int last;
		for (int i = 0; i < 11; i++) {
			if ((sum + i) % 11 == 0) {
				last = i;
				break;
			}
		}
		if (last == 10) temp += "X";
		else {
			stringstream ss;
			ss << last;
			temp += ss.str();
		}
		cout << temp << endl;
	}
	return 0;
}