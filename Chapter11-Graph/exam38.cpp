// 인접리스트로 풀기
#include <vector>
#include <tuple>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

vector<int> solution(int start, int numNodes, vector<tuple<int, int, int>> edges)
{
	vector<vector<pair<int, int>>> adjList(numNodes);
	for (const auto& [from, to, weight] : edges)
	{
		adjList[from].emplace_back(to, weight);
	}

	vector<int> distances(numNodes, INF);
	distances[start] = 0;

	auto cmp = [](pair<int, int>& left, pair<int, int>& right)
		{
			return left.second > right.second;
		};

	priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
	pq.push({ 0, start });

	vector<bool> visited(numNodes, false);

	while (!pq.empty())
	{
		int currentDistance = pq.top().first;
		int currentNode = pq.top().second;
		pq.pop();

		if (visited[currentNode]) continue;
		visited[currentNode] = true;

		for (const auto& [neighbor, weight] : adjList[currentNode])
		{
			int newDistance = distances[currentNode] + weight;
			if (newDistance < distances[neighbor])
			{
				distances[neighbor] = newDistance;
				pq.push({ newDistance, neighbor });
			}
		}
	}

	return distances;
}