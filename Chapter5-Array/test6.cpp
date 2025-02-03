#include <vector>
#include <algorithm>

std::vector<int> solution(int N, std::vector<int> stages)
{
	std::vector<float> challenger(N + 1, 0.0);
	std::vector<float> fail(N + 1, 0.0);

	for (int i = 0; i < stages.size(); ++i)
	{
		for (int j = 1; j <= stages[i]; ++j)
		{
			challenger[j]++;
		}

		fail[stages[i]]++;
	}

	std::vector<std::pair<int, float>> failRatio(N);

	for (int i = 0; i < N; ++i)
	{
		failRatio[i].first = i + 1;

		if (challenger[i + 1] == 0)
		{
			failRatio[i].second = 0;
		}
		else
		{
			failRatio[i].second = fail[i + 1] / challenger[i + 1];
		}
	}

	std::sort(failRatio.begin(), failRatio.end(), [](const auto& left, const auto& right) {
		if (left.second == right.second)
		{
			return left.first < right.frist;
		}
		return left.second > right.second;
		});

	std::vector<int> answer;
	for (int i = 0; i < N; ++i)
	{
		answer.push_back(failRatio[i].first);
	}

	return answer;
}