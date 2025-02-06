#include <stack>
#include <unordered_map>
#include <string>

std::unordered_map<char, char> pair = { {')','('}, {']','['}, {'}','{'}};

bool isValid(std::string& s, int start)
{
	std::stack<char> stk;
	int sz = s.size();

	for (int i = 0; i < sz; ++i)
	{
		char ch = s[(start + i) % sz];

		if (pair.find(ch) != pair.end())
		{
			if (stk.empty() || stk.top() != pair[ch])
			{
				return false;
			}

			stk.pop();
		}
		else
		{
			stk.push(ch);
		}
	}

	return stk.empty();
}

int solution(std::string s)
{
	int answer = 0;
	int n = s.size();

	for (int i = 0; i < n; ++i)
	{
		answer += isValid(s, i);
	}

	return answer;
}