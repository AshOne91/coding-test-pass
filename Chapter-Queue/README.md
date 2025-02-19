# 7. 큐
## 07-1 큐의 개념
선입선출 또는 FIFO이라고 함. 스택과 마찬가지로 큐도 삽입하는 연산을 푸시, 꺼내는 연산을 팝이라고 함
### 큐에서 데이터가 이동하는 과정 살펴보기
### 큐의 특성을 활용하는 분야
- 작업 대기열
- 이벤트 처리
### 큐의 ADT
### 큐 구현하기
```cpp
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue<int> q;

	q.push(10);
	q.push(20);
	q.push(30);
	cout << "Front: " << q.front() << endl;

	while (!q.empty())
	{
		cout << q.front() << "을 큐에서 삭제했습니다. " << endl;
		q.pop();
	}
	cout << "큐가 비었나요? " << (q.empty() ? "Yes" : "No") << endl;

	return 0;
}
```
