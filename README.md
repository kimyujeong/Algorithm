# Algorithm

## 해시
-	String과 같이 자료구조가 돋보이는 문제

## 이분탐색
-	최대값, 최솟값을 구하는 탐색 문제

## Multiset
-	중복을 허용하는 set 자료구조
-	Insert의 return 값이 삽입한 원소 k의 위치를 가리키는 반복자
``` c++
	multiset<int>::iterator iter;
	    for(iter = ms.begin(); iter != ms.end(); iter++){
		cout << *iter << " " ;
	    }
	    cout << endl;
	cout << "ms.count(11) : " << ms.count(11) << endl << endl;
	
	q.erase(--q.end()) -> 마지막 원소 지우기 가능
```

## 자료구조형::iterator iter;
-	set, map 같은 자료구조에서 유용해보임
-	iter 자체는 원소의 주소, *iter가 해당 값

## Upper_bound, Lower_bound
-	이분탐색 기반
-	원소들이 반드시 정렬되어 있어야 한다.
-	반복자를 return

``` c++
	#include <algorithm>
	사용) upper/lower_bound(찾으려는 값)
	Upper_bound: 찾으려는 값을 초과하는 값 ( “초과” )
	Lower_bound: 찾으려는 값 ( “이상” )
	Upper-lower == 0  =>  원소가 없다
```

## String – Find()
-	Str.find(문자열)
-	찾으려는 문자열이 있으면 인덱스 반환
-	없으면 -1 반환

## String – str.substr(시작, 갯수)
-	Str의 a번째부터 b개만큼

## String - str.erase(시작, 갯수)
* (시작)부터 (갯수)만큼 삭제

## String - getline(cin,str)
* 공백까지 입력받음
* #include < string >
	
## String - 소문자로 변경(transform/tolower)
``` c++
// transform : #include <algorithm>
// tolower : #include <ctype.h>

transform(str.begin(), str.end(), str.begin(), (int(*)(int))tolower);

// tolower 함수가 ambiguous하기 때문에 명확하게 인자를 캐스팅해야 함
```

## DFS 
- 그래프에서 아래로 내려갈 수 있을 때까지 갔다가 막히면 되돌아와서 다시 내려가는 탐색 방법
## BFS 
– 그래프에서 한 노드에서 인접한 노드를 다 살핀 후 인접한 노드의 인접한 노드를 같은 방식으로 살피는 탐색 방법

## Max_element

``` c++
	#include <algorithm>
	Int max = *max_element(a.begin(),a.end());
```

## LCS (비연속적 최장 공통 부분 문자열)

```c++

if(A[i-1] == B[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
    
// LCS인 실제 단어를 찾기 위해서는
// 맨 오른쪽 아래부터 대각선을 따라 왼쪽 위로 이동
// 오른쪽에서 왼쪽으로 가면서 자신과 같은 숫자일 때까지만 이동하고
// 왼쪽과 위가 모두 자기와 다르고
// 그 위치에서 왼쪽 대각선이 (자기-1)인지 확인하고
// 대각선 위치로 올라가서 반복

```
    
## Segment Tree

* 구간 합을 구할 때 사용하는 알고리즘

```c++

// Tree Size
int tree_height = (int)ceil(log2(n)); // #include <cmath>
int tree_size = (1 << (tree_height + 1));

```

```c++

// 세그먼트 트리 생성
long long make_segmentTree(int node, int start, int end)

// 세그먼트 트리 연산
long long mul(int node, int start, int end, int left, int right)

// 세그먼트 트리 값 변경
long long update(int node, int start, int end, int index, long long num)

```


 
# 틀린 문제

## 백준 14889 – 스타트와 링크
-	백트래킹 문제
-	n/2로 나누는 아이디어를 생각하지 못함
-	for문을 여러 개 비효율적으로 사용하여 시간초과
-	시간초과가 나지 않으려면 중복탐색을 하지 않도록 함수에 시작 index를 함께 넘겨주어야함 
-	void go(int idx, int cnt)
-	n/2개를 각각 저장하는 아이디어가 어려웠는데, check[]배열에 탐색한 노드를 저장하고 n까지 for문을 돌면서 check[] 값에 따라 두개의 배열에 나눠 저장하면 해결됨
-	재귀 호출 후에는 check[] 값을 다시 false로 바꾸어주기

## 백준 9663 – N-Queen
-	백트래킹 문제
-	N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 문제. 퀸의 이동은 직선 방향, 대각선 방향이 가능
-	짜여진 알고리즘을 보고도 구현 원리를 이해하기 어려웠음
-	각 행 또는 열에는 퀸이 오직 하나만 올 수 있다는 점이 중요
-	재귀적으로 호출하며 아래, 오른쪽 대각선, 왼쪽 대각선을 모두 제외시키며 다음 행으로 이동
-	N이 주어졌을 때, 각 행마다 하나의 퀸이 존재할 수 있는데 행에 둘 수 있는 자리가 없다면 다음 재귀로 이동
-	cnt==n 마다 경우의 수를 ++

## 백준 2580 – 스도쿠
-	백트래킹 문제
-	기존의 백트래킹 문제와는 접근 방식에서 조금 다른 점이 있었음
-	문제 접근부터 감을 못잡았던 문제
-	스도쿠 배열을 입력받으며 0인(=알아내야하는 수) 개수를 변수(cnt)에 저장하고, 벡터(v)에 넣어줌
-	백트래킹을 할 때 입력받은 수가 0인 수의 x좌표와 y좌표를 저장한 벡터 v에 값을 1~9까지 넣어보면서 check함수를 통해 유효성 검사를 수행
-	check함수에서는 행과 열에서 같은 수가 존재하는지, 같은 정사각형 범위 내에 같은 수가 존재하는지 검사
-	check함수를 통한 유효성 검사에 통과한다면 다음 백트래킹으로 넘어감
-	이 때, flag를 통해 벡터 v의 모든 검사를 맞췄다는 true를 return 받으면 함수 종료

## 백준 2579 – 계단 오르기
-	DP
-	2차원 배열을 사용한 DP - 연속으로 3개의 계단을 밟으면 안된다는 조건 때문
-	dp[i][0] : i-1번째 계단을 밟지 않은 i번째 계단까지의 최댓값 / max(dp[i - 2][0], dp[i - 2][1]) + v[i];
-	dp[i][1] : i-1번째 계단을 밟은 i번째 계단까지의 최댓값 / dp[i - 1][0] + v[i];

## 백준 1912 – 연속합
-	DP
-	알고리즘을 집중해서 생각해내지 못함
-	max함수로 간단하게 해결할 수 있는 코드였는데 if문으로 어지럽게 정리해서 나조차도 알아보기 힘들었음
-	연속하는게 최대값인지, 끊고 새로 시작하는게 최대값인지.
-	max( dp[index-1] + cost[index] , cost[index] )

## 백준 2225 – 합분해
-	DP
-	빠르게 식을 전개하고 그 안에서 규칙을 찾아 점화식을 빠르게 찾는 스킬이 필요할 것 같음
-	dp 배열의 정의를 빠르게 생각해내야 함
-	dp[n][k] = 정수 n을 n보다 작거나 같은 k개의 정수로 만들 수 있는 경우의 수
-	이 경우에는 식을 전개했을 때, dp[n][j] = dp[n-1][k] + dp[n][k-1] 이라는 식이 성립함
-	문제의 출력으로 %1000000000을 구해야하는데, 수가 커지더라도 정상적인 출력을 하기 위해서는 미리 dp[n][k]를 저장할 때 %mod의 상태로 값을 저장하는 것이 좋음

## 백준 11053 – 가장 긴 증가하는 부분 수열
-	DP
-	LIS / Longest Increasing Subsequence
-	알고리즘을 생각해내기 어려웠음
-	처음에 for문을 돌려 cnt++ 하는 방향에서 벗어나지 못했음
-	dp[i]: A[i]를 마지막으로 하는 가장 긴 증가하는 부분 수열의 길이
-	A[i]:  10 20 10 30 20 50
-	dp[i]: 1  2  1  3  2  4

## 백준 13398 – 연속합2
-	DP
-	알고리즘에 거의 근접했으나 한번 막혀서 포기한 문제 ..
-	dp 배열의 정의를 2차원으로 접근한 것은 좋았으나, 정의 부분에서 잘못됨
-	dp[i][0]: 1개를 제거하지 않고 i번째까지의 가장 큰 연속합
-	dp[i][0] = max(dp[i-1][0]+v[i], v[i])
-	dp[i][1]: 1개를 제거하고 i번째까지의 가장 큰 연속합
-	dp[i][1] = max(dp[i-1][0], dp[i-1][1]+v[i]) // max(현재 값 삭제, 이전 값 삭제했을 때)

## 백준 17404 – RGB거리 2
-	DP
-	RGB 거리 1 문제와 달리 첫번째 색과 마지막 색이 달라야한다는 조건을 해결하기 어려웠음
-	첫번째 색을 먼저 정한채로 마지막 색에서 첫번째 색을 제외하고 min을 찾으면 됨
-	1. 매우 큰 수를 res에 임시로 저장
-	2. 첫번째 수를 RGB 중 하나로 지정한채로 문제 풀이
-	3. RGB의 각각의 경우는 이전의 자신의 경우를 제외한 두가지 색으로 칠했을 때의 min
-	4. 첫번째 수를 지정한 RGB를 제외하고 두가지 경우중 더 작은 값을 찾는다.

## 백준 1063 – 킹
-	시뮬레이션
-	조건을 꼼꼼히 확인하지 못했음
-	1. 킹의 이동이 범위를 벗어나는지 확인
-	2. 돌멩이와 부딪히는지 확인
-	3. 돌멩이와 부딪힐 시, 돌멩이 또한 이동이 범위를 벗어나는지 확인

## 백준 20055 – 컨베이어 벨트 위의 로봇
-	시뮬레이션
-	2020 하반기 삼성 SW 역량테스트
-	문제 이해하다 시간 지난 문제 ..
-	결국 컨베이어 벨트는 벨트대로 따로 움직이고, 로봇은 스스로 움직인다는 말이 로봇도 따로 자기가 움직인다는 뜻
-	컨베이어 그림 벨트는 옆면에서 바라본 것 = 아래 칸에는 로봇이 있을 수 없다 !
-	문제를 이해하기 보다는 글을 코드로 바로 옮기는 것이 맞는 문제
-	n번째(i=n-1) 칸에는 어떤 경우든 로봇이 있을 수 X
-	회전 문제를 만나면 무조건 deque 자료형을 쓰자!
```c++
	void rotate() {
		dq.push_front(dq.back());
		dq.pop_back();
	}
```

## 백준 9251 – LCS
-	DP
-	LCS(Longest Common Subsequence, 최장 공통 부분 수열): 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제
-	1. 두 단어 중 하나 고정
-	2. 고정되지 않은 단어를 첫 글자부터 차례차례 고정된 단어와 비교를 하는데 글자가 일치하면 그전의 결과값 +1, 일치하지 않는다면 그 전 결과값 중 큰 값을 넣어줌

## 백준 12865 – 평범한 배낭
-	DP
-	dp[i][j]: i번째 물건까지 고려했고, 가방에 넣은 물건들의 무게가 j일 때 최대 가치합
-	i~n번째 물건까지 순회하며 가방에 담는다.
i번째 물건을 가방에 넣지 않는 경우: dp[i][j] = dp[i-1][j]
i번째 물건을 가방에 넣는 경우: dp[i][j] = dp[i-1][j-w[i]] + v[i]

## 백준 1644 – 소수의 연속합
-	에라토스테네스의 체
-	투포인터
-	시간초과 문제 – bool 타입의 prime 배열을 사용해서 해결
-	투포인터 알고리즘은 이전 것과 유사하고 어려운 것이 없었음
-	에라토스테네스의 체
```c++	
	const int s = 4000005;
	vector<int>arr;
	bool prime[s + 3];
	memset(prime, true, sizeof(prime));
		prime[1] = false;
		for (int i = 1; i <= s; i++) {
			if (prime[i] == true) {
				for (int k = 2; i*k <= s; k++) {
					prime[i * k] = false;
				}
			}
		}
```

## 백준 2110 – 공유기 설치
-	이분탐색
-	이분탐색 응용 문제는 처음이라서 알고리즘에 익숙치 않았음
-	mid: 가장 인접한 두 공유기 사이의 최대 거리
-	if (v[i] - last >= mid)  cnt++;
-	cnt>=c : 여유가 있다! x보다 짧은 거리는 볼 필요 없이 거리를 늘려 최댓값 확인!

## 백준 6236 – 용돈 관리
-	이분탐색
-	문제를 똑바로 읽자..!
-	통장에서 인출해야 할 최소 금액 K(=mid)는 무조건 i번째 날에 이용할 금액보다 커야함
-	그렇지 않고서는 돈을 몇 번을 인출하더라도 i번째 날을 보낼 수 없게 됨

## 백준 1300 - K번째 수
-	이분탐색
-	꼭 다시 풀어보기!!!!
-	벡터에 넣고 sort해서 출력하면 시간 초과, 메모리 초과
-	k번째 숫자를 찾자 -> 임의의 숫자 m을 골라서 k번째 숫자인지 판단해보자!
-	m보다 작은 숫자의 개수를 바르게 구하기 -> 이분탐색
-	A[i][j]에서 i행에 속한 숫자들은 i*j이므로 모두 i의 배수
-	min(mid/i, N)이 i번째 행에서 mid보다 작은(=임의의 m보다 작은) 숫자들의 개수
		- i행의 숫자들 중 m보다 작거나 같은 숫자는 (i*j <= m)를 만족하는 j의 개수이고, 이는 i*1, i*2, …, i*j이므로 m/i와 같은 값이 됨
		- cnt는 N보다 클 수 없음
-	cnt가 찾고자 하는 k일 경우에도 가장 최적의, 가장 작은 mid값을 찾아내야함
-	중복되는 숫자들이 있을 경우 가장 왼쪽의 lower_bound가 답이기 때문
- 	https://www.acmicpc.net/board/view/37110
-	https://www.acmicpc.net/board/view/12846

## 백준 2156 – 포도주 시식
-	DP
-	3번을 연속으로 마실 수 없다 / 포도주는 모두 양수의 양 / 최대로 마실 수 있는 양
-	2차원 배열을 이용하여 계산할 경우에는 예를 들어 O X X O 로 최대인 경우는 구하지 못한다.
-	X : dp[i-1]
-	X O O : dp[i - 3] + v[i] + v[i - 1]
-	X O : dp[i - 2] + v[i]
-	dp[i] = max(max(dp[i - 1], dp[i - 2] + v[i]), dp[i - 3] + v[i] + v[i - 1])

## 백준 19949 – 영재의 시험
-	백트래킹
-	처음에 ‘3개 연속’에 집착하여 DP로 풀 수 있으리라 생각하였지만, 시간 복잡도가 1억을 넘어가지 않음
-	시간 복잡도가 O(5^10)=약 O(1000만)이므로 브루트포스도 가능은 함 -> 10중 for문으로 ,,
-	백트래킹으로 3개 연속 같은 답이 나오지 않도록 검사하여 ans배열에 저장하여 해결

## 백준 2980 – 도로와 신호등
-	시뮬레이션
-	꼭 다시 풀어보기
-	Distance 및 time을 하나씩 증가시키지 않고 무조건 한 블록에 이동하려해서 풀이가 어려웠음
-	1. Distance 위치에 신호등이 있다면
-	- 신호등의 주기 계산
-	- 현재 빨간불인지 초록불인지 확인
-	- 신호등의 빨간불 지속시간 – (현재시간 % 해당 신호등의 주기)
-	- 가 0보다 작으면 현재 초록불 -> 그대로 distance++, time++
-	- 가 0보다 크면 현재 빨간불 -> 남은 시간을 time에 더해주기
-	2. Distance 위치에 신호등이 없다면
-	- distance++, time++ (그대로 그냥 지나감)

## 백준 7662 – 이중 우선순위 큐
-	우선순위 큐 (min heap, max heap)
-	2개의 힙을 이용하는 방식까지는 생각하였으나, 나아가서 한쪽만 삭제하면 다음 순서에서 순서가 바뀔 경우 같은 수를 삭제할 수 있다는 것을 간과함
-	삭제하려는 수가 반대 힙의 top일 수도 있음
-	Visited 배열을 선언하여 이미 삭제한 수라면 pop시켜주는 과정이 필요함

## 백준 1477 – 휴게소 세우기
-	이분 탐색
-	우선순위 큐의 방법으로 푸는 방법에만 집착했는데, 굳이 우선순위 큐 자료구조를 쓰지 않고 벡터 자료구조로도 해결이 가능한 문제
-	휴게소를 세우는 간격을 이분탐색하면 된다
-	이분탐색을 하여 최솟값을 구하는 방향으로

## 백준 13975 – 파일 합치기 3
-	우선순위 큐
-	모든 파일에 대해서 가장 크기가 작은 두 파일들을 계속해서 합쳐주면 끝나는 문제 ..
-	큰 파일을 먼저 합치면 뒤의 과정에서 계속해서 같이 큰 파일을 더해줘야 하기 때문에 최대한 나중에 합쳐주는 게 좋다.

## 백준 11000 – 강의실 배정
-	우선순위 큐, 그리드 알고리즘
-	현재 조건에서 가장 최선의 경우를 할당
-	무조건 꼬리물기 문제로 착각
-	끝나는 시간이 가장 빠른 값이 top에 있기 때문에 그 값이랑만 비교하면 된다
-	그 값이 집어넣으려는 값의 시작 시간보다 크다면 뒤에는 비교할 필요도 없음
-	시작 시간이 빠른 것부터 정렬, 같다면 끝나는 시간이 빠른 것부터
-	맨 처음 시간표는 그냥 집어넣고
-	그 다음부터는 결과 우선순위 큐의 top에 있는 시간이, 집어넣으려는 시작 시간보다 작거나 같으면 그 애(끝나는 시간)를 pop시키고 집어넣는다
-	아니라면(시간이 겹친다면) 그냥 push
-	결과 우선순위 큐의 size가 결과값

## 백준 14719 – 빗물
-	구현, simulation
-	테스트케이스에 대한 답은 나왔는데 왜 틀린 건지는 모르겠음.. 하지만 아무튼 더 간단한 방법이 있었음
-	빗물이 고이는 원리(양쪽이 나보다 더 높을 때)를 생각하면 쉽게 해결이 가능한 문제
-	왼쪽에서 오른쪽으로 움직이면서
-	본인 기준으로 왼쪽에서 제일 큰 값과 오른쪽에서 제일 큰 값을 구한다.
-	Left와 right 중 더 (작은값-본인)을 계산하면 그 위치에서 고일 물의 양을 구할 수 있다.

## 프로그래머스 고득점 Kit – 가장 큰 수
-	사용자 정의 정렬
-	한 줄짜리 코드를 생각 못해서 어렵게 생각함..
-	범위가 매우 크기 때문에 애초에 int형이나, long long으로 계산 자체가 안됨
```c++
	To_string(s) :  int to string
	
	bool cmp(const string &a, const string &b){
    		return (a+b) > (b+a);
}
```
-	이렇게 정의하면 더 큰 수로 정렬할 수 있음

## 프로그래머스 고득점 Kit – 도둑질
-	DP
-	첫번째 집과 마지막 집을 둘 다 터는 경우에 대한 예외처리를 생각하지 못함
-	Dp 배열을 2개, 1차원 배열로 정의
-	하나는 첫번째 집부터 터는 경우
-	하나는 두번째 집부터 터는 경우
-	로 나눠서 비교하면 가능
-	두번째 집부터 터는 경우에 세번째 집에서는 첫번째 집이 0이기 때문에 무조건 XOX인 경우를 생각할 수밖에 없다
-	집이 3개 이상이라는 것에서 힌트를 얻었을 수도 있었던 문제,,,
-	(2번째 집+현재 집), (1번째 전 집)을 비교하여 더 큰 값으로 dp값을 갱신

## 프로그래머스 고득점 Kit – 이중우선순위큐
-	Heap
-	두번이나 틀린 문제,, 정신이 있냐 !!!!
-	원소를 삭제할 때마다 top에 있는 원소가 삭제했던 원소인지 비교해주어야한다
-	Bool visited 배열 선언
-	그런데 중요한 것은, multiset으로도 풀 수 있다는 점
-	Multiset 자료구조를 사용하면 중복원소도 삽입 가능하고 뒤에서 빼내는게 가능하다
-	q.erase(--q.end()) 요렇게,,

## 프로그래머스 고득점 Kit – 전화번호 목록
-	해시
-	문제를 똑바로 안읽어서 틀림
-	접두사니깐 맨 앞에만 비교하면 됨
-	고로 정렬해서 앞뒤 문장만 비교하면 끝…
-	Substr() 이용

## 프로그래머스 고득점 Kit – 여행경로
-	DFS
-	Visited 배열: ticket에 대한 것
-	Ticket 개수 만큼 모두 visited가 true이면 끝나는 것
-	그리고 처음에 ticket 정렬을 하는 것도 중요
-	<DFS알고리즘>
-	1. 일단 answer에 넣는다
-	2. 모든 ticket을 확인했다면 true 리턴
-	3. 해당 티켓에서 다음 티켓으로 visited
-	- 아직 티켓을 다 순회하지 않았는데 순회할 수 있는 것이 없다면(갈수 있는 경로가 없다면)
-	-  answer에서 다시 pop해주고
-	- 돌아와서 visited를 true로 바꾸어준다
-	- // 계속해서 다음 경로로 타고 들어가서 마지막으로 true로 리턴한다면 그 경로가 정답 !!

## 프로그래머스 고득점 Kit – 타겟 넘버
-	DFS
-	재귀함수 잘 모르겠다…
-	DFS(sum+num);
-	DFS(sum-num);
-	각각 계산해주기

## 프로그래머스 고득점 Kit – 단어 변환
-	BFS
-	너비 우선 탐색에 깊이 depth 번호를 부여한다고 생각할 수 있음
-	같은 level에 있더라도 갈 수 있는 경로는 여러 개 일 수 있으니깐!!
-	그렇게 해서 마지막에 레벨을 출력하면 된다

## 백준 1937 - 욕심쟁이 판다
* DP + DFS
* DFS로 쉽게 풀리는 문제지만, 시간 초과
* 메모리제이션 기법을 사용하는 DP를 이용해야한다.
* dp[y][x] : {y,x}에 판다를 풀어놓았을 때 살 수 있는 최대일수
* dfs함수에 들어갔을 때 dp[y][x]가 이미 저장되어있다면, 연산이 끝난 것이니 그대로 return
* 만약에 이전에 가지 않았다면 dp[y][x]를 1로 설정한 뒤에 상하좌우 4방향으로 dfs탐색을 통해 갈 수 있다면 1씩 값을 더해줌

		 dp[y][x] = max(dp[y][x], dfs(next_y, next_x)+1);

## 백준 2206 - 벽 부수고 이동하기
* BFS
* 일반적인 BFS 풀이라면 queue에 {y,x} 좌표만 저장하고
* Visited 또한 [y][x]에 대해 저장한다.
* 하지만, 벽을 1회 부실수 있다는 특수성이 있기 때문에 변수를 다르게 선언하여야 한다.
* queue<pair<pair<int,int>,int>> q : {{y,x},벽을 부순 횟수} : 여기서 마지막 "벽을 부순 횟수"가 0이라면 1번 부술 기회가 남아있는 것
* Visited[y][x][2] : 마지막 인자를 0에 저장하면 벽을 부수지 않고 이동, 1은 벽을 부수고 이동
* 또한 Visited 배열을 단순 'check'의 목적으로 사용하는 것이 아닌, 좌표까지의 최단 경로도 함께 저장한다.

``` c++
q.push({ { 0,0 },0 });
Visited[0][0][0] = 1; // 최단 경로

// 처음 bfs()에 진입했을 때
// 큐에 {0,0} 좌표와 벽을 부수지 않음(0)을 함께 push
```

``` c++
int node_y = q.front().first.first;
int node_x = q.front().first.second;
int block = q.front().second; // 0이라면 1번 부술 기회가 있는 것

if (node_y == n - 1 && node_x == m - 1) return Visited[node_y][node_x][block];
// 마지막 좌표까지 이동하면 Visited(==최단경로)를 return
```

``` c++
if (Map[next_y][next_x] == 0 && !Visited[next_y][next_x][block]) { // 지나갈 수 있는지
	  Visited[next_y][next_x][block] = Visited[node_y][node_x][block] + 1;
	  q.push({ { next_y,next_x },block });
}
```

``` c++
else if (Map[next_y][next_x] == 1 && !Visited[next_y][next_x][block]) { // 막혀있는지
	if (!block) { // block == 0 이라면 -> 아직 부순 적이 없다면
		Visited[next_y][next_x][1] = Visited[node_y][node_x][block] + 1;
        	// Visited[][][1]에 저장
     
		q.push({ { next_y,next_x },1 });
        	// q.push({{ , },1})
	}
}
```

## 백준 9935 - 문자열 폭발

* 문자열
* 처음에는 폭탄의 첫번째 문자를 만났을 때부터 비교를 하려고 했었는데
  * 그럼 예를 들어서
  * str : abcdcdbbabde
  * bomb : cdb
  * 인 경우는 처리하지 못한다
* 바꾸어 생각하여, 마지막 문자를 만났을 때 비교를 하여 폭탄을 제거하면 문제 해결이 가능해진다
* 또한, 폭탄을 만났을 때 원래 문자열에서 erase 해나가는 방법은 시간초과
* 따라서 빈 문자열에 포인터를 이동하며 문자를 더해주고, 폭탄을 만났을 때는 다음 포인터로 문자를 덮는 과정을 해야함
* 정리하자면, 
* 1. 폭탄의 마지막 문자를 만날때까지 문자열에 더한다(포인터 2개 이동)
* 2. 문자열의 마지막이 폭탄일 때 포인터를 앞으로 이동시켜 덮는다.
* 3. 마지막까지 문자열을 비교하면 result(결과 문자열)의 끝에 NULL 문자('\0') 삽입
* 4. result의 포인터인 idx가 0이라면 빈 문자열이므로, "FRULA" 출력



# 맞은 문제

## 백준 2992 – 크면서 작은 수
-	next_permutation()을 이용하여 해결하였으나, 백트래킹으로도 풀이 가능함
-	next_permutation()을 이용하면 숫자가 커지면 시간초과
-	vector에 입력한 수를 한글자씩 담은 후, 하나씩 체크하며 for문을 돈다.
-	n개씩 돌때마다(순열처럼) 숫자를 입력한 수와 비교하여 크면 return

## 백준 15650 – N과 M(2)
-	백트래킹 문제
-	배열의 크기를 꼼꼼히 생각하지 못했음
-	N과 M의 범위가 1<=M<=N<=8이고 백트래킹의 for문에서 for(int i=idx;i<=n;i++)로 검사하고 싶기 때문에 배열의 인덱스를 9로 초기화해주어야함
-	백트래킹을 오름차순으로 검사하고자 한다면 함수에 인자를 두개 넘겨주면 됨 / void go(int idx, int cnt)

## 백준 15624 – 피보나치 7
-	DP
-	재귀로 해결 
-	피보나치 수가 크기 때문에 자료형에 주의. Long long 타입 사용
-	dp배열을 선언하고 if (dp[x] != -1) return dp[x]; 를 통해(memorization 기법 사용) 시간 단축
-	기저 사례에 없다면 return dp[x] = (fib(x - 1)+fib(x - 2)) % 1000000007;

## 백준 2003 – 수들의 합 2
-	투포인터
-	포인터 left, right 선언 / 구하고자 하는 합 m
-	Sum > m : left++
-	Sum < m : right++
-	Sum == m : right++; ans++;
-	Right == n : 종료

## 백준 2559 – 수열
-	투포인터
-	시간초과
-	처음에는 left, right 포인터를 한칸씩 옆으로 이동하며 모든 sum을 다시 구했음
-	그러다보니 시간초과가 나서, 이전의 left 값을 빼고 이후의 right 값을 더해서 sum의 계산범위를 줄여줌

## 백준 1620 – 나는야 포켓몬 마스터 이다솜
-	해시(map)
-	시간초과
-	입출력 해야하는 데이터가 많다면(이 경우에는 입력 데이터가 최대 200000개)
-	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	를 꼭!!! 써줘야함
-	endl보다는 “\n”이 시간 복잡도가 더 좋음

## 백준 1351 – 무한 수열
-	해시(map)
-	런타임 에러(DivisionByZero)
-	자료형을 int로 사용할 경우 입력받는 수가 매우 커지면 의도했던 바와 다르게, 0으로 나누는 경우가 생길 수도 있음
-	이 문제의 경우 0<=N<=10^12 , 2<=P,Q<=10^9 이므로 충분히 고려해볼만 하다.
-	long long 자료형을 필수적으로 사용해야함

## 백준 1302 – 베스트셀러
-	해시(map & sort)
-	Map을 vector로 옮겨 sort하여 해결하는 문제
-	1. Map을 vector<pair< , >> 에 복사한다
-	2. Vector를 비교하는 사용자 정의 함수 bool cmp()를 정의한다.
-	3. Sort(v.begin(),v.end(),cmp)

## 백준 13414 – 수강신청
-	해시(map & sort)
-	런타임 에러(out ofBounds)
-	수강신청을 한 인원이 수강 가능 인원보다 적은 경우를 생각해 주어야함
-	If( i >= v.size()) break;

## 백준 9322 – 철벽 보안 알고리즘
-	해시(map)
-	Sort 함수를 사용자 정의하여 선언하였는데 오히려 불필요한 부분이었던지, 틀렸음
-	Sort 함수를 사용자 정의하지 않고 map에 map<int,string>으로 집어넣어 순서를 key값으로 입력하여 문제를 간단히 해결할 수 있었음
-	Map의 정렬되어 저장되는 성질을 이용

## 백준 1972 – 놀라운 문자열
-	해시(map)
-	for문을 순회할 때마다 문자열의 일정 부분을 저장하기 위해서 s.substr(시작,개수) 함수를 사용
-	mp.count(s) == 0 일 때만 mp[cmp]=1; 로 저장
-	map의 성질을 알고 있었다면 매우 쉽게 풀이할 수 있는 문제

## 백준 1269 – 대칭 차집합
-	해시(map)
-	입력을 받으며 map에 존재하면 erase 해주고, 아니라면 map에 저장하여 마지막에 size를 출력

## 백준 5568 – 카드 놓기
-	백트래킹(set)
-	백트래킹 도중 인자로 cnt를 받아오기 때문에(void go(int cnt)) ans[cnt++]로 cnt를 증감시키면 안됨
-	go(cnt+1)에서 증감시켜 주어야함
-	순열을 돌며 set에 집어넣음
-	Set은 중복불가능인 성질

## 백준 17479 – 정식당
-	해시(map)
-	순서대로 요구사항을 해결하면 되는데, 3번째 요구사항(서비스 메뉴는 단 하나만 주문할 수 있다) 해결을 위해서는 조건문에서 if(flag == true && sv == 1) 을 사용하면 sv>=1인 경우에 모두 true 처리를 하기때문에 요구사항에 부합함
-	if (flag == true && sv >= 1) {
		if (sv == 1 && …
으로 중첩해서 검사해주어야 함
-	입력 범위가 크므로(가격) long long 자료형을 써야함

## 백준 1654 – 랜선 자르기
-	이분탐색
-	기본 문제
-	입력 범위가 크기 때문에 (10,000 * 1,000,000) 자료형에 주의!
-	Left, right, mid 정의가 배열의 인덱스인 줄 알고 있었음. 그게 아니라 문제마다 정의가 달라짐
-	여기서는 랜선의 길이(일정하게 자를)

## 백준 2805 – 나무 자르기
-	이분탐색
-	Left, right, mid: 절단기에 설정할 높이

## 백준 2343 – 기타 레슨
-	이분탐색
-	블루레이 크기 중 최소 출력
-	최소를 출력해야하므로 큰 범위에서 줄여나가는 방향으로 조건문을 짜는 것이 좋다.
-	하나의 영상이 블루레이 크기보다 큰 경우 예외처리

## 백준 10816 – 숫자 카드 2
-	Upper_bound, lower_bound
-	숫자 카드 중 입력된 수를 가지고 있는 개수
-	Multiset에 입력받아서 s.count(x)로 계산하면 시간초과
-	Upper-lower를 출력하여 매우 간단하게 풀 수 있는 문제

## 백준 9012 – 괄호
-	스택
-	열린 괄호가 나온다? 스택에 저장
-	닫힌 괄호가 나온다? 스택에 열린 괄호가 있다면 스택 pop, 없다면 올바르지 않은 괄호 문자열

## 백준 1874 – 스택 수열
-	스택
-	X: 입력한 수 / last: 마지막으로 스택에 집어넣은 수+1
-	X>=last : x까지 스택에 집어넣고 pop하기
-	X<last : x==top이라면 pop, 아니라면 스택 수열이 불가능한 경우

## 백준 1406 – 에디터
-	스택
-	스택 2개로 활용
-	커서를 옮기는 명령이 들어오면 반대쪽 스택으로 넘긴다.

## 백준 4949 – 균형잡힌 세상
-	스택
-	괄호 문자열 (), [] 를 구분하여야 하므로 스택을 2개 이용한 것이 아닌, 하나의 스택을 사용하여 구현하여야함
-	공백이 포함된 문자열 입력: getline(cin,s)

## 백준 15651 – N과 M (3)
-	백트래킹
-	중복을 포함한 수열을 구하기 위해서는 백트래킹에서 check 배열을 쓰지 않아도 된다.

## 백준 1966 – 프린터 큐
-	큐(queue)
-	우선순위 큐(priority_queue)로도 해결할 수 있는 문제
-	중요도를 입력받으며 queue에 집어넣고, 동시에 중요도를 vector에도 저장한다.
-	( * ) Vector를 내림차순 sort해주고 맨 앞 인덱스부터 queue의 front와 비교한다.
-	vector에서 가장 큰수를 찾아 변수에 저장하고 그 변수보다 importance가 작으면 맨뒤로 보낸다.
-	그 큰 수 차례가 오면 pop해주고 cnt++, vector의 인덱스도 늘려준다.
-	: 같은 수가 여러 번 중복 입력되더라도, vector에도 똑같이 입력을 해줄 것이고, 각자는 개인의 인덱스를 가지기 때문에 식별이 가능하다.
-	우선순위 큐를 사용하면 ( * ) 의 과정이 생략된다.

## 백준 15652 – N과 M (4)
-	백트래킹
-	오름차순으로 순열을 정리하려면 백트래킹 함수 go에 idx, cnt 2개의 인자를 넘기면 된다.

## 백준 1213 – 팰린드롬 만들기
-	문자열
-	팰린드롬: 거꾸로 해도 같은 문자열
-	        : 모든 문자가 짝수개 or 하나만 홀수개, 나머지는 짝수개
-	<알파벳, 개수>로 map에 저장
-	Map을 순회하며 팰린드롬을 만들 수 있는지 없는지 확인
-	홀수개인 것이 한 개보다 많으면 팰린드롬을 만들 수 없음
-	확인함과 동시에 해당 문자의 개수/2만큼 문자열에 붙어 저장한다 (사전 순으로 먼저 나오는 문자열을 출력하기 때문에 가능한 알고리즘)
-	순회 후에는, 문자열을 tmp에 임시 저장하여 reverse해주고
-	홀수개인 문자를 (없다면 스킵) 결과문자열에 붙인 후 reverse한 문자열도 붙여준 후 출력 !

## 백준 3986 – 좋은 단어
-	스택
-	문자열을 앞에서부터 비교하면 스택의 top과 같은 것이면 스택에서 pop해준다.
-	마지막까지 비교한 후, 스택이 비어 있다면 좋은 단어

## 백준 1935 – 후위 표기식 2
-	스택
-	연산자가 나올 때까지 스택에 피연산자를 집어넣고
-	연산자가 나오면 스택에서 2개를 pop해서 연산한 후 다시 스택에 집어넣는다
-	마지막에 스택의 top이 최종 결과
```c++
	소수점 고정 : cout<<fixed;
	             cout.precision(고정자리수)
```

## 백준 2841 – 외계인의 기타 연주
-	스택
-	스택도 배열?로 할당 가능 	ex> stack<int> st[7]

## 백준 5430 – AC
-	Deque
-	R(거꾸로): flag를 세워 다음 연산에서 뒤에서부터 읽게 한다.
-	D(바르게): 또한 flag를 세워 다음 연산에서 앞에서부터 읽게 한다.
-	테스트케이스 수를 입력받고 전역함수로 구현하였기 때문에, 변수 초기화에 유의해야했음

## 백준 1021 – 회전하는 큐
-	Deque
-	처음에 문제 이해를 잘못했음
-	왼쪽으로 회전하거나, 오른쪽으로 회전하거나, 둘 중 하나 경우의 min을 구하는 문제인 것으로 이해
-	어디가 가까운지 파악 후 회전하면 되는 간단한 문제

## 백준 1927 – 최소 힙
-	Priority queue
-	오름차순 정렬을 사용하려면 priority_queue<int, vector<int>, greater<int>> q;
-	greater<int> 탬플릿은 <functional> 헤더에 속해있음
-	기본 설정인 내림차순 정렬을 그대로 사용해서 최소 힙을 만드려면 push할 때 –(마이너스)를 붙인 상태로 삽입하여 출력할 때 다시 –(마이너스)를 붙여주면 된다.

## 백준 11286 – 절댓값 힙
-	Priority queue
-	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
-	절댓값을 함께 입력하기 위해 pair 자료형 사용

## 백준 2345 – 풍선 터뜨리기
-	Deque
-	왼쪽 또는 오른쪽으로 이동하는 문제는 deque 자료구조를 사용하면 된다.

## 백준 1012 – 유기농 배추
-	BFS
-	X와 y의 입력범위를 반대로 생각해서 입출력에 문제가 생김
-	상하좌우로 움직이는 BFS를 생각해내지 못함
-	BFS 함수를 탐색할 때
-	첫번째 노드의 x,y 좌표를 집어넣은 후
-	상하좌우에 탐색하지 않은(check==false && arr=1) 노드가 있으면 큐에 집어넣고 다음 단계를 반복한다.

## 2017 카카오코드 예선 – 카카오프렌즈 컬러링북
-	BFS
-	플러드 필 기본 문제
-	프로그래머스에선 초기화를 잘하자 ,,

## 백준 4963 – 섬의 개수
-	BFS
-	플러드 필
-	meset함수 쓰려면 #include <cstring> 잊지않기 ,,
-	초기화 꼭하기

## 백준 16236 – 아기상어
-	BFS / 시뮬레이션
-	아기 상어의 현재 위치에서 bfs를 통해 큐에는 이동할 수 있는 경로를 집어넣고, 벡터에는 잡아먹을 물고기의 위치를 집어넣는다.
-	이때, 벡터를 튜플로 선언하여, 거리, x좌표, y좌표를 저장해야 나중에 우선순위 sort에 편리하다.
-	먹을 수 있는 물고기가 1마리 이상이면, 정렬 후 벡터의 맨앞에 있는 물고기로 향하는 거리를 시간에 더해주고
-	위치 조정후, 사용했던 dist, check 배열을 초기화해준다.
-	잡아먹을 물고기가 없을 때까지 반복
-	시뮬레이션 문제를 해결할 때는 복잡한 문제까지 풀기 위해서 누구라도 코드를 알아볼 수 있게 잘 정리해야 한다.

## 백준 2075 - N번째 큰 수
-	우선순위 큐
-	메모리 초과
-	큐 안에는 n개의 원소만 있게 메모리 공간을 유지해야한다.
-	Min heap을 선언하고
-	만약 지금 집어넣을 x가 top보다 크면(가장 작은 원소보다 크면) top을 버리고 x를 push
-	Size가 n보다 작으면 신경쓰지 않고 그냥 push
-	원소를 모두 입력받은 후 min heap의 top이 구하고자하는 N번째 큰 수

## 프로그래머스 고득점 Kit – 모의고사
-	완전탐색
-	#include <algorithm>
-	Int max = *max_element(a.begin(),a.end());


## 프로그래머스 고득점 Kit – 소수찾기
-	완전탐색, 백트래킹
-	소수 검사에서 1인 경우에는 제외시켜 주어야함

## 프로그래머스 고득점 Kit - K번째 수
-	정렬
-	Vector sort의 인덱스를 start와 end값으로 설정해서 간단하게 해결가능
-	Sort(v.begin()+start-1, v.begin()+end);

## 프로그래머스 고득점 Kit – H-Index
-	이분 탐색
-	벡터 속에서 ‘최댓값’을 찾으라는 문제 지문을 보고, 이분 탐색으로 해결해야겠다고 힌트를 얻음

## 프로그래머스 고득점 Kit – 더 맵게
-	Heap, priority_queue
-	Prirority_queue<int,vector<int>,greater<int>> pq(v.begin(),v.end());
-	내림차순 정렬은 less<int>
-	Pq.top(); pq.push(); pq.pop();

## 프로그래머스 고득점 Kit – 입국 심사
-	이분탐색
-	Int * int 연산을 할 때, 결과값이 int보다 큰 경우, int의 범위 밖의 bit가 손실
-	둘 중 하나는 long long 으로 선언
-	(long long)으로 typecasting 가능

## 프로그래머스 고득점 Kit – 징검 다리
-	이분탐색
-	처음에 백트래킹으로 하려고 했으나, 시간초과 가능성
-	Mid: 바위간 거리의 최소값 중 최대값
-	바위간 거리가 mid보다 작으면, 바위제거(cnt++)
-	바위간 거리가 mid보다 같거나 크다면, 제거하지 않는다, 즉, idx를 i로 변경해주어야 다음 인덱스에서 그 인덱스와의 거리로 비교
-	Idx 변수를 통해 제거할 바위간 거리를 비교한다.
-	최소값 중 최대값, 즉, 최대값을 구하므로 left=mid+1로 계속 증가시키기

## 프로그래머스 고득점 Kit – 위장
-	해시(map)
-	Set을 써서 비교하려고 했는데 굳이 그러지 않아도 iterator로 바로 연산 가능
-	Answer*=x.second+1;

## 프로그래머스 고득점 Kit – 베스트앨범
-	해시
-	자료구조를 어떻게 쓰느냐가 돋보였던 문제
-	Map, priority queue를 적절히 섞어서 활용하였다.
-	Map(Genres): 장르별 재생 횟수를 더하고 정렬해야했기 때문에 map 자료구조 사용
-	Map(Idx): 장르별 인덱스를 설정하고, priority queue에서 사용하기 위해 정의
-	Prirority queue(pq): 장르별 인덱스로 큐를 배열처럼 메모리 할당하고, for문을 돌 때 해당 큐를 찾아서 <재생횟수, 인덱스> 쌍으로 저장하게 했다. 정렬할 때 재생횟수가 같다면 인덱스는 오름차순으로 정렬하는 사용자 정의 함수를 만드려고 했는데 방법을 못찾았다. 그래서 집어넣을 때 마이너스를 붙여서 넣은 후에 결과 출력 때는 마이너스를 다시 붙여 복구하는 형태로 정렬을 대신하였다.

## 프로그래머스 고득점 Kit – 디스크컨트롤러
-	Heap?? Shortest Job First,,
-	풀긴 했는데, 그다지 좋은 풀이는 아니었음 / multimap 이용
-	주어진 자료구조를 그대로 이용하고도 짧은 풀이 가능
-	이 경우에 항상 짧은 애를 먼저 선택하는 것이 짧다.
-	Type 1을 고려할 필요가 없었음
-	소요시간으로 우선 정렬하면
-	지금 현재 가능한 시간 내에서 가장 짧은 애를 먼저 전개할 수 있다.
-	전개 후에는 원소 제거하기 ( jobs.erase(jobs.begin()+i))
	
## 백준 5582 - 공통 부분 문자열

* 연속 공통 부분 문자열
* LCS 알고리즘과 유사하지만 LCS 알고리즘은 "비연속적" 최장 공통 부분 문자열이다
* 하지만, 이 문제는 연속된 공통 부분 문자열을 찾아야 하므로
* 같은지의 조건만 확인하고, 대각선+1하며 max_num을 갱신

 ```c++
    if(A[i-1] == B[j-1]) {
        dp[i][j] = dp[i-1][j-1]+1;
        max_num = max(max_num, d[i][j]);
    }
```

## 백준 1504 - 특정한 최단 경로
* 다익스트라
* 임의로 주어진 두 정점 반드시 통과
* 2가지 경우로 나누어서 생각
    * 1 → V1 → V2 → N
    * 1 → V2 → V1 → N
* V1 != N, V2 != 1
    * V1==1, V2==N은 가능하다 → 예외 처리
* 다익스트라 함수가 0을 return하면, 자기자신 dijkstra(a, a)랑 구분 X → return -1 

## 백준 2665 - 미로 만들기
* 다익스트라/BFS
* 흰 방으로 바꾸어야 할 최소의 검은방 수
* 상하좌우로 움직이면서,
    * 흰 칸으로 이동하는 경우 : 그 칸을 지나가는 것이 더 비용이 적게 들면 이전의 블록 수로 변경 후 큐에 push ( if(Change[ny][nx] > changed_block) )
    * 검은 칸으로 이동하는 경우 : 흰 칸과 유사하게, 그 칸을 지나가는 것이 더 비용이 적게 들면 이전의 블록 수 +1 && 큐에 push ( if(Change[ny][nx] > changed_block + 1) )
* 마지막 칸에 대한 블록 수를 출력 ( Change[n-1][n-1] )

## 백준 14938 - 서강 그라운드
* 다익스트라
* 첫번째 노드부터 마지막 노드까지를 시작점으로 돌면서 다익스트라 순회
   * 그 노드에서 갈 수 있는 노드에 있는 아이템 갯수를 더해주고 return
