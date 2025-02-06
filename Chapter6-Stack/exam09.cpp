#include <stack>
#include <string>

std::string solution(int decimal)
{
	if (decimal == 0)
	{
		return "0";
	}

	std::stack<int> stack;
	while (decimal > 0)
	{
		stack.push(decimal % 2);
		decimal /= 2;
	}

	std::string binary = "";
	while (!stack.empty())
	{
		binary += std::to_string(stack.top());
		stack.pop();
	}

	return binary;
}