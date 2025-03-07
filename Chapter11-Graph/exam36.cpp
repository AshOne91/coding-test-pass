#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

unordered_map<char, vector<char>> adjList;
vector<char> result;
unordered_set<char> visited;

void dfs(char node)
{
	visited.insert(node);
	result.push_back(node);

	for (char neighbor : adjList[node])
	{
		if (visited.find(neighbor) == visited.end())
		{
			dfs(neighbor);
		}
	}
}

vector<char> solution(vector<pair<char, char>> graph, char start)
{
	for (auto& edge : graph)
	{
		char u = edge.first;
		char v = edge.second;
		adjList[u].push_back(v);
	}

	dfs(start);
	return result;
}