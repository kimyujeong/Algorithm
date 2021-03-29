#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    
    rocks.push_back(0); rocks.push_back(distance);
    sort(rocks.begin(),rocks.end());
    
    int left=0, right=distance;
    
    while(left<=right){
        int mid=(left+right)/2;
        
        int idx=0, cnt=0;
        for(int i=1;i<rocks.size();i++){
            if(rocks[i]-rocks[idx]<mid) cnt++;
            else idx=i;
        }
        
        if(cnt>n){
            right=mid-1;
        }
        else{
            left=mid+1;
            answer=mid;
        }
    }
    
    return answer;
}