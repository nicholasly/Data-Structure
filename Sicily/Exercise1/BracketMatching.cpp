#include <iostream>
#include <stack>
#include <string>
int main() {
	int n;
	std::cin >> n;
	while (n--) {
		std::string str;
		std::stack<char> s;
		bool flag = true;
		std::cin >> str;
		for (unsigned int i = 0; i < str.size(); i++) {
			if (str[i] == '{' || str[i] == '[' || str[i] == '(')
				s.push(str[i]);
            else if (str[i] == ')') {
             	if (s.empty() || s.top() != '(')
                	flag = false;
                else s.pop();
            }
        	else if (str[i] == ']') {
            	if (s.empty() || s.top() != '[')
                	flag = false;
        	    else s.pop();
        	}
        	else if (str[i] == '}') {
            	if (s.empty() || s.top() != '{')
                	flag = false;
            	else s.pop();
        	}
        }
        if (!s.empty()) flag = false;
		if (!flag) std::cout << "No" << std::endl;
		else std::cout << "Yes" << std::endl;
	}
	return 0;
}
