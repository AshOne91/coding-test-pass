#include <limits>   // 숫자의 최댓값을 다루는 라이브러리
#include <tuple>    // 튜플을 다루는 라이브러리
#include <vector>   // 벡터를 다루는 라이브러리

using namespace std;

// 무한대 값 설정 (너무 큰 숫자를 의미)
const int INF = numeric_limits<int>::max();

// solution 함수: 최단 경로를 구하는 함수
vector<int> solution(int num_vertices, vector<tuple<int, int, int>> edges, int source)
{
    // 그래프를 2차원 벡터로 만들기 (각 정점에 연결된 다른 정점들과 가중치 저장)
    vector<vector<pair<int, int>>> graph(num_vertices);

    // edges로 주어진 정보를 바탕으로 그래프 만들기
    for (auto& edge : edges)
    {
        int from, to, weight;
        tie(from, to, weight) = edge;  // edge에서 from, to, weight 값을 뽑아서 사용
        graph[from].emplace_back(to, weight);  // 'from' 정점에서 'to' 정점으로 가는 가중치 'weight'를 저장
    }

    // 각 정점까지의 최단 거리 값을 저장할 벡터 (처음에는 모두 무한대(INF)로 설정)
    vector<int> distance(num_vertices, INF);
    distance[source] = 0;  // 출발 정점의 거리는 0

    // 벨만-포드 알고리즘 핵심: 모든 간선을 'num_vertices - 1'번씩 확인하며 거리 갱신
    for (int i = 0; i < num_vertices - 1; ++i)
    {
        for (int u = 0; u < num_vertices; ++u)  // u: 출발 정점
        {
            for (const auto& [v, weight] : graph[u])  // v: 도착 정점, weight: 간선의 가중치
            {
                // 출발 정점 u를 거쳐서 도착 정점 v로 가는 거리 계산
                if (distance[u] + weight < distance[v])
                {
                    distance[v] = distance[u] + weight;  // 최단 거리 갱신
                }
            }
        }
    }

    // 음수 사이클이 있는지 확인하기
    for (int u = 0; u < num_vertices; ++u)
    {
        for (const auto& [v, weight] : graph[u])
        {
            if (distance[u] + weight < distance[v])  // 거리 갱신이 가능하면 음수 사이클이 있다는 의미
            {
                return vector<int>(1, -1);  // 음수 사이클이 있으면 -1을 반환
            }
        }
    }

    return distance;  // 최단 거리 배열 반환
}
