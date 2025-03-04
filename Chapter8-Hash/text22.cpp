#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<string, int> phoneBook;

bool isPrefix(const string& phoneNumber)
{
	string prefix = "";
	for (char digit : phoneNumber)
	{
		prefix += digit;

		if (phoneBook.find(prefix) != phoneBook.end() && prefix != phoneNumber)
		{
			return true;
		}
	}
}

bool solution(vector<string> phoneNumbers)
{
	for (const string& phoneNumber : phoneNumbers)
	{
		phoneBook[phoneNumber] = 1;
	}

	for (const string& phoneNumber : phoneNumbers)
	{
		if (isPrefix(phoneNumber))
		{
			return false;
		}
	}
	return true;
}