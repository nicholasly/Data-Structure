#include <iostream>
const int maxSize = 20;

class polynomal {
private:
    int n;
	int coef[maxSize];
public:
	polynomal() {
		n = 0;
		for (int i = 0; i < maxSize; i++) {
			coef[i] = 0;
		}
	}
	void inputData() {
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			int t1, t2;
			std::cin >> t1 >> t2; 
			coef[t2] = t1;
		}
	}
	polynomal addition(polynomal b) {
		polynomal c;
		c.n = 0; 
		for (int i = 0; i < maxSize; i++) {
			c.coef[i] = coef[i] + b.coef[i];
			if (c.coef[i] != 0) c.n++; 
		}
		return c;
	}
		friend void outputResult(polynomal);
};

void outputResult(polynomal c) {
	std::cout << c.n << std::endl;
	for (int i = maxSize - 1; i >= 0; i--) {
		if (c.coef[i] == 0) continue;
		std::cout << c.coef[i] << " " << i << std::endl;
	}
}

int main() {
	int m;
	std::cin >> m;
	while (m--) {
		polynomal a, b ,c;
		a.inputData();
		b.inputData();
		c = a.addition(b);
		outputResult(c);
	}
	return 0;
}
