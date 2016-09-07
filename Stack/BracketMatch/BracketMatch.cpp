#include <iostream>
#include <stdio.h>
#include <string.h>
#include "LinkedStack.h"

const int maxLength = 100;

void printBracketMatch(char * expression) {
	LinkedStack<int> s(maxLength);
	int j, length = strlen(expression);
	for (int i = 1; i < length; i++) {
		if (expression[i - 1] == '(') s.Push(i);
		else if (expression[i - 1] == ')') {
			if (s.Pop(j) == true)
				std::cout << j << " and " << i << " are matched" << std::endl;
			else std::cout << "There is no left bracket that can match a left bracket" << std::endl;
		}
	}
	while (!s.isEmpty()) {
		s.Pop(j);
		std::cout << "There is no left bracket that can match the final left bracket" << std::endl;
	}
}
