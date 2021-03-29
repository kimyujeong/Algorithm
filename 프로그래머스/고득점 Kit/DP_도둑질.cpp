#include <string>
#include <vector>

#include <cstring>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    
    int dp1[1000000]; // 첫번째 집부터 턴다
    int dp2[1000000]; // 두번재 집부터 턴다
    memset(dp1,0,sizeof(dp1));
    memset(dp2,0,sizeof(dp2));
    
    dp1[0]=money[0];
    dp1[1]=money[0];
    
    dp2[0]=0;
    dp2[1]=money[1];
    
    for(int i=2;i<money.size()-1;i++){
        dp1[i]=max(dp1[i-2]+money[i],dp1[i-1]);
        dp2[i]=max(dp2[i-2]+money[i],dp2[i-1]);
    }
    
    // dp1은 첫번째 집을 털었으므로, 마지막 집 터는 것이 불가능
    dp2[money.size()-1]=max(dp2[money.size()-3]+money[money.size()-1],dp2[money.size()-2]);
    
    answer=max(dp1[money.size()-2],dp2[money.size()-1]);
    
    return answer;
}