#include <string>
#include <vector>

using namespace std;

int answer=0;

void dfs(vector<int> numbers, int target, int sum, int cnt){
    if(cnt==numbers.size()){
        if(sum==target) answer++;
        return;
    }
    dfs(numbers,target,sum-numbers[cnt],cnt+1);
    dfs(numbers,target,sum+numbers[cnt],cnt+1);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers,target,0,0);
    return answer;
}

// 처음에 백트래킹을 쓰려고 했는데
// 그럼 cnt 계산하는 조건이 안맞음
// 단계마다 sum에 각각 더하고 빼서 한칸씩 재귀