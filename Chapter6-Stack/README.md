# 6 스택
## 06-1 스택 개념
먼저 들어간 것이 마지막에 나오는 규칙
### 스택의 동작 원리 이해하기
### 06-2 스택의 정의
ADT로 스택 알아보기
#### 스택의 ADT
푸시, 팝, 가득 찼는지 확인, 비었는지, 가장 최근 데이터 확인
#### 스택 구현하기
```c++
#include <iostream>
#include <stack>

using namespace std;

int main()W
{
	stack<int> st;
	
	st.push(10);
	st.push(20);
	st.push(30);

	while(!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;

	return 0;
}
```
