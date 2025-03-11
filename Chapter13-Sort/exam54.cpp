#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
	vector<int> counts(26, 0);

	for (char c : s)
	{
		counts[c - 'a']++;
	}

	string sorted_str = "";
	for (int i = 0; i < 26; ++i)
	{
		sorted_str += string(counts[i], i + 'a');
	}

	return sorted_str;
}