#include <iostream>
#include <string>
#include <stack>
using namespace std;
string transfer(string str) {
    stack<char> s;
    string temp;
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            temp += str[i];
            continue;
        }
        if (str[i] >= 'a' && str[i] <= 'z') {
            temp += str[i];
            continue;
        }
        if (str[i] == '+' || str[i] == '-') {
            if (s.empty()) {
                s.push(str[i]);
                continue;
            }
            if (s.top() == '*' || s.top() == '/' || s.top() == '%') {
                while (!s.empty()) {
                    temp += s.top();
                    s.pop();
                }
                s.push(str[i]);
                continue;
            }
            if (s.top() == '+' || s.top() == '-') {
                temp += s.top();
                s.pop();
                s.push(str[i]);
                continue;
            }
        }
        if (str[i] == '*' || str[i] == '/' || str[i] == '%') {
            if (s.empty()) {
                s.push(str[i]);
                continue;
            }
            if (s.top() == '+' || s.top() == '-') {
                s.push(str[i]);
                continue;
            }
            if (s.top() == '*' || s.top() == '/' || s.top() == '%') {
                while (!s.empty()) {
                    temp += s.top();
                    s.pop();
                }
                s.push(str[i]);
                continue;
            }
        }
    }
    while (!s.empty()) {
        temp += s.top();
        s.pop();
    }
    return temp;
}

int main() {
    string temp;
    cin >> temp;
    cout << transfer(temp);
    return 0;
}
