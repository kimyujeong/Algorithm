#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    priority_queue<int> priority;
    queue<pair<int,int>> waiting_list;
    
    for(int i=0;i<priorities.size();i++){
        priority.push(priorities[i]);
        waiting_list.push({priorities[i],i});
    }
        
    while(!waiting_list.empty()){
        
        int waiting_priority=waiting_list.front().first;
        int waiting_idx=waiting_list.front().second;
        waiting_list.pop();
        
        if(waiting_priority==priority.top()){
            answer++;
            priority.pop();
            if(waiting_idx==location){
                return answer;
            }
        }
        
        else waiting_list.push({waiting_priority, waiting_idx});
        
    }
    
    
    return answer;
}