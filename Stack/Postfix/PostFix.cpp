#include <iostream>
#include <stack>

int isp(char s) {
	if (s == '#') return 0;
	if (s == '(') return 1;
	if (s == '*' || s == '/' || s == '%') return 5;
	if (s == '+' || s == '-') return 3;
	if (s == ')') return 6;
	return -1;
}
// in stack priority
int icp(char s) {
	if (s == '#') return 0;
	if (s == '(') return 6;
	if (s == '*' || s == '/' || s == '%') return 4;
	if (s == '+' || s == '-') return 2;
	if (s == ')') return 1;
	return -1;
}
// in comming priority
void postfix(std::string e) {
	std::stack<char> s;
	char ch = '#', ch1, op;
	s.push(ch);
	std::cin.get(ch);
	while (!s.empty() && ch != '#') {
		if (isdigit(ch)) {
			std::cout << ch;
			std::cin.get(ch);
			//  output the operand
		} else {
			ch1 = s.top();
			if (isp(ch1) < icp(ch)) {
				s.push(ch);
				std::cin.get(ch);
			}
			else if (isp(ch1) > icp(ch)) {
                op = s.top();
                // get the top
                std::cout << op;
				s.pop();
			} else {
				op = s.top();
				if (op == '(') std::cin.get(ch);
			}
		}
	}
}