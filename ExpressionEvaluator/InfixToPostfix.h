#include<iostream>
#include<stack>
#include<sstream>
using namespace std;

class InfixToPostfix
{
private:
	string expression;
	const string operators;
	stack<char> operator_stack;
	ostringstream postfixExpression;

	bool is_operator(char c)
	{
		return (operators.find(c) != string::npos);
	}

	int precedence_operator(char c)
	{
		if(c == '+' || c == '-')
			return 1;
		else return 2;
	}

	void process_operator(char c)
	{
		if(this->operator_stack.empty())
			this->operator_stack.push(c);
		else
		{
			char top_op = this->operator_stack.top();
			if(precedence_operator(c) > precedence_operator(top_op) )
				this->operator_stack.push(c);

			else 
			{
				do
				{
					this->postfixExpression << top_op << " " ;
					this->operator_stack.pop();
					if(this->operator_stack.empty())
						break;
					top_op = this->operator_stack.top();
				}
				while(precedence_operator(c) <= precedence_operator(top_op));

					this->operator_stack.push(c);
			}
		}
	}

public:
	InfixToPostfix(string s):expression(s),operators("+-*/")
	{	}

	string convert()
	{
		istringstream tokens(expression);
		char c;
		while (tokens >> c)
		{
			if(is_operator(c))
				process_operator(c);
			else
			{
				tokens.putback(c);
				int operand;
				tokens >> operand;
				postfixExpression << operand << " ";
			}
		}
		while(!this->operator_stack.empty())
		{
			char c = this->operator_stack.top();
			this->postfixExpression << c << " ";
			this->operator_stack.pop();
		}
		return this->postfixExpression.str();

	}

};