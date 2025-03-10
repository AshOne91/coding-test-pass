# 8. 해시
## 08-1 해시의 개념
해시는 해시 함수를 사용해서 변환한 값을 인덱스로 삼아 키와 값을 저장해서 빠른 데이터 탐색을 제공하는 자료구조입니다. 해시는 키를 활용해 데이터 탐색을 빠르게 함
### 해시 자세히 알아보기
전화번호는 값, 값을 검색하기 위해 활용하는 정보는 키
### 해시의 특징
키 자체가 해시 함수에 의해 값이 있는 인덱스가 되므로 값을 찾기 위한 탐색 과정이 필요가 없음
해시 테이블은 키와 대응한 값이 저장되어 있는 공간이고, 해시 테이블의 각 데이터를 버킷이라고 부름
### 해시의 특성을 활용하는 분야
- 비밀번호 관리
- 데이터베이스 인덱싱
- 블록체인
## 08-2 해시 함수
unordered_map
### 해시 함수를 구현할 때 고려할 내용
충돌의 의미는 서로 다른 두 키에 대해 해싱 함수를 적용한 결과가 동일한 것을 의미
### 자주 사용하는 해시 함수 알아보기
#### 나눗셈 법
왜 충돌이 많이 발생할까?
나눗셈법의 해시 테이블 크기는 K
#### 곱셈법
#### 문자열 해싱
## 08-3 충돌 처리
### 체이닝으로 처리하기
해시 함수의 결괏값이 같으면 충돌
#### 해시 테이블 공간 활용성이 떨어짐
#### 검색 성능이 떨어짐
### 개방 주소법으로 처리하기
빈 버킷을 찾아 충돌값을 삽입
#### 선형 탐사 방식
빈 버킷을 찾을 때까지 일정한 간격으로 이동
#### 이중 해싱 방식

#### 추가 부록 해시코드 유도되는 법
# 문자열 해시 함수 유도 과정

## 1. 목표: 문자열을 하나의 숫자로 변환하기
우리는 문자열을 하나의 숫자로 변환하는 해시 함수를 만들고 싶다. 
이때, 다음 조건을 만족해야 한다.
- **같은 문자열이면 같은 해시 값**을 가져야 한다.
- **순서가 다르면 다른 해시 값**이 나와야 한다.
- **빠르게 계산할 수 있어야 한다.**

하지만 단순히 문자의 아스키 값(A=65, B=66, ...)을 더하는 방식은 
문자 순서를 구별하지 못하므로 적절하지 않다.

## 2. 위치를 반영하는 방법: 거듭제곱 사용
숫자를 표현할 때 각 자릿수를 고려하는 방법을 떠올려보자.
예를 들어, 숫자 `123`을 표현하는 방법은 다음과 같다.

\[
123 = 1 \times 10^2 + 2 \times 10^1 + 3 \times 10^0
\]

이를 문자열에도 적용해 보자. 문자열 `"abc"`를 숫자로 변환한다고 하면,

\[
H = c_1 p^2 + c_2 p^1 + c_3 p^0
\]

즉,
- 첫 번째 문자 `a`(=97)는 가장 중요한 자리 → \( 97 \times p^2 \)
- 두 번째 문자 `b`(=98)는 그다음 자리 → \( 98 \times p^1 \)
- 세 번째 문자 `c`(=99)는 가장 덜 중요한 자리 → \( 99 \times p^0 \)

이렇게 하면 문자열의 순서가 반영되므로 서로 다른 문자열이 다른 해시 값을 갖게 된다.

## 3. 효율적인 계산 방법: 점진적 업데이트
위 공식을 그대로 사용하면 매번 \( p^n \) 을 계산해야 해서 속도가 느려진다.
이를 방지하기 위해 **하나씩 추가하는 방식**으로 변환한다.

1. `"a"` 하나만 있을 때:
   \[
   H = 97
   \]
2. `"b"`를 추가하면:
   \[
   H = (97 \times p) + 98
   \]
3. `"c"`를 추가하면:
   \[
   H = ((97 \times p) + 98) \times p + 99
   \]

이를 일반화하면,

\[
H_n = H_{n-1} \times p + c_n
\]

이 방식은 **이전 해시 값에 문자를 추가하는 방식으로 빠르게 업데이트**할 수 있다.

## 4. 숫자가 너무 커지는 문제 해결: 모듈러 연산
긴 문자열을 해싱하면 숫자가 너무 커질 수 있다. 이를 방지하기 위해 **모듈러 연산**을 적용한다.

\[
H = (H \times p + c) \mod m
\]

- **적당히 큰 소수 \( m \)** 을 사용하면 해시 충돌을 줄일 수 있다.
- 계산 과정에서 값이 일정 범위를 유지하므로 **연산 속도도 빨라진다.**

## 5. 최종 공식
이제 최종적으로 우리가 사용할 해시 함수는 다음과 같다.

\[
\text{hash\_value} = (\text{hash\_value} \times p + c) \mod m
\]

이 공식은 **문자열을 하나의 숫자로 변환하면서, 순서와 내용을 반영하고, 빠르게 계산할 수 있도록 해준다.**
