// 배열 제어하기
#include<vector>
#include<algorithm>

std::vector<int> solution(std::vector<int> arr)
{
	std::sort(arr.begin(), arr.end(), [](const auto& left, const auto& right) {
		return left > right;
		});

	arr.erase(std::unique(arr.begin(), arr.end()), arr.end()); //unique는 new end를 반환(자료는 삭제되지 않음)

	return arr;
}