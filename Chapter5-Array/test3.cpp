#include <vector>
#include <set>

std::vector<int> solution(std::vector<int> numbers)
{
	std::set<int> uniqueNums;
	for (int i = 0; i < numbers.size() - 1; ++i)
	{
		for (int j = i + 1; j < numbers.size(); ++j)
		{
			uniqueNums.insert(numbers[i] + numbers[j]);
		}
	}

	std::vector<int> rtn(uniqueNums.begin(), uniqueNums.end());

	return rtn;
}

