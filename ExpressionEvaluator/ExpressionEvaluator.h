#include<iostream>
#include<string>
#include<sstream>
#include<stack>

using namespace std;

class ExpressionEvaluator
{
private:
	string  expression;
	const string operators;
	stack <int> operands;

	bool is_operator(char c)
	{
		if(operators.find(c) < 4)
			return 1;

		else return 0;
	}

	int eval_operator(char c)
	{
		int right, left;
		right = this->operands.top();
		this->operands.pop();

		left = this->operands.top();
		this->operands.pop();

		switch(c)
		{
		case '+':	return left + right;
		case '-':	return left - right;
		case '*':	return left * right;
		case '/':	
			{
				if(right != 0)
					return left / right;
				else
				{
					string expression;
					cout << " invalid denomentor" << endl;
					system("PAUSE");
					exit(1);
				}
			}
		}
	}

public:
	
	ExpressionEvaluator(string s):expression(s),operators("+-*/")
	{	}

	int value()
	{
		int val;
		istringstream tokens(expression);
		char c;
		while(tokens >> c )
		{
			if(is_operator(c))
			{
				val = eval_operator(c);
				cout << "pushing " << val<< endl;
				this->operands.push(val);
			}
			else
			{
				tokens.putback(c);
				int operands;
				tokens >> operands;
				cout << " pushing " << operands << endl;
				this->operands.push(operands);
			}
		}
		return val;

	}

};