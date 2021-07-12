#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 987654321

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    int max_num=0;
    
    vector<int> Graph[20001];
    int dist[20001];
    for(int i=1;i<=n;i++) dist[i]=MAX;
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    
    for(int i=0;i<edge.size();i++){
        Graph[edge[i][0]].push_back(edge[i][1]);
        Graph[edge[i][1]].push_back(edge[i][0]);
    }
    
    dist[1]=0;
    pq.push({0,1});
    
    while(!pq.empty()){
        int cost=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        
        for(int i=0;i<Graph[node].size();i++){
            int next=Graph[node][i];
            if(dist[next]>cost+1){
                dist[next]=cost+1;
                pq.push({dist[next],next});
                max_num=max(max_num,dist[next]);
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        if(dist[i]==max_num) answer++;
    }
    
    return answer;
}