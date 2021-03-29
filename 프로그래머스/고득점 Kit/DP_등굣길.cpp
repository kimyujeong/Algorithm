#include <string>
#include <vector>
#include <cstring>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    int dp[101][101];
    memset(dp,0,sizeof(dp));
    
    for(int i=0;i<puddles.size();i++){ // 침수지역은 -1로 체크
        // 0: x좌표, 1: y좌표
        dp[puddles[i][1]-1][puddles[i][0]-1]=-1;
    }
    
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            
            if(dp[i][j]==-1) continue;
            
            if(i==0) { 
                if(dp[i][j-1]==-1) dp[i][j]=-1;
                else dp[i][j]=1; 
                continue; 
            }
            if(j==0) { 
                if(dp[i-1][j]==-1) dp[i][j]=-1;
                else dp[i][j]=1;
                continue;
            }
            //위에서 내려오거나, 왼쪽에서 오거나        
                        
            if(dp[i-1][j]!=-1) dp[i][j]+=dp[i-1][j];
            if(dp[i][j-1]!=-1) dp[i][j]+=dp[i][j-1];
            
            if(dp[i][j]==0) dp[i][j]=-1;
            
            dp[i][j]=dp[i][j]%1000000007;
        } 
    }
    
    answer=dp[n-1][m-1];
    if(answer==-1) answer=0;
    
    return answer;
}