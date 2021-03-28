#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(),citations.end());
    
    int left=0, right=citations.size();
    
    while(left<=right){
        int mid=(left+right)/2;
        
        int cnt=0;
        for(int i=0;i<citations.size();i++){
            if(citations[i]>=mid) cnt++;
        }
        
        if(cnt>=mid){
            answer=mid;
            left=mid+1;            
        }
        else{
            right=mid-1;
        }
    }
    
    return answer;
}