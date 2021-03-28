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
    
    while(!pq.empty()){
        
        if(pq.top()>=K) break;
        
        int First=pq.top();
        pq.pop();
        if(pq.empty()){
            if(First<K) answer=-1;
            break;
        }
        int Second=pq.top();
        pq.pop();
        
        pq.push(First + Second*2);
        answer++;
    }     
    
    return answer;
}