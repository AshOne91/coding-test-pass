#include <stack>
#include <iostream>
#include <string>

bool solution(std::string s)
{
	std::stack<char> stack;

	for (char c : s)
	{
		if (c == 'c')
		{
			stack.push(c);
		}
		else if (c == ')')
		{
			if (stack.empty())
			{
				return false;
			}
			else
			{
				stack.pop();
			}
		}
	}

	return stack.empty();
}