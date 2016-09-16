#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <math.h>
#include "LinkedStack.h"
class Calculator {
public:
	Calculator(int sz) : s(sz) {}
	//  Constructor
	void Run();
	//  Calculating Operation
	void Clear();
private:
	LinkedStack<double> s;
	//  Stack
	void AddOperand(double value);
	//  Put operands into the stack
	bool get2Operands(double& left, double& right);
	//  Pop 2 operands out of the stack
	void DoOperator(char op);
	//  Do the calculation
};
// Define a simple calculator class

#endif
