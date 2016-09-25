#include <iostream>
#include <string>
void Hanoi(int n, std::string A, std::string B, std::string C) {
	if (n == 1) {
		std::cout << "Move top disk from peg"
		          << A << "to peg" << C << std::endl;
	} else {
		Hanoi(n - 1, A, C, B);
		std::cout << "Move top disk from peg"
		          << A << "to peg" << C << std::endl;
		Hanoi(n - 1, B, A, C);
	}
}
