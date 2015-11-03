#include"ExpressionEvaluator.h"
#include"InfixToPostfix.h"
int main()
{
	string expression;
	cout << "enter an infix expresion" << endl;
	getline(cin, expression,'\n');

	InfixToPostfix s(expression);
	string exp = s.convert();
	cout << " the expression is: " << endl << exp << endl;
	ExpressionEvaluator e(exp);
	cout << "the valur of \"" << expression << "\" : " << e.value() << endl;

	system("PAUSE");
	return 0;
}