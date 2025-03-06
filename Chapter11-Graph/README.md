# 11. 그래프
## 11-1 그래프의 개념
노드와 간선을 이용한 비선형 데이터 구조
### 그래프 용어 정리
간선, 가중치, 정점
### 그래프의 특징과 종류
방향성, 가중치, 순환 특성에 따라 종류를 구분
### 흐름을 표현하는 방향성
방향 그래프, 무방향 그래프
### 흐름의 정도를 표현하는 가중치
데이터의 양 가중치, 가중치 그래프
### 시작과 끝의 연결 여부를 보는 순환
순환 그래프, 비순환 그래프
## 그래프 구현
노드, 간선, 방향, 가중치
### 인접 행렬 그래프 표현
### 인접 리스트 그래프 표현
[v, w]로 묶어서 vector에 넣기
```c++
#include <iostream>
#include <vector>
using namespace std;

struct nodeInfo
{
	int V;
	int W;
};

vector<vector<nodeInfo>> adjList;

void addEdge(int u, int v, int w)
{
	adjList[u].push_back({v, w});
}

int main()
{
	int N = 5;
	adjList.resize(N);

	addEdge(1, 2, 3);
	addEdge(2, 1, 6);
	addEdge(2, 3, 5);
	addEdge(3, 2, 1);
	addEdge(3, 4, 13);
	addEdge(4, 4, 9);
	addEdge(4, 1, 42);

	//printAdjList();

	return 0;
}
```

