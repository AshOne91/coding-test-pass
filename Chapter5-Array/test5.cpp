#include <vector>

std::vector<std::vector<int>> solution(std::vector<std::vector<int>> arr1, std::vector<std::vector<int>> arr2)
{
	std::vector<std::vector<int>> answer;
	answer.assign(arr1.size(), std::vector<int>(arr2[0].size(), 0));

	for (int i = 0; i < arr1.size(); ++i)
	{
		for (int j = 0; j < arr2[0].size(); ++j)
		{
			for (int k = 0; k < arr2.size(); ++k)
			{
				// M*K * K*N = M*N
				answer[i][j] += arr1[i][k] * arr2[k][j];
			}
		}
	}

	return answer;
}
