#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(),times.end(),greater<int>());
    
    long long left=0, right=(long long)times[0]*n;
    
    while(left<=right){
        long long mid=(left+right)/2;
        
        long long cnt=0;
        for(long long i=0;i<times.size();i++){
            cnt+=(mid/times[i]);
        }
        
        if(cnt>=n){
            answer=mid;
            right=mid-1;
        }
        else{
            left=mid+1;
        }
        
    }
    
    return answer;
}