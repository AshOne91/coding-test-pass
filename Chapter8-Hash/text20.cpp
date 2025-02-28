#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
	unordered_map<string, int> ph;
	for (auto& str : participant)
	{
		ph[str]++;
	}

	for (auto& str : completion)
	{
		ph[str]--;
		if (ph[str] == 0)
		{
			ph.erase(str);
		}
	}

	return ph.begin()->first;
}