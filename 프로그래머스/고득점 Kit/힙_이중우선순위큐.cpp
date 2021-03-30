#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq1; // 오름차순
    priority_queue<pair<int,int>> pq2; // 내림차순
    
    bool visited[1000000]={false,};
    
    for(int i=0;i<operations.size();i++){
        if(operations[i][0]=='I'){ // 삽입
            
            string tmp="";
            for(int j=2;j<operations[i].size();j++) tmp+=operations[i][j];
            
            pq1.push({stoi(tmp),i});
            pq2.push({stoi(tmp),i});
        }
        if(operations[i][0]=='D'){ // 삭제
            
            if(operations[i][2]=='1'){ // 최댓값 삭제
                
                while(!pq2.empty() && visited[pq2.top().second])
                    pq2.pop();
                
                if(pq2.empty()) continue;
                
                visited[pq2.top().second]=true;
                pq2.pop();
            }
            else if(operations[i][2]=='-'){ // 최솟값 삭제
                
                while(!pq1.empty() && visited[pq1.top().second])
                    pq1.pop();
                
                if(pq1.empty()) continue;
                
                visited[pq1.top().second]=true;
                pq1.pop();
            }
        }
    }
    
    while(!pq1.empty() && visited[pq1.top().second])
        pq1.pop();
    while(!pq2.empty() && visited[pq2.top().second])
        pq2.pop();
    
    if(pq1.empty() || pq2.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(pq2.top().first);
        answer.push_back(pq1.top().first);
    }
    
    
    return answer;
}