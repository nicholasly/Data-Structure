#include <iostream>
#include <stack>
#include <iomanip>	
#include <vector>
using namespace std;

double trans(char s) {
	return (s - 'a' + 1.0);
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		string temp;
	    cin >> temp;
	    vector<char> v;
	    for (size_t i = 0; i < temp.size(); i++) {
	    	v.push_back(temp[i]);
	    }
	    stack<double> s;
	    for (vector<char>::iterator iter = v.begin(); iter != v.end(); ) {
	    	if (*iter >= 'a' && *iter <= 'z') {
	    		s.push(trans(*iter));
	    		v.erase(iter);
	    		continue;
	    	}
	    	if (*iter == '+') {
	    		double t1 = s.top();
	    		s.pop();
	    		double t2 = s.top();
	    		s.pop();
	    		s.push(t1 + t2);
	    		v.erase(iter);
	    		continue;
	    	}
	    	if (*iter == '-') {
	    		double t1 = s.top();
	    		s.pop();
	    		double t2 = s.top();
	    		s.pop();
	    		s.push(t2 - t1);
	    		v.erase(iter);
	    		continue;
	    	}
	    	if (*iter == '*') {
	    		double t1 = s.top();
	    		s.pop();
	    		double t2 = s.top();
	    		s.pop();
	    		s.push(t1 * t2);
	    		v.erase(iter);
	    		continue;
	    	}
	    	if (*iter == '/') {
	    		double t1 = s.top();
	    		s.pop();
	    		double t2 = s.top();
	    		s.pop();
	    		s.push(t2 / t1);
	    		v.erase(iter);
	    		continue;
	    	}
	    }
	    cout.precision(2);
        cout.setf(ios::fixed);
        cout << s.top() << endl;
	}
	return 0;
}
