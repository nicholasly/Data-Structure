#include <iostream>
#include <vector>

const int maxSize = 1001;
const int num = 3;
const int max = 20000;

int p[maxSize], color[maxSize], min[maxSize], s[num][maxSize], l[num];
int n, t = 0, su = 1;
int bit[max], loc[max], con[max];
std::vector<char> output;
bool flag = true;

void connect(int i, int j) {
    loc[++t] = bit[i];
    bit[i] = t;
    con[t] = j;
    loc[++t] = bit[j];
    bit[j] = t;
    con[t] = i;
}

 void paint(int x,int c) { 
    if (!color[x])  color[x]=c;
    else if (color[x] != c) {
       flag = false;
	   output.clear();
       output.push_back('0');
       return;
    }
    else return;
    for (int i = bit[x]; i; i = loc[i] ) {
        paint(con[i], 3 - c);    
    }
}

int main() {
    while (std::cin >> n) {
		for (int i = 1; i < n + 1; i++) {
            std::cin >> p[i];       
        }
        min[n] = p[n];
        for (int i = n - 1; i > 0; i--) {
            min[i] = (min[i + 1] < p[i]) ? min[i + 1] : p[i];
        }
        s[1][0] = 1002;
        color[n + 1] = 1;
        s[2][0] = 1002;
        p[n + 1] = 1001;
        for (int i = 1; i <= n - 2; i++) {
            for (int j = i + 1; j <= n - 1; j++) {
                if (p[i] < p[j] && min[j + 1] < p[i]) connect(i, j);
            }
        }
        for (int i = 1; i <= n; i++) {
            if (!color[i]) paint(i, 1);
        }
        for (int i = 1; i <= n + 1; i++) {
            while(1) {
                if (s[1][l[1]] == su) {
                    su++;
                    l[1]--;
                    if (flag) output.push_back('b');
                }
                else if (s[2][l[2]] == su) {
                    su++;
                    l[2]--;
                    if (flag) output.push_back('d');
                }
                else break;
            }
            s[color[i]][++l[color[i]]] = p[i];
            if (i < n + 1) {
                if (color[i] == 1 && flag) output.push_back('a');
                else if (color[i] == 2 && flag) output.push_back('c');
            }
        }
        for (std::vector<char>::iterator it = output.begin(); it != output.end(); it++) {
        	if (it != output.begin()) std::cout << " ";
        	std::cout << *it;
		}
		std::cout << std::endl;
		for (int i = 0; i < maxSize; i++) {
			p[i] = 0;
			color[i] = 0;
			min[i] = 0;
		}
		for (int i = 0; i < max; i++) {
			bit[i] = 0;
			loc[i] = 0;
			con[i] = 0;
		}
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < maxSize; j++) {
				s[i][j] = 0;
			}
			l[i] = 0;
		}
		t = 0;
		su = 1;	
		output.clear();
		flag = true;
    }
    return 0;
}
