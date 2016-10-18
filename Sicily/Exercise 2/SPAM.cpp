#include <iostream>
using namespace std;
int main() {
	string temp;
	string email;
	while (getline(cin, temp)) {
		if (temp.length() == 0) continue;
		string user, server;
		int index;
		bool dot;
		for (int i = 0; i < temp.length(); i++) {
			if (temp[i] == '@') {
				user = server = "";
				index = i - 1;
				dot = false;
			    while (index >= 0) {
					if ((temp[index] >= 'a' && temp[index] <= 'z') || \
						(temp[index] >= 'A' && temp[index] <= 'Z') || \
						(temp[index] >= '0' && temp[index] <= '9') || \
						temp[index] == '-' || temp[index] == '_') {
							user = temp[index--] + user;
					} else if (temp[index] == '.') {
						if (!dot) {
							user = temp[index--] + user;
							dot = true;
						} else break;
					} else break;
				}
				if (user.length() == 0)  continue; 
				if (user.length() == 1 && user[0] == '.')  continue;
				if (user[0] == '.') user = user.substr(1);
				index = i + 1;
				dot = false;
				while (index < temp.length()) {
					if ((temp[index] >= 'a' && temp[index] <= 'z') ||
						(temp[index] >= 'A' && temp[index] <= 'Z') ||
						(temp[index] >= '0' && temp[index] <= '9') ||
						temp[index] == '-' || temp[index] == '_') {
						server += temp[index++];
					} else if (temp[index] == '.') {
						if (!dot) {
							server += temp[index++];
							dot = true;
						} else break;
					} else break;
				}
				if (server[server.length() - 1] == '.') server = server.substr(0, server.length() - 1);
				if (server.length() == 0)  continue;  
            	if (server.length() == 1 && server[0] == '.')  continue;
            	email = user + "@" + server;
            	cout << email << endl;
            	email.clear();
            }
		}
	}
	return 0;
}