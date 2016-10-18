#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int arr[60010];
    int next[60010];
    int pro[1000010];
    int lenOfCode;
    int lenOfProtection;
    while (cin >> lenOfCode) {
        if (0 != lenOfCode) {
            for (int i = 0; i < lenOfCode; i++) {
                cin >> arr[i];
            }
            cin >> lenOfProtection;
            for (int i = 0; i < lenOfProtection; i++) {
                cin >> pro[i];
            }
            memset(next, 0, sizeof(next[0]) * 60010);
            next[0] = 0;
            int index = 0;
            for (int i = 1; i < lenOfCode; i++) {
                if (arr[i] == arr[index]) {
                    next[i] = index;
                    index++;
                } else {
                    next[i] = index;
                    index = 0;
                }
            }
            index = 0;
            int result = 0;
            bool found = false;
            for (int i = 0; i < lenOfProtection ; i++) {
                if (arr[index] == pro[i]) {
                    index++;
                } else if (index != 0) {
                    i--;
                    index = next[index];
                }
                if (index == lenOfCode) {
                    result = i - index + 1;
                    found = true;
                    break;
                }                   
            }
            if (found) cout << result << endl;
            else cout << "no solution" << endl;
        }
    }
    return 0;
}
