#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

unordered_map<int, vector<int>> adjList;
vector<int> result;

void bfs(int start)
{
	unordered_set<int> visited;
	queue<int> q;

	q.push(start);
	visited.insert(start);
	result.push_back(start);

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		for (int neighbor : adjList[node])
		{
			if (visited.find(neighbor) == visited.end())
			{
				q.push(neighbor);
				visited.insert(neighbor);
				result.push_back(neighbor);
			}
		}
	}
}

vector<int> solution(vector<pair<int, int>> graph, int start)
{
	for (auto& edge : graph)
	{
		int u = edge.first;
		int v = edge.second;
		adjList[u].push_back(v);
	}

	bfs(start);

	return result;
}