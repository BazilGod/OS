#include "stdafx.h"
#include <iostream>
#include <stack>
#include <string>

bool is_correct(const std::string&);

int main()
{
	std::string str;
	std::cin >> str ;

	std::cout << (is_correct(str) ? "Yes" : "No") << std::endl;
}

bool is_correct(const std::string& str)
{
	std::stack< char > stack;

	for (int i = 0; i < (int)str.length(); ++i)
	{
		if (str[i] == '(' )
		{
			stack.push(str[i]);
		}
		else if (str[i] == ')' )
		{
			if
				(
					stack.empty()
					|| ((str[i] == ')') ^ (stack.top() == '('))
					
					)
			{
				return false;
			}

			stack.pop();
		}
	}
	return stack.empty();
}