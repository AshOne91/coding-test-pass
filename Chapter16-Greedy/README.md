# 그리디
## 16-1 그리디 개념
탐욕스러운, 욕심이 많은이라는 뜻
지역 최적해를 추구한다.
그리디 알고리즘으로 풀어보자
### 그리디 알고리즘으로 거스름돈 내어주기
거스름돈 주기는 아님
### 그리디 알고리즘이 최적해를 보장하려면?
- 최적 부분 구조 : 부분해를 푸는 과정이 최적해를 구하는 과정과 일치
- 그리디 선택 속성 : 선택 과정이 다른 과정에 영향을 주지 않음
## 16-2 최소 신장 트리
### 신장 트리란?
신장 트리는 모든 정점이 간선으로 연결되어 있고 간선 개수가 정점 개수보다 하나 적은 그래프
### 최소 신장 트리란?
신장 트리 중 간선의 가중치 합이 최소면 최소 신장 트리(minimum spanning tree)MST
#### 최소 신장 트리를 구하는 그리디 알고리즘
##### 프림 알고리즘으로 최소 신장 트리 구하기
**최소신장트리(MST, Minimum Spanning Tree)**는 그래프에서 **모든 노드를 연결하는 최소 비용의 간선들로 구성된 트리**입니다. 이때 각 간선의 비용은 주어지며, **프림 알고리즘**은 MST를 찾는 방법 중 하나입니다.

### 프림 알고리즘
프림 알고리즘은 **시작점에서부터 하나씩 간선을 추가**하여 최소신장트리를 구하는 방식입니다. 그리디 알고리즘의 일종으로, **현재까지 연결된 노드와 인접한 노드들 중 가장 적은 비용의 간선을 선택**하는 방식입니다.

### 기본 아이디어
1. **시작 노드를 정한다**.
2. **현재 트리에 연결된 노드들**에서 **가장 적은 비용**을 가진 간선을 선택하여 트리에 추가한다.
3. 모든 노드가 연결될 때까지 이 과정을 반복한다.

### 프림 알고리즘의 단계
1. **시작 노드를 선택**하고, 그 노드를 트리에 포함시킵니다.
2. 현재 트리에 연결된 노드들 중에서 가장 비용이 적은 간선을 선택하고, 그 간선에 연결된 노드를 트리에 포함시킵니다.
3. 이 과정을 모든 노드가 트리에 포함될 때까지 반복합니다.

### C++ 코드 예시

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> pii; // 비용, 노드 번호를 저장하기 위한 pair

// 프림 알고리즘을 이용한 최소 신장 트리
int prim(int n, vector<vector<pii>>& graph) {
    vector<int> minCost(n, INT_MAX);  // 각 노드로 가는 최소 비용
    vector<bool> inMST(n, false);     // MST에 포함된 노드 여부
    priority_queue<pii, vector<pii>, greater<pii>> pq; // (비용, 노드) 형태로 최소 힙을 사용

    // 시작 노드를 0으로 설정
    minCost[0] = 0;
    pq.push({0, 0}); // (비용, 노드) -> (0, 0)부터 시작

    int totalCost = 0;

    while (!pq.empty()) {
        int u = pq.top().second; // 현재 노드 u
        int cost = pq.top().first; // 현재 비용
        pq.pop();

        if (inMST[u]) continue; // 이미 MST에 포함되었으면 넘어감
        inMST[u] = true; // MST에 추가

        totalCost += cost; // 해당 간선 비용을 총합에 더함

        // 현재 노드 u와 연결된 모든 간선들을 확인
        for (auto& edge : graph[u]) {
            int v = edge.first; // 연결된 노드
            int edgeCost = edge.second; // 간선의 비용

            // 아직 MST에 포함되지 않았고, 비용이 더 적으면 갱신
            if (!inMST[v] && edgeCost < minCost[v]) {
                minCost[v] = edgeCost;
                pq.push({edgeCost, v}); // 새로운 간선(비용, 노드)을 우선순위 큐에 추가
            }
        }
    }

    return totalCost; // MST의 총 비용 반환
}

int main() {
    int n = 5; // 노드 개수
    vector<vector<pii>> graph(n); // 그래프 인접 리스트 (비용, 노드)
    
    // 그래프 간선 추가 (각 간선: {노드1, 노드2, 비용})
    graph[0].push_back({1, 2});
    graph[0].push_back({3, 6});
    graph[1].push_back({0, 2});
    graph[1].push_back({2, 3});
    graph[1].push_back({3, 8});
    graph[2].push_back({1, 3});
    graph[2].push_back({3, 5});
    graph[3].push_back({0, 6});
    graph[3].push_back({1, 8});
    graph[3].push_back({2, 5});

    cout << "최소 신장 트리의 비용: " << prim(n, graph) << endl;
    return 0;
}
```

### 설명
1. **graph**: 인접 리스트 형식으로 그래프를 나타냅니다. 각 간선은 `{노드, 비용}` 형식으로 저장됩니다.
2. **priority_queue**: 우선순위 큐를 사용하여, 항상 **최소 비용의 간선**을 먼저 선택합니다. 이 큐는 비용이 작은 간선부터 뽑혀 나옵니다.
3. **minCost**: 각 노드로 가는 최소 비용을 저장합니다. 초기에는 모든 비용을 매우 큰 값(`INT_MAX`)으로 설정하고, 시작 노드는 0으로 설정합니다.
4. **inMST**: 해당 노드가 최소 신장 트리에 포함되었는지 여부를 기록합니다.
5. **while loop**: 큐에서 가장 작은 비용의 노드를 꺼내어, 그 노드와 연결된 간선들을 검사하면서 최소 신장 트리를 확장해 나갑니다.

### 결과
위 예시에서 그래프는 다음과 같습니다:
- 0번 노드와 1번 노드 사이의 간선 비용은 2
- 0번 노드와 3번 노드 사이의 간선 비용은 6
- 등등...

최소 신장 트리의 비용은 **16**입니다.

#### 크루스칼 알고리즘으로 최소 신장 트리 구하기
### 🚀 크루스칼 알고리즘을 아주 쉽게 설명해볼게요!

---

### **📌 크루스칼 알고리즘이란?**
- **최소 신장 트리(MST, Minimum Spanning Tree)**를 구하는 방법 중 하나입니다.
- 모든 노드를 연결하면서, **가장 적은 비용의 간선들만 선택**하는 방식입니다.
- **그리디 알고리즘**을 기반으로 합니다.

---

### **📌 크루스칼 알고리즘의 핵심 아이디어**
1. **모든 간선을 비용 기준으로 정렬**한다.
2. **가장 적은 비용의 간선부터 선택**하면서 트리를 만든다.
3. **사이클이 생기지 않도록** 주의하면서 간선을 추가한다.  
   → 이를 위해 **유니온-파인드(Union-Find, 서로소 집합)** 자료구조를 사용합니다.

---

### **📌 크루스칼 알고리즘을 쉽게 이해하는 예시**
#### **🌳 예제 그래프**
- 노드: {A, B, C, D, E}
- 간선과 비용:  
  ```
  A - B (2)
  A - C (3)
  B - C (1)
  B - D (4)
  C - D (5)
  C - E (6)
  ```
- 크루스칼 알고리즘을 적용하면 **가장 적은 비용**의 간선부터 선택하여 최소 신장 트리를 만듭니다.

---

### **📌 C++ 코드 (간단하고 쉬운 버전!)**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 간선을 저장할 구조체
struct Edge {
    int u, v, weight;
};

// 부모 찾기 (Find 함수)
int findParent(vector<int>& parent, int node) {
    if (parent[node] == node) return node;
    return parent[node] = findParent(parent, parent[node]);  // 경로 압축
}

// 두 집합을 합치는 함수 (Union 함수)
void unionNodes(vector<int>& parent, vector<int>& rank, int a, int b) {
    int rootA = findParent(parent, a);
    int rootB = findParent(parent, b);

    if (rootA != rootB) {
        if (rank[rootA] > rank[rootB]) parent[rootB] = rootA;
        else if (rank[rootA] < rank[rootB]) parent[rootA] = rootB;
        else {
            parent[rootB] = rootA;
            rank[rootA]++;
        }
    }
}

// 크루스칼 알고리즘 함수
int kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    vector<int> parent(n);  
    vector<int> rank(n, 0);
    
    for (int i = 0; i < n; i++) parent[i] = i; // 부모를 자기 자신으로 초기화

    int totalCost = 0;
    int edgeCount = 0;

    for (Edge edge : edges) {
        if (findParent(parent, edge.u) != findParent(parent, edge.v)) {
            unionNodes(parent, rank, edge.u, edge.v);
            totalCost += edge.weight;
            edgeCount++;
            
            if (edgeCount == n - 1) break; // MST 완성
        }
    }

    return totalCost;
}

int main() {
    int n = 5; // 노드 개수
    vector<Edge> edges = {
        {0, 1, 2}, {0, 2, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 5}, {2, 4, 6}
    };

    cout << "최소 신장 트리의 비용: " << kruskal(n, edges) << endl;
    return 0;
}
```

---

### **📌 코드 설명**
1. **`Edge` 구조체**  
   → `u`, `v`는 연결된 두 노드, `weight`는 가중치(비용)

2. **`findParent` (Find 함수, 경로 압축)**
   → 현재 노드의 부모(루트)를 찾아주는 함수 (최적화를 위해 경로 압축 사용)

3. **`unionNodes` (Union 함수)**
   → 두 개의 노드를 같은 집합으로 합치는 함수 (랭크 기반 최적화)

4. **`kruskal` (크루스칼 알고리즘)**
   - ① **간선을 비용 기준으로 정렬**
   - ② **가장 적은 비용부터 선택 (사이클 방지)**
   - ③ **n-1개의 간선을 선택하면 종료**

---

### **📌 실행 결과**
```
최소 신장 트리의 비용: 12
```

---

### **📌 크루스칼 vs 프림 차이점**
| 알고리즘 | 동작 방식 | 사용 자료구조 | 시간 복잡도 |
|----------|----------|--------------|--------------|
| **프림(Prim)** | 노드 중심 (가장 작은 간선 선택) | 우선순위 큐 | O(E log V) |
| **크루스칼(Kruskal)** | 간선 중심 (가장 작은 간선부터 연결) | 정렬 + 유니온-파인드 | O(E log E) |

- **프림 알고리즘**: 한 정점에서 시작하여 **하나씩 추가**하는 방식  
- **크루스칼 알고리즘**: **간선들을 정렬**한 후, 작은 것부터 추가하는 방식

---

### **📌 요약**
✅ 크루스칼 알고리즘은 **가장 비용이 적은 간선부터 선택**하는 방식이다.  
✅ **유니온-파인드(Union-Find)**를 사용하여 **사이클을 방지**한다.  
✅ **정렬과 유니온-파인드**를 활용하므로 **O(E log E)**의 시간 복잡도를 가진다.  
✅ **그래프의 간선 개수가 적은 경우** 크루스칼이 유리하다.  

---

이제 크루스칼 알고리즘이 쉬워졌죠? 😆 🚀

## 16-3. 배낭 문제
무게를 초과하지 않으면서 담은 가치를 최대로 하는 문제를 배낭 문제라고 함
### 짐을 쪼갤 수 있는 부분 배낭 문제
가치가 높은 짐을 최대한 많이 넣는 그리디 알고리즘
### 짐을 쪼갤 수 없는 0/1 배낭 문제
동적 계획법으로 접근해야함