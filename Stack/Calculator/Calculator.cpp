#include <iostream>
#include <math.h>
#include "Calculator.h"
void Calculator::DoOperator(char op) {
	double left, right, value;
	int result;
	if (result) {
		switch(op) {
			case '+': value = left + right; s.Push(value); break;
			case '-': value = left - right; s.Push(value); break;
			case '*': value = left * right; s.Push(value); break;
			case '/': if (right == 0.0) {
					  		std::cerr << "Devide by 0!" << std::endl;
					  		Clear();
			          } else {
			          		value = left / right; s.Push(value);
			          		break;
			          }
		}
	}
	else Clear();
}

bool Calculator::get2Operands(double& left, double& right) {
	if (s.isEmpty()) {
		std::cerr << "No right operands!" << std::endl;
	}
	s.Pop(right);
	if (s.isEmpty()) {
		std::cerr << "No left operands!" << std::endl;	
	}
	s.Pop(left);
	return true;
}

void Calculator::AddOperand(double value) {
	s.Push(value);
}

void Calculator::Run() {
	char ch;
	double newOperand;
	while (std::cin >> ch, ch != '#') {
		switch(ch) {
			case '+': case '-': case '*': case '/':
					DoOperator(ch); break;
			default: std::cin.putback(ch);
			        std::cin >> newOperand;
			        AddOperand(newOperand);
		}
	}
}

void Calculator::Clear() {
	s.makeEmpty();
}
