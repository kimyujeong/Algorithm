#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
      
    priority_queue<int,vector<int>,greater<int>> pq;
    
    for(auto x:scoville){
        pq.push(x);
    }
    
    while(1){
        if(pq.top()>=K) break;
        if(pq.size()==1 && pq.top()<K) return -1;
        
        int First=pq.top();
        pq.pop();
        
        int Second=pq.top();
        pq.pop();
        
        pq.push(First+(Second*2));
        
        answer++;
    }
    
    return answer;
}