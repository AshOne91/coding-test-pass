# 15. 동적 계획법
## 15-1. 동적 계획법 개념
작은 문제들을 해결하고, 이것들을 활용하여 전체 문제를 해결하는 방법
- 큰 문제를 작은 문제로 나누었을 때 동일한 작은 문제가 반복해서 등장해야 함
- 큰 문제의 해결책은 작은 문제의 해결책의 합으로 구성할 수 있어야 합니다.
작은 문제의 해결책의 합으로 큰 문제를 해결할 수 있는 구조를 *최적 부분 구조*라고 함
큰 문제를 나누었을 때 작은 문제가 여러 개 반복되는 문제를 *중복 부분 문제*라고 함

### 점화식 세우기와 동적 계획법
1. 문제를 해결하는 해가 이미 있다고 가정
2. 종료 조건을 설정
3. 과정 1, 2를 활용해 점화식을 세움
팩토리얼을 예시
#### 점화식 구현: 재귀 활용
1. 재귀 호출 자체를 쓰지 않는 법 -> 반복문
2. 재귀 호출의 횟수를 줄이는 법 -> 메모이제이션

### 재귀 호출의 횟수를 줄여주는 메모이제이션
#### 점화식 구현 : 재귀 + 메모이제이션 활용
- 점화식 작성(가정)
- 재귀 방식으로 풀어보기(반복)
- 동적 계획법으로 재귀 + 메모이제이션으로 구현(기억)
### 최장 증가 부분 수열
#### 부분 수열이란?
주어진 수열 중 일부를 뽑아 새로 만든 수열
순서는 바뀌지는 않음
#### 최장 증가 부분 수열이란?
오름차순을 유지하면서도 길이가 가장 긴 수열을 말함
#### LIS의 길이 동적 계획법으로 구하기
동적 계획법으로 LIS의 길이를 구해보기
- 숫자가 점점 증가함
- 원소 간의 전후 관계는 유지함

3으로 끝나는 LIS 길이는?
앞에서 찾은 특정 원소로 끝나는 LIS 길이 중 가장 큰 것에 1을 더하면 된다.
앞에서 찾은 숫자가 나보다 큰 숫자면 앞을 순회해서 dp+1
나보다 작은 숫자라면 1더해서 저장

#### 최장 공통 부분 수열
알겠어요! 좀 더 간단하게 설명할게요.

### LCS (최장 공통 부분 수열) 쉽게 설명:

두 개의 문자열이 있을 때, 그 안에서 **순서를 바꾸지 않고** 공통으로 나오는 가장 긴 부분 문자열을 찾는 문제입니다. 다만, 부분 문자열이 **연속적일 필요는 없어요**. 예를 들어, `AB`와 `AC`가 있을 때, 공통 부분 수열은 `A`입니다. (순서만 맞추면 되죠.)

### 예시
- 문자열 A: "ABCBDAB"
- 문자열 B: "BDCAB"

이때, **"BCAB"**가 두 문자열에서 공통으로 나오는 가장 긴 부분 수열입니다.

### 문제를 푸는 방법 (쉽게 말하면)

1. 각 문자를 하나씩 비교하면서, 일치하는 문자가 있으면 그 문자를 **LCS에 추가**합니다.
2. 두 문자열을 동시에 탐색하면서, 길이를 구해 나갑니다.
3. **동적 계획법(DP)**을 이용해, 이전에 계산한 값을 저장하고, 중복 계산을 피하면서 빠르게 결과를 도출합니다.

### 동적 계획법 (DP) 핵심

- `dp[i][j]`는 A의 앞에서부터 i번째 문자와 B의 앞에서부터 j번째 문자의 **최장 공통 부분 수열**의 길이를 저장하는 표입니다.
- 만약 두 문자가 같으면, 그 문자를 포함해서 LCS의 길이를 늘리고, 다르면 그때까지의 최댓값을 가져옵니다.

### 간단한 C++ 코드

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int LCS(string A, string B) {
    int m = A.length();
    int n = B.length();

    // DP 배열 만들기
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // LCS 계산
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            // 문자가 같으면 LCS 길이를 1 늘린다
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            // 다르면 이전 값 중 더 큰 값을 선택
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // 마지막 값이 최장 공통 부분 수열의 길이
    return dp[m][n];
}

int main() {
    string A = "ABCBDAB";
    string B = "BDCAB";

    cout << "최장 공통 부분 수열의 길이: " << LCS(A, B) << endl;
    return 0;
}
```

### 요약
1. 두 문자열을 비교하면서 공통으로 나오는 부분을 찾고,
2. 그 길이를 `dp` 배열에 저장하며, 중복 계산을 피하는 방법입니다.

이 방식으로 계산하면 **최장 공통 부분 수열**을 빠르고 효율적으로 구할 수 있어요!

알겠어요! **LIS(Longest Increasing Subsequence)**는 주어진 배열에서 **가장 긴 증가하는 부분 수열**을 찾는 문제입니다. 중요한 점은 **연속된 숫자가 아니어도 되고**, 순서대로 증가하는 숫자들을 찾아내는 것입니다.

### 예시
- 주어진 배열: `10 22 9 33 21 50 41 60 80`
- 이 배열에서 가장 긴 증가하는 부분 수열은 `10 22 33 50 60 80`입니다. (길이는 6)

### 문제 해결 아이디어
1. 각 숫자를 살펴보면서, 그 숫자가 이전에 나온 숫자들보다 더 큰지 비교해가며 증가하는 수열을 찾습니다.
2. 이때, 각 숫자에 대해 **이전에 나온 숫자들과 비교**하여 **가장 긴 증가하는 부분 수열의 길이**를 기록해 나갑니다.
3. **동적 계획법(DP)**을 사용하여 계산된 길이를 저장하고, 그 중 가장 큰 값을 찾습니다.

### LIS 문제를 푸는 방법

1. **DP 배열**을 만든다: `dp[i]`는 `i`번째 숫자까지 고려했을 때의 **가장 긴 증가하는 부분 수열의 길이**를 저장합니다.
2. **각 숫자를 비교**하여, 이전 숫자보다 더 작은 숫자를 만나면 그 숫자를 포함시켜 수열 길이를 갱신합니다.
3. 최종적으로 **가장 큰 길이**가 LIS의 길이가 됩니다.

### C++ 코드

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // for max()
using namespace std;

int LIS(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1);  // dp 배열 초기화 (최소 길이는 1)

    // dp 배열을 채워나가며 가장 긴 증가하는 부분 수열의 길이를 구한다
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {  // 증가하는 수열을 발견하면
                dp[i] = max(dp[i], dp[j] + 1);  // 길이를 갱신
            }
        }
    }

    // dp 배열에서 가장 큰 값이 LIS의 길이
    return *max_element(dp.begin(), dp.end());
}

int main() {
    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    cout << "가장 긴 증가하는 부분 수열의 길이: " << LIS(arr) << endl;
    return 0;
}
```

### 설명
1. **DP 배열**: `dp[i]`는 `arr[i]`까지의 가장 긴 증가하는 부분 수열의 길이를 저장합니다. 초기값은 모두 1로 시작합니다.
2. **두 개의 루프**: 
   - 첫 번째 루프(`i`)는 각 원소를 확인합니다.
   - 두 번째 루프(`j`)는 `i`보다 작은 인덱스의 원소들과 비교하여 증가하는 부분 수열을 찾습니다.
3. **최대 길이 구하기**: 마지막에는 `dp` 배열에서 가장 큰 값을 찾아 LIS의 길이를 구합니다.

### 결과
위 코드에서는 배열 `{10, 22, 9, 33, 21, 50, 41, 60, 80}`에 대해 가장 긴 증가하는 부분 수열의 길이를 계산하여 출력합니다.

**LIS의 길이: 6**

